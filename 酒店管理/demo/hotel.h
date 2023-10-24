#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <list>
#include "room.h"
using namespace std;

class Room_list{
public:
	list<Room> room;
	int local_layer;
};

class Hotel {
	static Hotel hotel;
	int layer_cal;//层数
	int* layer_room_cal;//每层房间数
	Room_list* rooms_layer;
	Hotel(void) {
		init();
	}
	Hotel(const Hotel& that) {

	}
public:
	//获取程序运行前创建的静态类对象
	static Hotel& get_hotel(void) {
		return hotel;
	}
	int init(void);
	//入住
	bool check_in(void);
	//退房
	void check_out(void);
	//查看空房
	int show_empty_room(void)const;
	//根据价格查询房间
	int query_room_price(void)const;
	//根据房号查询房间
	Room& query_room_num(void)const;
	//升级
	bool upgrade(void);
};

#endif
