#include "manager.h"
#include "emis.h"
#include <iomanip>
using namespace std;

//构造函数
Manager::Manager(const char* name, const char* pwd) {
	strcpy(this->name, name);
	strcpy(this->pwd, pwd);
	id = get_mgrid();
}
//拷贝构造
Manager::Manager(const Manager& that) {
	strcpy(this->name, that.name);
	strcpy(this->pwd, that.pwd);
	this->id = that.id;
}

//查看id
int Manager::getid(void) const {
	return id;
}
//查看姓名
const char* Manager::getName(void) const {
	return name;
}
//查看密码
const char* Manager::getPwd(void) const {
	return pwd;
}
//设置id 修改id
void Manager::setid(int id) {
	this->id = id;
}
//设置名字 修改名字
void Manager::setName(const char* name) {
	strcpy(this->name, name);
}
//设置密码 修改密码
void Manager::setPwd(const char* name) {
	strcpy(this->pwd, pwd);
}
//显示管理员信息
ostream& operator<<(ostream& os, const Manager& mgr) {
	os << "ID:" << mgr.id;
	os << " 用户名:" << setiosflags(ios::left) << setw(4) << mgr.name;
	os << " 密码:" << mgr.pwd;
	return os; 
}
