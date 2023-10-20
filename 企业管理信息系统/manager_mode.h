#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include <iostream>
#include "manager_ctrl.h"

class ManagerMode {
public:
	virtual ~ManagerMode(void) {}
	//从文件中加载数据到内存
	virtual void load(list<Manager>&) = 0;
	//保存数据到文件
	virtual void save(list<Manager>&) = 0;
};
#endif//MANAGER_CTRL_H
