#include <iostream>
#include "xml_parse.h"
using namespace std;

XmlParse::XmlParse() {
	doc = new TiXmlDocument;
	root = NULL;
}
XmlParse::XmlParse(const char* xml_path) {
	doc = new TiXmlDocument(xml_path);	
	doc->LoadFile();
	root = doc->RootElement();
	parse();
}
XmlParse::~XmlParse(void) {
	delete doc;
}

//解析XML文件，遍历后以键值对形式存储到map中
void XmlParse::parse(void) {
	env.clear(); //先清空
	TiXmlElement* node = root->FirstChildElement();
	while(node) { //解析每个节点
		TiXmlElement* son = node->FirstChildElement();
		while(son) { //解析node节点中的所有子节点
			env[son->Value()] = son->GetText();
			son = son->NextSiblingElement();
		}
		node = node->NextSiblingElement();
	}
}
void XmlParse::parse(const char* xml_path) {
	if(NULL == root) {
		doc->LoadFile(xml_path);
	} else {
		delete doc;
		doc = new TiXmlDocument(xml_path);	
		doc->LoadFile();
	}
	root = doc->RootElement();
	parse();
}

//从map中读取key的value
const char* XmlParse::getValue(const char* key) {
	map<string, string>::iterator it = env.find(key);
	if(it == env.end()) {
		return NULL;
	}
	return it->second.c_str();
}
//显示解析的所有内容
void XmlParse::show() const {
	for(map<string, string>::const_iterator it = env.begin(); it != env.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}
