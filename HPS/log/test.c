#include <stdio.h>
#include "log.h"

int main(int argc,const char* argv[])
{
	//初始化log模块
	log_init("./log","test", LOG_ERROR);
	flog("fatal flog %d\n",0);	
	elog("error flog %d\n",1);	
	wlog("warning flog %d\n",2);	
	ilog("info flog %d\n",3);	
	return 0;
}
