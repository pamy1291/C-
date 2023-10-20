#include <iostream>
#include "json.h"
using namespace std;

struct Student {
	int id;
	char name[20];
};
struct Score {
	float ma_score;
	float ch_score;
};
int main(int argc,const char* argv[])
{
	Student stu = {1002, "pamy"};

	//数据转JSON对象
	JSON json;
	json.addObject("json_id", stu.id);
	json.addObject("json_name", stu.name);

	//JSON对象转字符串
	//cout << json.getStr() << endl;

	Score score = {99, 88.5};
	JSON json1;
	json1.addObject("ma_score", score.ma_score);
	json1.addObject("ch_score", score.ch_score);
	json.addObject("score", json1);

	
	//cout << json.getStr() << endl;

	//解析
	cout << "------解析第一层数据----------" << endl;
	JSON json3;
	json3.getJson(json.getStr()); //反序列化
	cout << json3.getStr() << endl;
	int id = 0;
	json3.getObject("json_id", id);
	cout << id << endl;
	
	//获取子节点
	cout << "------解析第一层中节点数据----------" << endl;
	JSON json_s;
	json3.getObject("score", json_s);
	cout << json_s.getStr() << endl;
	int ma_score = 0;
	json_s.getObject("ma_score", ma_score);
	cout << ma_score << endl;

	json.delObject();
	json3.delObject();
	return 0;
}
