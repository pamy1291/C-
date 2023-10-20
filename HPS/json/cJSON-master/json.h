#ifndef JSON_H
#define JSON_H

#include "cJSON.h"
using namespace std;

class JSON {
	cJSON* root;
	char* str;
public:
	JSON();
	~JSON();

	//JSON对象转字符串
	char* getStr();
	/*
	 *把数据转换成JSON对象的节点
	 *@name:key_name
	 *@data:key对应的值
	 */
	void addObject(const char* name, bool data);
	void addObject(const char* name, const char* data);
	void addObject(const char* name, JSON& data);
	template<typename T>
	void addObject(const char* name, const T& data) {
		//类内函数模板需要直接定义
		cJSON_AddNumberToObject(root, name, data);
	}

};
#endif//JSON_H




