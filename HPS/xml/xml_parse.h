#ifndef XML_PARSE_H
#define XML_PARSE_H

#include "tinyxml.h"
#include <map>
using namespace std;

class XmlParse {
	TiXmlDocument* doc;
	map<string, string> env;
	TiXmlElement* root;
public:
	XmlParse();
	XmlParse(const char* xml_path);
	~XmlParse(void);

	//解析XML文件，遍历后以键值对形式存储到map中
	void parse(void);
	void parse(const char* xml_path);

	//从map中读取key的value
	const char* getValue(const char* key);
	
	//显示解析的所有内容
	void show() const;
};

#endif//XML_PARSE_H
