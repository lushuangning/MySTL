#include <iostream>
#include "assistant_func.h"
using std::cin;
using std::cout;
using std::string;

long get_a_target_long()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "):  ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "):  ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

/*
snprintf函数用法：将可变参数(...)按照 format 格式化成字符串，并将字符串复制到 str 中
声明：int snprintf ( char * str, size_t size, const char * format, ... );

参数:
	str -- 目标字符串
	size -- 拷贝字节数(Bytes)
	format -- 格式化成字符串
	... -- 可变参数

返回值：
	如果格式化后的字符串长度小于等于 size，则会把字符串全部复制到 str 中，
	并给其后添加一个字符串结束符 \0；

	如果格式化后的字符串长度大于 size，超过 size 的部分会被截断，
	只将其中的 (size-1) 个字符复制到 str 中，并给其后添加一个字符串结束符 \0，
	返回值为欲写入的字符串长度。
*/

int compareLongs(const void * a, const void * b)
{
	return (*(long*)a - *(long*)b);
}

int compareString(const void* a, const void* b)
{
	if ( *(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}