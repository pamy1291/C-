#ifndef EMIS_H
#define EMIS_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

/*各id在文件中的偏移位置*/
#define MGRID_OFFSET 0
#define DEPTID_OFFSET 3
#define EMPID_OFFSET 7

#define MAX_MANAGER 10 //最大管理员数量
#define MAX_DEPT 20 //部门允许数量

//容器内容显示
template<class TYPE>
void show(const list<TYPE>& list) {
	system("clear");
	for(auto it = list.begin(); it != list.end(); it++) {
		cout << *it << endl;
	}
}
template<class TYPE>
void show(const vector<TYPE>& vc) {
	system("clear");
	for(auto it = vc.begin(); it != vc.end(); it++) {
		cout << *it << endl;
	}
}

//超级管理员帐号与密码
extern const char* su_user;
extern const char* su_pwd;

//生成管理员id
int get_mgrid(void);
//生成部门id
int get_deptid(void);
//生成员工id
int get_empid(void);

#endif//EMIS_H
