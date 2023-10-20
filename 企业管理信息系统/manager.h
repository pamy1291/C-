#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <cstring>
#include "tools.h"
using namespace std;

class Manager {
int id;//管理员id
char name[40];//管理员姓名
char pwd[20];//管理员密码
public:
	Manager(const char* name, const char* pwd);
	Manager(void) {}
	Manager(const Manager& that);
	int getid(void) const;//查看id
	const char* getName(void) const;//查看姓名
	const char* getPwd(void) const;
	void setid(int id);//修改id
	void setName(const char* name);//修改姓名
	void setPwd(const char* pwd);
	//显示某个管理员对象
	friend ostream& operator<<(ostream& os, const Manager& mgr);
};

#endif//MANAGER_H
