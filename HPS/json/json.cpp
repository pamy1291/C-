#include "json.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

JSON::JSON(void) {
	root = cJSON_CreateObject();
	str = NULL;
}
JSON::~JSON(void) {
	free(str);
	str = NULL;
}
//手动释放JSON对象，在析构函数中释放会导致子节点重复释放，只需根节点调用一次即可
void JSON::delObject() {
	cJSON_Delete(root);
	root = NULL;
	free(str);
	str = NULL;
}
//JSON对象转字符串 序列化
char* JSON::getStr() {
	free(str);
	str = cJSON_Print(root);
	if(NULL == str) {
		cout << cJSON_GetErrorPtr() << endl;
	}
	return str;
}
//字符串转JSON对象 反序列化                                             
void JSON::getJson(const char* json_str) {
	cJSON_Delete(root);
	free(str);
	str = NULL;
	root = cJSON_Parse(json_str);
	if(NULL == root) {
		cout << cJSON_GetErrorPtr() << endl;
	}
}

/*
 *把数据转换成JSON对象的节点
 *@name:key_name
 *@data:key对应的值
 */
void JSON::addObject(const char* name, bool data) {
	cJSON_AddBoolToObject(root, name, data);
}
void JSON::addObject(const char* name, const char* data) {
	cJSON_AddStringToObject(root, name, data);
}
void JSON::addObject(const char* name, char data[]) {
	cJSON_AddStringToObject(root, name, data);
}
void JSON::addObject(const char* name, JSON& node) {
	cJSON_AddItemToObject(root, name, node.root);
}

//从JSON对象中解析各种类型数据
bool JSON::getObject(const char* name, char* data) {
    cJSON* obj = cJSON_GetObjectItem(root, name);
    if(NULL == obj) {
    	cout << cJSON_GetErrorPtr() << endl;
        return false;                                                       
    }   
    strcpy(data, obj->valuestring);
    return true;
}
bool JSON::getObject(const char* name, double& data) {
    cJSON* obj = cJSON_GetObjectItem(root, name);
    if(NULL == obj) {
    	cout << cJSON_GetErrorPtr() << endl;
        return false;                                                       
    }   
    data = obj->valuedouble;
    return true;
}
bool JSON::getObject(const char* name, JSON& node) {
    cJSON* obj = cJSON_GetObjectItem(root, name);
    if(NULL == obj) {
    	cout << cJSON_GetErrorPtr() << endl;
        return false;                                                       
    }   
    node.root = obj;
    return true;
}




