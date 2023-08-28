#include <iostream>
#include "guest.h"
using namespace std;

Guest::Guest(string name, char sex, string id_card):name(name),sex(sex),id_card(id_card) {}
string Guest::get_id_card(void)const {
	return id_card;
}
//重载==，用于链表住客链表移除比较
bool Guest::operator==(const Guest& that)const {
	return id_card == that.id_card;
}

//输出运算符重载,用于显示特定类对象
ostream& operator<<(ostream& os, const Guest& guest) {
	if(guest.id_card.length())
		os << "姓名：" << guest.name << " 性别：" << guest.sex << " 身份证号码:" << guest.id_card << endl;
	return os;
}

