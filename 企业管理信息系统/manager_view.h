#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include <iostream>

class ManagerView {
public:
	virtual ~ManagerView(void) {}
	//超级管理员登录
	virtual void loginManager(void) = 0;
	//业务管理员登录
	virtual void loginService(void) = 0;
	//用户菜单
	virtual void menuAll(void) = 0;
	//增加管理员
	virtual void addMgr(void) = 0;
	//删除管理员
	virtual void delMgr(void) = 0;
	//显示所有管理员
	virtual void listMgr(void) = 0;
};
#endif//MANAGER_VIEW_H
