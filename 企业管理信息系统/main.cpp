#include <iostream>
#include "manager_view_impl.h"
using namespace std;

int main(int argc,const char* argv[]) 
{
	ManagerView* emis = new ManagerViewImpl;
	emis->menuAll();
	delete emis;
}
