#include <iostream>
#include <cstring>
#include <getch.h>
#include "room.h"
#include <cstdlib>
using namespace std;

Room::Room(int num, int type, int price):num(num),type(type),price(price) {
	cur_cnt = 0;//初始时入住人数为0
}
Room::~Room(void) {
	guest.clear();
}


//入住
bool Room::check_in(const Guest& guest) {
	if(cur_cnt < type) {
		cur_cnt++;
		this->guest.push_back(guest);
		return true;
	}else {
		cout << "该房间人数已满，请查询其他空房！" << endl;
	}
	return false;
}
//退房
void Room::check_out(const Guest& guest) {
	this->guest.remove(guest);
	cur_cnt = this->guest.size();
}
//返回当前入住人数
int Room::get_cur_cnt(void)const {
	return cur_cnt;
}
//输出运算符重载,用于显示特定类对象
ostream& operator<<(ostream& os, const Room& r) {
	os << "房号:" << r.num << endl;
	os << "房型:" << r.type << endl;
	os << "房价:" << r.price << endl;
	os << "入住人数:" << r.cur_cnt << endl;
	if(0 != r.cur_cnt) {
    	list<Guest>::iterator it;
    	for (it = (const_cast<Room&>(r)).guest.begin(); it != (const_cast<Room&>(r)).guest.end(); ++it) {
        	cout << *it;
    	}
    	/*
    	it = (const_cast<Room&>(r)).guest.begin();
    	int cmd;
    	while((cmd=getch()) != 'q') {
    		stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
    		cout << *it;
    		if(cmd == LEFT && it != (const_cast<Room&>(r)).guest.begin()) it--;
    		else if(cmd == RIGHT && it!= (const_cast<Room&>(r)).guest.end()) it++;
    		else continue;
    	}*/
		
	}	 
	return os;
}
