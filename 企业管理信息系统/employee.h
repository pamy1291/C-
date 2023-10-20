#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <cstring>
#include <stdint.h>
#include "tools.h"
#include "emis.h"
using namespace std;

//员工类
class Employee {
	int id;//id号
	char name[40];//姓名
	char sex;//性别
	int age;//年龄
public:
	Employee() {}
	Employee(const char* name, char sex, int age);
	/*修改相关信息*/
	void setid(int);
	void setName(const char*);
	void setSex(char);
	void setAge(int);
	/*查看相关信息*/
	int getid(void);
	char* getName(void);
	char getSex(void);
	int getAge(void);
	friend istream& operator>>(istream& is, Employee& emp);
	friend ostream& operator<<(ostream& os, const Employee& emp);
};
#endif//EMPLOYEE_H
