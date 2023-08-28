#include "hotel.h"
#include <cstdio>
#include <cstdlib>

Hotel Hotel::hotel;

//加载房间信息
bool Hotel::load(const char* path) {
	FILE* f = fopen(path, "r");
	if(NULL == f) {
		perror("fopen");
		fclose(f);
		return false;
	}
	fscanf(f, "%d", &level_cnt);
	level_room = new int[level_cnt];
	rooms = new Room**[level_cnt];//为层数申请地址
	for(int i=0; i<level_cnt; i++) {
		fscanf(f, "%d", level_room+i);
		rooms[i] = new Room*[level_room[i]];
		for(int j=0; j<level_room[i]; j++) {
			short id;
			char type;
			float price;
			fscanf(f, "%hd %hhd %f", &id, & type, &price);
			rooms[i][j] = new Room(id, type, price);
		}
	}
	fclose(f);
	return true;
}
//酒店运行
void Hotel:: start(void) {
	for(;;) {
		switch(menu()) {
			case '1': check_in(); break;
			case '2': query_room(); break;
			case '3': check_out(); break;
			case '4': list_empty(); break;
			case '5': upgrade_room(); break;
			case '6': return;
			default: break;
		}
	}
}
//菜单
int Hotel::menu(void) {
	system("clear");
	cout << "   酒店管理系统" << endl;
	cout << "1. 入住		2. 查询房间" << endl;
	cout << "3. 退房		4. 查询空房" << endl;
	cout << "5. 升级		6. 退出系统" << endl;
	
	return get_cmd('1', '6');
}
//找房间
Room* Hotel::find_room(short room_id) {
	for(int i=0; i<level_cnt; i++) {
		for(int j=0; j<level_room[i]; j++) {
			if(*rooms[i][j] == room_id) {
				return rooms[i][j];
			}
		}
	}
	return NULL;
}
//入住
void Hotel:: check_in(void) {
	short room_id;
	cout << "请输入要入住的房间号：" << endl;
	cin >> room_id;
	Room* room = find_room(room_id);
	if(NULL == room) {
		cout << "无效房间号" << endl;
		anykey_continue();
		return;
	}
	string name, id;
	char sex;
	cout << "请输入入住人姓名 性别 身份证号码:"<< endl;
	cin >> name >> sex >> id;
	Guest* guest = new Guest(name, sex, id);
	if(room->in(guest)) {
		cout << "入住成功" << endl;
	}else {
		cout << "该房间已满" << endl;
	}
	delete guest;
	anykey_continue();
}
//显示空房
void Hotel:: list_empty(void) {
	for(int i=0; i<level_cnt; i++) {
		for(int j=0; j<level_room[i]; j++) {
			if(rooms[i][j]->is_empty()) {
				cout << *rooms[i][j];
			}
		}
	}
	anykey_continue();
}
//显示已入住
void Hotel:: query_room(void) {
	for(int i=0; i<level_cnt; i++) {
		for(int j=0; j<level_room[i]; j++) {
			if(!rooms[i][j]->is_empty()) {
				cout << *rooms[i][j];
			}
		}
	}
	anykey_continue();
}
//退房
void Hotel:: check_out(void) {
	short room_id;
	cout << "请输入退房房间号" << endl;
	cin >> room_id;
	Room* room = find_room(room_id);
	if(NULL == room) {
		cout << "无效房间号" << endl;
		return;
	}
	//全人退
	if(room->out()) {
		cout << "退房成功" << endl;
	}else {
		cout << "空房间" << endl;
	}
	anykey_continue();
}
//升级
void Hotel:: upgrade_room(void) {
	cout << __func__ << endl;
}


