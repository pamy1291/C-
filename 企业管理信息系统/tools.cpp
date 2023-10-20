#include "tools.h"


//任意键继续
void anykey_continue(void) {
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清除getch残留在输入缓冲区的换行
	cout << "请按任意键继续..." << endl;
	getch();
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲
}
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
//获取max_len-1个有效字符(结尾置为结束符)，可以输入中文
int get_str(char buf[], int max_len) {
	stdin->_IO_read_ptr = stdin->_IO_read_end;//进来前先清缓冲区，防止上次残留
	int len = 0;
	fgets(buf, max_len, stdin);
	while(buf[len]) len++;//获取有效长度
	if(buf[len-1] && buf[len-1] == '\n') {//输入过短，\n接收进去了
		buf[len-1] = '\0';
		len--;//除去'\n'的实际个数
	}
	//过长时清缓冲区
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲区
	return len;
}

/*
 *获取指定长度字符
 *@buffer[]:接收字符数组
 *@len:有效数据长度
 *@type:字符用途类型，无特殊类型为0即可
 *@type_digit:限定为数字类型 不限定为数字0即可
 */
int get_string(char buffer[],int len, int type, int type_digit) {
	int cnt=0;
	int readch;
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲区
	while(cnt < len) {//不足len个时
		while( (readch=getch()) != '\n') {//有效字符获取	
			//限制左右键
			if(readch == LEFT || readch == RIGHT) {
				getch();
				continue;
			}
			if(readch == BACK) {//退格
				if(cnt > 0) { 
					cnt--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
				continue;
			}
			if(type_digit == DIGIT_TYPE) {//数字判断
				if(cnt < len && '0' <= readch && readch <= '9') {
					//回显
					if(type != PWD_TYPE) {//判断字符类型
						putchar(readch);
						buffer[cnt++] = readch;//赋值合法字符
					}else {//密码不可见						
						putchar('*');
						buffer[cnt++] = readch;//赋值合法字符
					}
				} 
				else continue;
			}			 
			else {//可为非数字
				if(cnt < len) {
					//回显
					if(type != PWD_TYPE) {
						putchar(readch);
						buffer[cnt++] = readch;//赋值合法字符
					}else {						
						putchar('*');
						buffer[cnt++] = readch;//赋值合法字符
					}
				} 
			}
		}//while(getch)
		break;
	}//while(cnt < len)
	printf("\n");
	if(cnt <= len) buffer[cnt] = 0;//输入数量小于最大时，最后一位置空
	stdin->_IO_read_ptr = stdin->_IO_read_end;//清缓冲区
	return cnt;
}
