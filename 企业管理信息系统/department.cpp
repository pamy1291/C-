#include "department.h"
using namespace std;

Department::Department(const char* name) {
	strcpy(this->name, name);
	id = get_deptid();
}
Department::~Department(void) {
	
}
/*设置部门相关信息*/
void Department::setid(int id) {
	this->id = id;
}
void Department::setName(const char* name) {
	strcpy(this->name, name);
}
/*获取部门相关信息*/
int Department::getid(void) {
	return id;
}
char* Department::getName(void) {
	return name;
}
//输入输出重载
istream& operator>>(istream& is, Department& dept) {
	return is >> dept.id >> dept.name;
}
ostream& operator<<(ostream& os, const Department& dept) {
	return os << dept.id << " " << dept.name;
}
