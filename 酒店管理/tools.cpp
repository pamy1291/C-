#include <iostream>
#include "tools.h"
using namespace std;

void anykey_continue(void) {
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
	cout << "请按任意键继续..." << endl;
	getch();
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲
}
