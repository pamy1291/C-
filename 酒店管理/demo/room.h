#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <list>
#include "tools.h"
#include "guest.h"

using namespace std;

class Room {
	int cur_cnt;//当前入住人数
	list<Guest> guest;//入住对象
public:
	int num;//房号
	int type;//房型
	int price;//房价
	Room(int num, int type, int price);
	bool check_in(const Guest& guest);//入住
	void check_out(const Guest& guest);//退房
	~Room(void);
	int get_cur_cnt(void)const;
	friend ostream& operator<<(ostream& os, const Room& r);
};

#endif
