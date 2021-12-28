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
snprintf�����÷������ɱ����(...)���� format ��ʽ�����ַ����������ַ������Ƶ� str ��
������int snprintf ( char * str, size_t size, const char * format, ... );

����:
	str -- Ŀ���ַ���
	size -- �����ֽ���(Bytes)
	format -- ��ʽ�����ַ���
	... -- �ɱ����

����ֵ��
	�����ʽ������ַ�������С�ڵ��� size�������ַ���ȫ�����Ƶ� str �У�
	����������һ���ַ��������� \0��

	�����ʽ������ַ������ȴ��� size������ size �Ĳ��ֻᱻ�ضϣ�
	ֻ�����е� (size-1) ���ַ����Ƶ� str �У�����������һ���ַ��������� \0��
	����ֵΪ��д����ַ������ȡ�
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