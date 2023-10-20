#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include "manager.h"
#include "manager_mode.h"
#include "emis.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

class ManagerModeImpl : public ManagerMode {
public:
	//从文件中加载数据到内存
	void load(list<Manager>&);
	//保存数据到文件
	void save(list<Manager>&);
};
#endif//MANAGER_MODE_IMPL_H
