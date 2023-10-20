#include "manager_view_impl.h"
#include "tools.h"
#include "emis.h"
#include "department.h"
#include <getch.h>
#include <cstring>
#include <cstdlib>
#include <stdint.h>

//构造函数
ManagerViewImpl::ManagerViewImpl(void) {
	mgrCtrl = new ManagerCtrlImpl;
	srcView = new ServiceViewImpl;
}
//析构函数
ManagerViewImpl::~ManagerViewImpl(void) {
	delete mgrCtrl;
	delete srcView;
}
//选项菜单
void ManagerViewImpl::menuAll(void) {
	while(1) {
		system("clear");
		cout << "     登录" << endl;
		cout << "1. 超级管理员" << endl;
		cout << "2. 业务管理员" << endl;
		cout << "3. 退出" << endl;
		switch(get_cmd('1', '3')) {
			case '1': loginManager(); break;
			case '2': loginService(); break;
			case '3': return;
		}
	}
}
//超级管理员登录
void ManagerViewImpl::loginManager(void) {
	char user[10];
	char pwd[6];
	uint8_t cnt = 3;//重复输入的次数
	do {
		cout << "请输入帐号：";
		get_string(user, 9, 0, 0);
		cout << "请输入密码：";
		get_string(pwd, 5, PWD_TYPE, 0);
		if(0 == strcmp(user,su_user) && 0 == strcmp(pwd,su_pwd)) {
			//进入管理菜单
			menuMgr();
			return;
		}
		cout << "帐号或密码有误，请重新输入!" << endl;
	}while(--cnt);
}
//业务管理员登录
void ManagerViewImpl::loginService(void) {
	int id;
	char pwd[20];
	uint8_t cnt = 3;//重复输入的次数
	//获取管理员链表
	list<Manager>& listMgr = mgrCtrl->listMgr();
	while(cnt--) {
		cout << "请输入帐号：";
		cin >> id;
		cout << "请输入密码：";
		get_string(pwd, 19, PWD_TYPE, 0);
		//遍历每个管理员判断id与密码是否对应
		for(auto it = listMgr.begin(); it != listMgr.end(); it++) {
			if( id == it->getid() && 0 == strcmp(pwd, it->getPwd()) ) {
				//进入业务菜单
				srcView->menuSrc();
				return;
			}
		}
		cout << "帐号或密码有误，请重新输入!" << endl;
	}
}
//超级管理员用户菜单
void ManagerViewImpl::menuMgr(void) {
	while(1) {
		system("clear");
		cout << "   超级管理" << endl;
		cout << "1. 增加管理员" << endl;
		cout << "2. 删除管理员" << endl;
		cout << "3. 显示所有管理员" << endl;
		cout << "4. 退出" << endl;
		switch(get_cmd('1', '4')) {
			case '1': addMgr(); break;
			case '2': delMgr(); break;
			case '3': listMgr(); break;
			case '4': return;
		}
	}
}
//增加管理员
void ManagerViewImpl::addMgr(void) {
	char name[40], pwd[20];
	cout << "请输入管理员姓名：";
	get_str(name, 20);
	cout << "请输入管理员密码：";
	get_string(pwd, 19 , PWD_TYPE, 0);
	//创建管理员临时变量
	Manager mgr(name, pwd);
	if(mgrCtrl->addMgr(mgr)) {
		cout << "添加成功：" << name << endl;
	}else {
		cout << "添加失败，管理员名额已满！" << endl;
	}
	anykey_continue();
}
//删除管理员
void ManagerViewImpl::delMgr(void) {
	int id;
	cout << "请输入需要删除的管理员id：";
	cin >> id;
	if(mgrCtrl->delMgr(id)) {
		cout << "删除成功！" << endl;
	}else {
		cout << "删除失败，管理员不存在！" << endl;
	}
	anykey_continue();
}
//显示所有管理员
void ManagerViewImpl::listMgr(void) {
	//获取管理员链表进行输出显示
	list<Manager> mgrList = mgrCtrl->listMgr();
	show(mgrList);
	anykey_continue();
}
