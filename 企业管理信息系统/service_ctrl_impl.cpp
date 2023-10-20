#include "service_ctrl_impl.h"
#include "emis.h"

//构造
ServiceCtrlImpl::ServiceCtrlImpl(void) {
	srcMode = new ServiceModeImpl;
	//载入部门及员工信息
	srcMode->load(deptArr);
}
//析构
ServiceCtrlImpl::~ServiceCtrlImpl(void) {
	//保存部门及员工信息
	srcMode->save(deptArr);
	cout << "部门及员工数据已保存" << endl;
	delete srcMode;
}

//增加部门
bool ServiceCtrlImpl::addDept(Department& dept) {
	if(deptArr.size() >= MAX_DEPT) return false;
	deptArr.push_back(dept);
	return true;
}
//删除部门
int ServiceCtrlImpl::delDept(int id) {
	for(auto it = deptArr.begin(); it != deptArr.end(); it++) {
		if(it->getid() == id) {
			deptArr.erase(it);
			return id;
		}
	}
	return -1;
}
//显示所有部门信息,返回部门数组
vector<Department>& ServiceCtrlImpl::listDept(void) {
	return deptArr;
}
//根据部门id增加员工
bool ServiceCtrlImpl::addEmp(int id, Employee& emp) {
	for(auto it = deptArr.begin(); it != deptArr.end(); it++) {
		if(it->getid() == id) {
			it->empList.push_back(emp);
			return true;
		}
	}
	return false;
}
//根据id删除员工
bool ServiceCtrlImpl::delEmp(int id) {
	//遍历部门
	for(auto it_dept = deptArr.begin(); it_dept != deptArr.end(); it_dept++) {
		//遍历部门下的所有员工
		for(auto it_emp = it_dept->empList.begin(); 
				it_emp != it_dept->empList.end(); it_emp++) {
			if(it_emp->getid() == id) {
				//删除该部门下的员工
				it_dept->empList.erase(it_emp);
				return true;
			}
		}
	}
	return false;
}
//修改员工信息
bool ServiceCtrlImpl::modEmp(int id, Employee& emp) {
	//遍历部门
	for(auto it_dept = deptArr.begin(); it_dept != deptArr.end(); it_dept++) {
		//遍历部门下的所有员工
		for(auto it_emp = it_dept->empList.begin(); 
				it_emp != it_dept->empList.end(); it_emp++) {
			if(it_emp->getid() == id) {
				//删除该部门下的员工
				it_dept->empList.erase(it_emp);
				it_dept->empList.push_back(emp);
				return true;
			}
		}
	}
	return true;
}
//显示某个部门员工
Department* ServiceCtrlImpl::listEmp(int id) {
	//遍历部门
	for(auto it_dept = deptArr.begin(); it_dept != deptArr.end(); it_dept++) {
		if(it_dept->getid() == id) {
			Department* dept = new Department;
			*dept = *it_dept;
			return dept;
		}
	}
	return NULL;
}
//显示所有员工,返回数据给上层显示
vector<Department>& ServiceCtrlImpl::listAllEmp(void) {
	return deptArr;
}

