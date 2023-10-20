#ifndef MANAGER_CTRL_H
#define MANAGER_CTRL_H

#include <iostream>
#include <list>
#include "manager.h"

class ManagerCtrl {
public:
	virtual ~ManagerCtrl(void) {}
	virtual bool addMgr(Manager&) = 0;
	virtual bool delMgr(int) = 0;
	//返回储存管理员的链表引用
	virtual list<Manager>& listMgr(void) = 0;
};
#endif//MANAGER_CTRL_H
