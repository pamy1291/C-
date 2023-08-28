#include <iostream>
#include <cstring>
#include <getch.h>
#include <cstdlib>
#include "run.h"
using namespace std;

void menu(void) {
	system("clear");
	cout << "1. 办理入住" << endl;
	cout << "2. 客户退房" << endl;
	cout << "3. 查询空房" << endl;
	cout << "4. 查询房间(价格查询)" << endl;
	cout << "5. 查询房间(门牌号查询)" << endl;
	cout << "6. 升级" << endl;
	cout << "q. 退出系统" << endl;
}
void load(void) {
	Hotel& hotel = Hotel::get_hotel();
	while(1) {
		menu();
		switch(getch()) {
			case '1':hotel.check_in();break;
			case '2':hotel.check_out();break;
			case '3':
				hotel.show_empty_room();break;
			case '4':
				hotel.query_room_price();break;
			case '5':
				hotel.query_room_num();break;
			case '6':hotel.init();break;
			case 'q':return;
			default: break;
		}
		stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
		//sleep(1);//1s
	}
}

