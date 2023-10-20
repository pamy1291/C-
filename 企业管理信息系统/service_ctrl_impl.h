#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include "service_ctrl.h"
#include "service_mode_impl.h"
#include "department.h"
#include <iostream>
#include <vector>
using namespace std;

class ServiceCtrlImpl : public ServiceCtrl{
	ServiceMode* srcMode;
	vector<Department> deptArr;//所有部门组合
public:
	ServiceCtrlImpl(void);
	~ServiceCtrlImpl(void);
	bool addDept(Department&);//增加部门
	int delDept(int);//删除部门
	vector<Department>& listDept(void);//用于显示所有部门信息,返回部门数组
	bool addEmp(int, Employee&);//增加员工
	bool delEmp(int);//根据部门id删除员工
	bool modEmp(int, Employee&);//修改员工信息
	Department* listEmp(int);//显示某个部门员工
	vector<Department>& listAllEmp(void);//显示所有员工
};
#endif//SERVICE_CTRL_IMPL_H
