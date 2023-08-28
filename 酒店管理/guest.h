#ifndef GUEST_H
#define GUEST_H

#include <iostream>
#include <cstring>
using namespace std;

class Guest {
	string name;
	char sex;
	string id_card;
public:
	Guest(string name="", char sex='\0', string id_card="");
	string get_id_card(void)const;//获取身份证。用于退房时识别
	bool operator==(const Guest& that)const;//比较id_card是否相等，提供给list guest
	friend ostream& operator<<(ostream& os, const Guest& guest);
};

#endif

