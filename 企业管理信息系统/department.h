#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <cstring>
#include <list>
#include "employee.h"
using namespace std;

class Department {
	int id;//部门id
	char name[40];//部门名字
public:
	Department(void) {}
	Department(const char*);
	~Department(void);
	list<Employee> empList;//部门所有员工
	/*设置部门相关信息*/
	void setid(int);
	void setName(const char*);
	/*获取部门相关信息*/
	int getid(void);
	char* getName(void);
	//输入输出重载
	friend istream& operator>>(istream& is, Department& dept);
	friend ostream& operator<<(ostream& os, const Department& dept);
};
#endif//DEPARTMENT_H
