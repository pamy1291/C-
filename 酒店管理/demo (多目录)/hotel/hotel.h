#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"

class Hotel {
	static Hotel hotel;//单例静态酒店对象
	int level_cnt;//层数
	int* level_room;//每层房间数
	Room*** rooms;//每层房间对象指针
	//构造与拷贝私有化
	Hotel(void){}
	Hotel(const Hotel& that){}
public:
	static Hotel& get_hotel(void) {//静态接口函数
		return hotel;
	}
	//加载房间信息
	bool load(const char* path);
	//酒店运行
	void start(void);
	//菜单
	int menu(void);
	//入住
	void check_in(void);
	//显示空房
	void list_empty(void);
	//显示已入住
	void query_room(void);
	//退房
	void check_out(void);
	//升级
	void upgrade_room(void);
	//找房间
	Room* find_room(short room_id);
	/*~Hotel(void) {
		for(int i=0; i<level_cnt; i++) {
			for(int j=0; i<level_room[i]; j++) {
				delete rooms[i][j];//销毁单个房间地址
			}
			delete[] rooms[i];//销毁一层地址
		}
		delete[] rooms;
		
	}*/
};
#endif
