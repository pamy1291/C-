#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <pthread.h>
#include <queue>
using namespace std;

//	消费者线程真正的业务逻辑函数 由调用者提供
typedef void (*con_WorkFP)(void*);
//	生产者线程真正的业务逻辑函数 由调用者提供
typedef void* (*pro_WorkFP)(void);

template<typename T>
class ThreadPool
{
	int con_thread_cnt;		//	消费者线程数量
	pthread_t* con_tids;	//	消费者线程id
	int pro_thread_cnt;		//	生产者线程数量
	pthread_t* pro_tids;	//	生产者线程id
	queue<T> store;		//	队列仓库
	int store_cal;	//仓库容量
	con_WorkFP con_work;	//	消费者业务逻辑函数
	pro_WorkFP pro_work;	//	生产者业务逻辑函数
	pthread_mutex_t hlock;	//	队头锁
	pthread_mutex_t tlock;	//	队尾锁
	pthread_cond_t empty;	//	空仓条件变量
	pthread_cond_t full;	//  满仓条件变量
public:
	ThreadPool(con_WorkFP con_fp, pro_WorkFP pro_fp, int con_cnt=1, int pro_cnt=30, int store_cal=20) : con_work(con_fp), pro_work(pro_fp), \
				con_thread_cnt(con_cnt), pro_thread_cnt(pro_cnt), store_cal(store_cal) {
		con_tids = new pthread_t[con_thread_cnt];
		pro_tids = new pthread_t[pro_thread_cnt];
		
		//	初始化互斥量、条件变量
		pthread_mutex_init(&hlock,NULL);
		pthread_mutex_init(&tlock,NULL);
		pthread_cond_init(&empty,NULL);
		pthread_cond_init(&full,NULL);
	}
	~ThreadPool() {
		//	杀死生产者、消费者线程
		for(int i=0; i<pro_thread_cnt; i++)
		{
			pthread_cancel(pro_tids[i]);	
			pthread_join(pro_tids[i],NULL);
		}
		for(int i=0; i<con_thread_cnt; i++)
		{
			pthread_cancel(con_tids[i]);	
			pthread_join(con_tids[i],NULL);
		}

		delete pro_tids;
		delete con_tids;

		pthread_mutex_destroy(&hlock);
		pthread_mutex_destroy(&tlock);
		pthread_cond_destroy(&empty);
		pthread_cond_destroy(&full);
	}
	//	生产者线程入口函数 不能是普通成员函数，成员函数中隐藏this指针，而原线程入口函数要求不能与该参数，所以加上static修饰(无this指针)
	static void* pro_run(void* arg) {
		ThreadPool<T>* thread = (ThreadPool<T>*) arg;
		for(;;)
		{
			//	调用生产者业务逻辑函数(用户提供) 生产出数据
			T data = (T)thread->pro_work();
			thread->push_threadpool(data);
		}
	}
	static void* con_run(void* arg) {
		ThreadPool<T>* thread = (ThreadPool<T>*) arg;
		for(;;)
		{
			//	消费者从仓库中获取数据
			T data = thread->pop_threadpool();
			if(NULL == data) continue;
			//	获取数据后，执行真正的业务逻辑函数(用户提供)
			thread->con_work(data);
		}
	}
	//	生产数据
	void push_threadpool(T data) {
		//	队尾上锁,防止其他生产者生产数据
		pthread_mutex_lock(&tlock);

		//	如果一直队满，睡眠
		while(store.size() >= store_cal)
		{
			//	唤醒消费者线程
			pthread_cond_signal(&empty);
			//	睡入满仓条件变量,此时会自动解锁队尾
			pthread_cond_wait(&full, &tlock);
		}

		//	数据存入仓库
		store.push(data);
		//	唤醒消费者线程
		pthread_cond_signal(&empty);
		//	解锁队尾
		pthread_mutex_unlock(&tlock);
	}
		//	消费数据
	T pop_threadpool() {
		//	队头上锁,防止其他消费者使用数据
		pthread_mutex_lock(&hlock);

		//	如果一直队空，睡眠
		while(store.empty())
		{
			//	唤醒生产者线程
			pthread_cond_signal(&full);
			//	睡入空仓条件变量,此时会自动解锁队头
			pthread_cond_wait(&empty, &hlock);
		}

		//	从仓库获取数据
		T data = store.front();
		store.pop();
		//	唤醒生产者线程
		pthread_cond_signal(&full);
		//	解锁队头
		pthread_mutex_unlock(&hlock);
		return data;
	}
	//	启动线程池(创建线程)
	void start_threadpool() {
		//	启动生产者线程
		for(int i=0; i<pro_thread_cnt; i++)
		{
			//创建生产线程并提供入口函数
			pthread_create(pro_tids+i, NULL, pro_run, this);
		}
		//	启动消费者线程
		for(int i=0; i<con_thread_cnt; i++)
		{
			//创建消费线程并提供入口函数
			pthread_create(con_tids+i, NULL, con_run, this);	
		}
	}
};

#endif//THREADPOOL_H







