#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <getch.h>
using namespace std;

#define UP 183
#define DOWN 184
#define LEFT 186
#define RIGHT 185
#define BACK 127

#define PWD_TYPE 6	//密码类型
#define DIGIT_TYPE 1	//限定数字

//任意键继续
void anykey_continue(void);
//获取指定长度字符
int get_string(char buffer[],int len, int type, int type_digit);
//获取指定个数字符(包括中文)
int get_str(char buf[], int max_len);
//获取指定范围字符
char get_cmd(char start, char end);

#endif
