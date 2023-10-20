#include "employee.h"
#include <iomanip>
using namespace std;

Employee::Employee(const char* name, char sex, int age) {
	strcpy(this->name, name);
	this->sex = sex;
	this->age = age;
	this->id = get_empid();
}
/*修改相关信息*/
void Employee::setid(int id) {
	this->id = id;
}
void Employee::setName(const char* name) {
	strcpy(this->name, name);
}
void Employee::setSex(char sex) {
	this->sex = sex;
}
void Employee::setAge(int age) {
	this->age = age;
}
/*查看相关信息*/
int Employee::getid(void) {
	return id;
}
char* Employee::getName(void) {
	return name;
}
char Employee::getSex(void) {
	return sex;
}
int Employee::getAge(void) {
	return age;
}
//文件读写及显示
istream& operator>>(istream& is, Employee& emp) {
	return is >> emp.id >> emp.name >> emp.sex >> emp.age;
}
ostream& operator<<(ostream& os, const Employee& emp) {
	os << emp.id << " ";
	//os << setiosflags(ios::left) << setw(8) << emp.name << " ";
	os << emp.name << " ";
	os << emp.sex << " ";
	os << emp.age;
	return os;
}







