#include "service_mode_impl.h"
#include "department.h"
#include <fstream>

//载入部门及员工信息
void ServiceModeImpl::load(vector<Department>& dept) {
	fstream fs("./files/services.dat");
	if(!fs) {
		cout << "文件加载错误！" << endl;
	}

	while(1) {
		Department dept_ex;//临时部门对象
		int cal = 0;//员工数量
		//读取部门信息及成员个数
		fs >> dept_ex >> cal;
		//if(fs.peek() == EOF) break;
		if(fs.fail()) break;
		while(cal-- > 0) {
			Employee emp;//临时员工对象
			fs >> emp;
			//所有部门及成员均读取结束
			dept_ex.empList.push_back(emp);
		}
		dept.push_back(dept_ex);//将该部门添加至数组
	}
	fs.close();
}
//保存部门及员工信息
void ServiceModeImpl::save(vector<Department>& dept) {
	ofstream ofs("./files/services.dat", ios::out);
	if(!ofs) {
		cout << "无文件权限！" << endl;
	}
	//遍历每个部门
	for(auto it_dept = dept.begin(); it_dept != dept.end(); it_dept++) {
		ofs << *it_dept << " " << it_dept->empList.size() << endl;
		//保存对应员工
		for(auto it_emp = it_dept->empList.begin(); 
					it_emp != it_dept->empList.end(); it_emp++) {
			ofs << *it_emp << endl;
		}
	}
	ofs.close();
}



