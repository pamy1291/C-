#include "emis.h"
using namespace std;

//超级管理员帐号与密码
const char* su_user = "root";
const char* su_pwd = "2020";

//生成管理员id
int get_mgrid(void) {
	//打开文件读取数据
	fstream fs("./files/id.dat");
	if(!fs) {
		cout << "文件读取错误！" << endl;
		return -1;
	}
	int mgrid = -1;
	fs.seekg(MGRID_OFFSET, ios::beg);
	fs >> mgrid;//读出文件中的部门id
	++mgrid;//保存最新id
	
	//将新创立的管理员id更新到文件中
	fs.seekg(MGRID_OFFSET, ios::beg);
	fs << mgrid;
	fs.close();
	//返回新id
	return mgrid;
}
//生成部门id
int get_deptid(void) {
	//打开文件读取数据
	fstream fs("./files/id.dat");
	if(!fs) {
		cout << "文件读取错误！" << endl;
		return -1;
	}
	int deptid = -1;
	fs.seekg(DEPTID_OFFSET, ios::beg);
	fs >> deptid;//读出文件中的部门id
	++deptid;//保存当前id
	
	//将新创立的部门id更新到文件中
	fs.seekg(DEPTID_OFFSET, ios::beg);
	fs << deptid;
	fs.close();
	//返回新id
	return deptid;
}
//生成员工id
int get_empid(void) {
	//打开文件读取数据
	fstream fs("./files/id.dat");
	if(!fs) {
		cout << "文件读取错误！" << endl;
		return -1;
	}
	int empid = -1;
	fs.seekg(EMPID_OFFSET, ios::beg);
	fs >> empid;//读出文件中的部门id
	++empid;//保存当前新id
	
	//将新创立的部门id更新到文件中
	fs.seekg(EMPID_OFFSET, ios::beg);
	fs << empid;
	fs.close();
	//返回新id
	return empid;
}

