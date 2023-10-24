#ifndef GUEST_H
#define GUEST_H

#include "tools.h"

class Guest {
	string name;
	char sex;
	string id;//身份证号码
public:
	Guest(const string& name, char sex, const string& id):name(name), sex(sex), id(id){}
	//friend修饰后可在声明里实现
	friend ostream& operator<<(ostream& os, const Guest& guest) {
		return os << guest.name << " " << guest.sex << " " << guest.id;
	}
};
#endif
