#include "manager_mode_impl.h"

//从文件中加载管理员数据到内存
void ManagerModeImpl::load(list<Manager>& mgrList) {
	fstream fs("./files/managers.dat");
	if(!fs) {
		cout << "managers.dat 文件加载错误！" << endl;
	}
	Manager mgr;
	while(1) {
		fs.read((char*)&mgr, sizeof(Manager));
		if(fs.eof()) break;
		mgrList.push_back(mgr);//将读取的管理员放入链表
	}
	//关闭文件
	fs.close();
}
//保存管理员数据到文件
void ManagerModeImpl::save(list<Manager>& mgrList) {
	ofstream ofs("./files/managers.dat", ios::out);
	if(!ofs) {
		cout << "无文件权限！" << endl;
	}
	Manager mgr;
	for(auto it = mgrList.begin(); it != mgrList.end(); it++) {
		mgr = *it;
		ofs.write((char*)&mgr, sizeof(Manager));
	}
	ofs.close();
}
