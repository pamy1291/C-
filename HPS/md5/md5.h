#ifndef MD5_H
#define MD5_H

#include <stdio.h>

typedef struct
{
	unsigned int count[2];
	unsigned int state[4];
	unsigned char buffer[64];
}MD5_CTX;

void MD5Init(MD5_CTX *context);
void MD5Update(MD5_CTX *context,unsigned char *input,unsigned int inputlen);
void MD5Final(MD5_CTX *context,unsigned char digest[16]);

// 计算一个字符串的md5值
char* getmd5_str(const char* str, char* md5_str);
// 计算文件的md5值
char* getmd5_file(FILE* fp, char* md5_str);
// 根据文件路径计算文件的md5值
char* getmd5_file_path(const char* path, char* md5_str);

#endif

