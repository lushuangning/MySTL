#include "stl-list.h"

using namespace std;

void jj03::test_list(long&& value)
{
	cout << "\ntest_list()................ \n";
	list<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));		//将一个新的元素加到最后面，位置为当前最后一个元素的下一个元素
		}
		catch(exception& p){
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds :" << (clock() - timeStart) << endl;
	cout << "vector.size()= " << c.size() << endl;		// 有多少元素
	cout << "vector.max_size()= " << c.max_size() << endl;		// list能容纳的最大元素数量
	cout << "vector.front()= " << c.front() << endl;	// 第一个元素
	cout << "vector.back()= " << c.back() << endl;		// 最后一个元素

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);		// c.begin() 目前使用空间的头；c.end() 目前使用空间的尾
	cout << "::find(), milli-seconds :" << (clock() - timeStart) << endl;
	if (pItem != c.end())
	{
		cout << "found, " << *pItem << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}
	timeStart = clock();
	c.sort();		// list容器自己也有sort，而不是全局的sort，效率比全局sort要好
	cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;
}