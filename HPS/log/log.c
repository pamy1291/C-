#include "log.h"
#include <stdio.h>
#include <limits.h>

// 记录用户设置的日志等级的全局变量，决定整个项目的日志级别
LogLevel Log_Level;
//	日志文件的文件指针
FILE* ifp;
FILE* wfp;
FILE* efp;
FILE* ffp;
//	提供给用户 初始化日志文件路径、可执行文件名、等级
void log_init(const char* log_path, const char* program, LogLevel level) {
	Log_Level = level;
#ifdef DEBUG 
	//调试阶段 显示提示信息到屏幕
	ifp = stdout;
	wfp = stdout;
	efp = stdout;
	ffp = stdout;
#else
	//运营阶段
	char path[PATH_MAX] = {};
	sprintf(path,"%s/%s_info.log",log_path, program);
	ifp = fopen(path, "a");

	sprintf(path,"%s/%s_warning.log",log_path, program);
	wfp = fopen(path, "a");

	sprintf(path,"%s/%s_error.log",log_path, program);
	efp = fopen(path, "a");

	sprintf(path,"%s/%s_fatal.log",log_path, program);
	ffp = fopen(path, "a");
#endif 
}

