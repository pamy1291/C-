#include "manager_view.h"
#include "manager_ctrl_impl.h"
#include "service_view_impl.h"
#include "manager.h"
#include <iostream>
using namespace std;

class ManagerViewImpl : public ManagerView{
	ManagerCtrl* mgrCtrl;
	ServiceView* srcView;
public:
	ManagerViewImpl(void);
	~ManagerViewImpl(void);
	//超级管理员登录
	void loginManager(void);
	//业务管理员登录
	void loginService(void);
	//登录菜单
	void menuAll(void);
	//超级管理员用户菜单
	void menuMgr(void);
	//增加管理员
	void addMgr(void);
	//删除管理员
	void delMgr(void);
	//显示所有管理员
	void listMgr(void);	
};
