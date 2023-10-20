#ifndef JSON_H
#define JSON_H

#include "cJSON.h"
#include <cstring>
#include <iostream>
using namespace std;

class JSON {
	cJSON* root;
	char* str;
public:
	JSON();
	~JSON();

	//手动释放JSON对象
	void delObject();
	//JSON对象转字符串 序列化
	char* getStr();
	//字符串转JSON对象 反序列化
	void getJson(const char* json_str);

	/*
	 *把数据转换成JSON对象的节点
	 *@name:key_name
	 *@data:key对应的值
	 */
	void addObject(const char* name, bool data);
	void addObject(const char* name, const char* data);
	void addObject(const char* name, char data[]);
	void addObject(const char* name, JSON& node);
	template<typename T>
	void addObject(const char* name, const T& data) {
		//类内函数模板需要直接定义
		cJSON_AddNumberToObject(root, name, data);
	}
	
	//从JSON对象中解析各种类型数据
	bool getObject(const char* name, char* data);
	bool getObject(const char* name, double& data);
	bool getObject(const char* name, JSON& node);
	template<typename T>
	bool getObject(const char* name, T& data) {
		cJSON* obj = cJSON_GetObjectItem(root, name);
		if(NULL == obj) {
			cout << cJSON_GetErrorPtr() << endl;
			return false;
		}
		data = obj->valueint;
		return true;
	}
	

};
#endif//JSON_H




