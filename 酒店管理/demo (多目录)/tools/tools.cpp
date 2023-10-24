#include "tools.h"

//允许输入范围start～end
char get_cmd(char start, char end) {
	puts("请输入指令：");
	while(1) {
		stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲区
		char cmd = getch();
		if(start <= cmd && cmd <= end) {
			cout << cmd << endl;
			return cmd;
		}
	}
}
void anykey_continue(void) {
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
	cout << "请按任意键继续..." << endl;
	getch();
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲
}
