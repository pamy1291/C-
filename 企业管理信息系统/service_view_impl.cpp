#include "service_view_impl.h"
#include "tools.h"
#include <cstdlib>
#include <getch.h>
//构造
ServiceViewImpl::ServiceViewImpl(void) {
	srcCtrl = new ServiceCtrlImpl;
}
//析构
ServiceViewImpl::~ServiceViewImpl(void) {
	delete srcCtrl;
}

//业务菜单
void ServiceViewImpl::menuSrc(void) {
	while(1) {
		system("clear");
		cout << "   业务管理" << endl;
		cout << "1. 增加部门" << endl;
		cout << "2. 删除部门" << endl;
		cout << "3. 显示所有部门" << endl;
		cout << "4. 增加员工" << endl;
		cout << "5. 删除员工" << endl;
		cout << "6. 修改员工信息" << endl;
		cout << "7. 显示部门员工信息" << endl;
		cout << "8. 显示所有员工信息" << endl;
		cout << "9. 退出" << endl;
		switch(get_cmd('1', '9')) {
			case '1': addDept(); break;
			case '2': delDept(); break;
			case '3': listDept(); break;
			case '4': addEmp(); break;
			case '5': delEmp(); break;
			case '6': modEmp(); break;
			case '7': listEmp(); break;
			case '8': listAllEmp(); break;
			case '9': return;
		}
	}
}
//增加部门
void ServiceViewImpl::addDept(void) {
	char name[40];//部门名称
	cout << "请输入部门名称：";
	get_str(name, 40);
	Department dept(name);//临时对象
	if(srcCtrl->addDept(dept)) {
		cout << "成功增加 " << name << endl; 
	}else {
		cout << "部门数量上限！" << endl;
	}
	anykey_continue();
}
//删除部门
void ServiceViewImpl::delDept(void) {
	int id = -1;
	cout << "请输入需要删除的部门id：";
	cin >> id;
	if(id == srcCtrl->delDept(id)) {
		cout << "部门删除成功！" << endl; 
	}else {
		cout << "部门不存在！" << endl;
	}
	anykey_continue();
}
//显示所有部门信息
void ServiceViewImpl::listDept(void) {
	//获取部门数组
	vector<Department>& deptArr = srcCtrl->listDept();
	show(deptArr);
	anykey_continue();
}
//增加员工
void ServiceViewImpl::addEmp(void) {
	int id;//员工部门id
	cout << "请输入需要增加的员工所属部门id：";
	cin >> id;
	char name[40];//员工姓名
	char sex;//性别
	int age;//年龄
	cout << "请输入员工姓名：";
	get_str(name, 40);
	cout << "请输入员工性别：";
	cin >> sex;
	cout << "请输入员工年龄：";
	cin >> age;
	Employee emp(name, sex, age);
	if(srcCtrl->addEmp(id, emp)) {
		cout << "成功添加：" << name << endl;
	}else {
		cout << "部门不存在！" << endl;
	}
	anykey_continue();
}
//删除员工
void ServiceViewImpl::delEmp(void) {
	int id;//待删除的员工id
	cout << "请输入需要删除的员工id：";
	cin >> id;
	if(srcCtrl->delEmp(id)) {
		cout << "删除成功！" << endl;
	}else {
		cout << "该员工不存在！" << endl;
	}
	anykey_continue();
}
//修改员工信息
void ServiceViewImpl::modEmp(void) {
	int id;//待修改的员工id
	char name[40];//修改后的员工姓名
	char sex;//修改后的员工性别
	int age;//修改后的员工年龄
	cout << "请输入需要修改的员工id：";
	cin >> id;
	cout << "请输入修改后的员工姓名：";
	get_str(name, 40);
	cout << "请输入修改后的性别：";
	cin >> sex;
	cout << "请输入修改后的年龄：";
	cin >> age;
	Employee emp(name, sex, age);
	//调用业务逻辑函数进行修改
	if(srcCtrl->modEmp(id, emp)) {
		cout << "修改成功！" << endl;
	}else {
		cout << "该员工不存在！" << endl;
	}
	anykey_continue();
}
//显示某部门员工
void ServiceViewImpl::listEmp(void) {
	int id;//需要显示员工的部门id
	cout << "请输入部门id：" << endl;
	cin >> id;
	Department* dept = srcCtrl->listEmp(id);
	if(NULL == dept) {
		cout << "该部门id不存在，请检查！" << endl;
	}else {
		//显示当前部门员工
		show(dept->empList);
	}
	anykey_continue();
}
//显示所有员工
void ServiceViewImpl::listAllEmp(void) {
	system("clear");
	//获取部门数组
	vector<Department>& deptArr = srcCtrl->listAllEmp();
	auto it_dept = deptArr.begin();
	while(1) {
		system("clear");
		cout << "<< " << *it_dept << " >> " << endl;
		//显示该部门下的所有员工
		for(auto it_emp = it_dept->empList.begin(); 
				it_emp != it_dept->empList.end(); it_emp++) {
			cout << *it_emp << endl;
		}
		cout << "q. 退出" << endl;
		switch(getch()) {//换页处理
			case LEFT : 
				if(it_dept != deptArr.begin()) it_dept--; 
				break;
			case RIGHT : 
				if(it_dept != deptArr.end()) it_dept++; 
				if(it_dept == deptArr.end()) it_dept--;
				break;
			case 'q': 
				return;
		}
		stdin->_IO_read_ptr = stdin->_IO_read_end;//进来前先清缓冲区，防止上次残留
	}
}


