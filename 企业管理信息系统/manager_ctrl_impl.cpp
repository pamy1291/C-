#include "manager_ctrl_impl.h"
#include "emis.h"
#include <cstdlib>

ManagerCtrlImpl::ManagerCtrlImpl(void) {
	mgrMode = new ManagerModeImpl;
	//载入文件数据
	mgrMode->load(mgrList);
}
ManagerCtrlImpl::~ManagerCtrlImpl(void) {
	//结束前将数据保存至文件
	mgrMode->save(mgrList);
	cout << "管理员数据已保存！" << endl;
	delete mgrMode;
}

//增加管理员
bool ManagerCtrlImpl::addMgr(Manager& mgr) {
	if(mgrList.size() >= MAX_MANAGER) return false;
	mgrList.push_back(mgr);
	return true;
}
//删除管理员
bool ManagerCtrlImpl::delMgr(int id) {
	for(auto it = mgrList.begin(); it != mgrList.end(); it++) {
		if(id == it->getid()) {
			mgrList.erase(it);
			return true;
		}
	}
	return false;
}
//返回储存管理员的链表引用
list<Manager>& ManagerCtrlImpl::listMgr(void) {
	return mgrList;
}

