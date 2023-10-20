#ifndef LOG_H
#define LOG_H


#include <stdio.h>

//	日志等级
typedef enum LogLevel {
	LOG_INFO, //提示信息
	LOG_WARNING, //警告
	LOG_ERROR, //错误
	LOG_FATAL //致命错误
}LogLevel;


//	全局变量的声明
extern LogLevel Log_Level; //日志等级
//	日志文件指针声明
extern FILE* ifp;
extern FILE* wfp;
extern FILE* efp;
extern FILE* ffp;

//	提供给用户 初始化日志文件路径、可执行文件名、等级
void log_init(const char* log_path, const char* program, LogLevel level);

//	记录日志信息的宏函数
//写入致命错误
#define flog(fmt, ...) { \
	if(Log_Level <= LOG_FATAL) { \
		fprintf(ffp, "FILE:%s FUNC:%s LINE:%d DATE:%s TIME:%s FATAL:",__FILE__, __func__, \
				__LINE__, __DATE__, __TIME__); \
		fprintf(ffp, fmt, __VA_ARGS__); \
	} \
}
//写入错误信息
#define elog(fmt, ...) { \
	if(Log_Level <= LOG_ERROR) { \
		fprintf(efp, "FILE:%s FUNC:%s LINE:%d DATE:%s TIME:%s ERROR:",__FILE__, __func__, \
				__LINE__, __DATE__, __TIME__); \
		fprintf(efp, fmt, __VA_ARGS__); \
	} \
}
//写入警告
#define wlog(fmt, ...) { \
	if(Log_Level <= LOG_WARNING) { \
		fprintf(wfp, "FILE:%s FUNC:%s LINE:%d DATE:%s TIME:%s WARNING:",__FILE__, __func__, \
				__LINE__, __DATE__, __TIME__); \
		fprintf(wfp, fmt, __VA_ARGS__); \
	} \
}
//写入提示信息
#define ilog(fmt, ...) { \
	if(Log_Level <= LOG_INFO) { \
		fprintf(ifp, "FILE:%s FUNC:%s LINE:%d DATE:%s TIME:%s INFO:",__FILE__, __func__, \
				__LINE__, __DATE__, __TIME__); \
		fprintf(ifp, fmt, __VA_ARGS__); \
	} \
}

#endif//LOG_H
