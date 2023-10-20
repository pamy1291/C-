#ifndef SERVICE_CTRL_H
#define SERVICE_CTRL_H

#include <iostream>
#include <vector>
#include "employee.h"
#include "department.h"
using namespace std;

class ServiceCtrl {
public:
	virtual ~ServiceCtrl(void) {}
	virtual bool addDept(Department&) = 0;//增加部门
	virtual int delDept(int) = 0;//删除部门
	virtual vector<Department>& listDept(void) = 0;//显示所有部门信息
	virtual bool addEmp(int, Employee&) = 0;//增加员工
	virtual bool delEmp(int) = 0;//根据id删除员工
	virtual bool modEmp(int, Employee&) = 0;//修改员工信息
	virtual Department* listEmp(int) = 0;//显示某个部门员工
	virtual vector<Department>& listAllEmp(void) = 0;//显示所有员工
};

#endif//SERVICE_CTRL_H
