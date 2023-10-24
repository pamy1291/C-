#include <iostream>
#include <cstring>
#include "hotel.h"
#include <cstdlib>
using namespace std;

Hotel Hotel::hotel;

int Hotel::init(void) {
	FILE* f = fopen("./files/msg.txt", "r");
	if(NULL == f) {
		cout << "酒店信息文件不存在！" << endl;
		return -1;
	}

	fscanf(f, "%d\n",&layer_cal);//读取层数
	rooms_layer = new Room_list[layer_cal];//存入每层层号和对应的房间
	layer_room_cal = new int[layer_cal];//每层房间数
	for(int i=0; i<layer_cal; i++) {//存入每层层号
		if(i != layer_cal-1) {
			fscanf(f, "%d ",&rooms_layer[i].local_layer);
		}
		else { 
			fscanf(f, "%d\n",&rooms_layer[i].local_layer);
		}
	}
	for(int i=0; i<layer_cal; i++) {//存入每层房间数
		if(i != layer_cal-1) {
			fscanf(f, "%d ",layer_room_cal+i);
		}
		else {
			fscanf(f, "%d\n",layer_room_cal+i);
		}
	}
	//依次存入每层对应房间对象
	for(int i=0; i<layer_cal; i++) {
		for(int j=0;j<layer_room_cal[i]; j++) {
			int room_num = 0,room_type = 0, room_price = 0;
			if(j != layer_room_cal[i]-1) {
				fscanf(f, "%d-%d-%d ",&room_num, &room_type, &room_price);
			}
			else {
				fscanf(f, "%d-%d-%d\n",&room_num, &room_type, &room_price);
			}
			Room r(room_num, room_type, room_price);//新建临时房间对象
			rooms_layer[i].room.push_back(r);//将房间对象存入对应层的房间对象链表中
		}
	}
	
	fclose(f);	
	return 0;
}
//入住
bool Hotel::check_in(void) {
	Room& r = query_room_num();//根据门牌号获取对应需要入住的房间
	if(0 == r.type) {
		delete &r;
		return false;
	}

	string name;
	char sex;
	string id_card;
	cout << "请输入您的姓名：";
	cin >> name;
	cout << "请输入您的性别：";
	cin >> sex;
	cout << "请输入您的身份证号码：";
	cin >> id_card;
	Guest g(name, sex, id_card);//创建临时房客对象
	
	return r.check_in(g);//调用房间类的入住
}
//退房
void Hotel::check_out(void) {
	string id_card;
	cout << "请输入您的身份证号码：";
	cin >> id_card;
	Guest g("", '\0', id_card);
	Room& r = query_room_num();//根据门牌号获取对应需要退房的房间
	if(0 == r.type) {
		delete &r;
	}else {
		r.check_out(g);
	}
}
//显示空房，返回空房数量
int Hotel::show_empty_room(void)const {
	int cnt = 0; 
	//for(int i=0 ;i<layer_cal; i++) {
	int i = 0;//第一层
	while(1) {
		//遍历链表中的房间对象 分层分页显示
    	auto it = rooms_layer[i].room.begin();
    	int cmd;
    	while(1) {
    		system("clear");
			if((*it).get_cur_cnt() == 0) {
				cout << *it << endl;
				cout << "第" << rooms_layer[i].local_layer << "层" << endl;
				cout << "第" << cnt << "页" << endl;
				cout << "<. 上一页 >.下一页 n. 下一层 t. 上一层" << endl;
				cout << "q. 退出" << endl;
			}
			cmd = getch();
    		stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
    		if(cmd == 'n' && i < layer_cal-1) {
    			i++;
    			break;
    		}
    		if(cmd == 't' && i > 0) {
    			i--;
    			break;
    		}
    		if(cmd == 'q') return i;
    		if(cmd == LEFT && it != rooms_layer[i].room.begin()) {
    			it--;
    			cnt--;
    		}
    		else if(cmd == RIGHT && it++ != rooms_layer[i].room.end()) {
    			//it++;
    			cnt++;
    		}
    		if(it == rooms_layer[i].room.end()) {
    			it--;
    			cnt--;
    		}
    		else continue;
    	}
	}
	return cnt;
}
//根据价格查询房间
int Hotel::query_room_price(void)const {
	int cnt = 0;//符合要求的个数
	int min_price,max_price;//价格范围
	cout << "请输入你要查询的房间价格最小值：";
	cin >> min_price;
	cout << "请输入你要查询的房间价格最大值：";
	cin >> max_price;
	for(int i=0 ;i<layer_cal; i++) {
		for(auto it = rooms_layer[i].room.begin(); it != rooms_layer[i].room.end(); it++) {
			if((*it).price >= min_price && (*it).price <= max_price) {
				cout << *it << endl;
				cnt++;
			}
		}
	}
	anykey_continue();
	return cnt;
}
//根据房间号码查询并返回那房间引用,入住时使用
Room& Hotel::query_room_num(void)const {
	int num = 0;//待查询的房号
	cout << "请输入房间门牌号：";
	cin >> num;
	Room* r = new Room(0, 0, 0);
	for(int i=0 ;i<layer_cal; i++) {
		for(auto it = rooms_layer[i].room.begin(); it != rooms_layer[i].room.end(); it++) {
			if((*it).num == num) {
				cout << *it << endl;
				anykey_continue();
				return *it;
			}
		}
	}
	cout << "无效门牌号！" << endl;
	anykey_continue();
	return *r;//没有此房间
}
//升级
bool Hotel::upgrade(void) {
	init();
	return true;
}





