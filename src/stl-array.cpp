#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib> //qsort, bsearch, NULL
#include "assistant_func.h"
#include "stl-array.h"

using namespace std;

const long ASIZE = 500;		// 500000��ʱ�򱨴�����

void jj01::test_array()
{
	cout << "\ntest_array()................ \n";
	array<long, ASIZE> c;
	clock_t timeStart = clock();
	for (long i = 0; i < ASIZE; ++i)
	{
		c[i] = rand();
	}

	cout << "milli-seconds :" << (clock() - timeStart) << endl;
	cout << "array.size()= " << c.size() << endl;
	cout << "array.front()= " << c.front() << endl;		// ��һ��Ԫ��
	cout << "array.back()= " << c.back() << endl;
	cout << "array.data()= " << c.data() << endl;	// ���������һ��Ԫ�����ڴ��λ��

	long target = get_a_target_long();

	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);
	long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
	cout << "qsort() + bsearch(), milli-seconds: " << (clock() - timeStart) << endl;
	if (pItem != NULL)
	{
		cout << "found, " << *pItem << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}
}
