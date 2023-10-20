#include <iostream>
#include "tinyxml.h"
#include "xml_parse.h"
using namespace std;

int main(int argc,const char* argv[])
{
	XmlParse xml("config.xml");
	xml.show();
	cout << xml.getValue("log_level") << endl;
	

	/*
	TiXmlDocument xml("config.xml");
	if(!xml.LoadFile()) {
		cout << "xml文件不存在!" << endl;
		return 0;
	}
	xml.Print(stdout);
	cout << endl;

	TiXmlElement* root = xml.RootElement();

	TiXmlElement* node = root->FirstChildElement();
	while(node) { //解析每个节点
		cout << node->Value() << endl;
		TiXmlElement* son = node->FirstChildElement();
		while(son) { //解析node节点中的所有子节点
			cout << son->Value() << " " << son->GetText() << endl;
			son = son->NextSiblingElement();
		}
		node = node->NextSiblingElement();
		cout << endl;
	}
	*/


	return 0;
}
