#ifndef SERVICE_VIEW_H
#define SERVICE_VIEW_H

#include <iostream>
using namespace std;

//业务子系统用户层
class ServiceView {
public:
	virtual ~ServiceView(void) {}
	virtual void menuSrc(void) = 0;
	virtual void addDept(void) = 0;//增加部门
	virtual void delDept(void) = 0;
	virtual void listDept(void) = 0;//显示所有部门信息
	virtual void addEmp(void) = 0;//增加员工
	virtual void delEmp(void) = 0;//删除员工
	virtual void modEmp(void) = 0;//修改员工信息
	virtual void listEmp(void) = 0;//显示某个员工
	virtual void listAllEmp(void) = 0;//显示所有员工
};

#endif//SERVICE_VIEW_H
