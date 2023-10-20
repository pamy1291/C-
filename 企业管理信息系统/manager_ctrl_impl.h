#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTRL_IMPL_H

#include <iostream>
#include <list>
#include "manager_ctrl.h"
#include "manager_mode_impl.h"
#include "manager.h"
using namespace std;

class ManagerCtrlImpl : public ManagerCtrl {
	list<Manager> mgrList;
	ManagerMode* mgrMode;
public:
	ManagerCtrlImpl(void);
	~ManagerCtrlImpl(void);
	//增加管理员
	bool addMgr(Manager&);
	//删除管理员
	bool delMgr(int);
	//返回储存管理员的链表引用
	list<Manager>& listMgr(void);
};

#endif//MANAGER_CTRL_IMPL_H

