#include "json.h"
#include <iostream>
using namespace std;

JSON::JSON(void) {
	root = cJSON_CreateObject();
	str = NULL;
}
JSON::~JSON(void) {
	cJSON_Delete(root);
	free(str);
	str = NULL;
}

//JSON对象转字符串
char* JSON::getStr() {
	free(str);
	str = cJSON_Print(root);
	if(NULL == str) {
		cout << cJSON_GetErrorPtr();
	}
	return str;
}
/*
 *把数据转换成JSON对象的节点
 *@name:key_name
 *@data:key对应的值
 */
void JSON::addObject(const char* name, bool data) {
	data ? cJSON_AddTrueToObject(root, name) : cJSON_AddFalseToObject(root, name);
}
void JSON::addObject(const char* name, const char* data) {
	cJSON_AddStringToObject(root, name, data);
}
void JSON::addObject(const char* name, JSON& node) {
	cJSON_AddItemToObject(root, name, node.root);
}





