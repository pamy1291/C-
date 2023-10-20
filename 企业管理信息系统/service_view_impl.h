#ifndef SERVICE_VIEW_IMPL_H
#define SERVICE_VIEW_IMPL_H

#include "service_view.h"
#include "service_ctrl_impl.h"
#include <iostream>
using namespace std;

class ServiceViewImpl : public ServiceView{
	ServiceCtrl* srcCtrl;
public:
	ServiceViewImpl(void);
	~ServiceViewImpl(void);
	void menuSrc(void);//业务菜单
	void addDept(void);//增加部门
	void delDept(void);//删除部门
	void listDept(void);//显示所有部门信息
	void addEmp(void);//增加员工
	void delEmp(void);//删除员工
	void modEmp(void);//修改员工信息
	void listEmp(void);//显示某个员工
	void listAllEmp(void);//显示所有员工
};

#endif//SERVICE_VIEW_IMPL_H
