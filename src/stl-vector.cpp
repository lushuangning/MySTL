#include "stl-vector.h"

using namespace std;

void jj02::test_vector(long&& value)
{
	cout << "\ntest_vector()................ \n";

	vector<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (const std::exception& p)
		{
			cout << "i=" << i << " " << p.what() << endl;
			abort();		// 退出程序
		}
	}

	cout << "milli-seconds :" << (clock() - timeStart) << endl;
	cout << "vector.size()= " << c.size() << endl;		// 有多少元素
	cout << "vector.front()= " << c.front() << endl;	// 第一个元素
	cout << "vector.back()= " << c.back() << endl;		// 最后一个元素
	cout << "vector.data()= " << c.data() << endl;
	cout << "vector.capacity()= " << c.capacity() << endl;		// 目前分配器申请到的空间有多大

	string target = get_a_target_string();

	{
		timeStart = clock();
		// ::find，全局的模板函数
		// c.begin()，迭代器
		auto pItem = ::find(c.begin(), c.end(), target);		
		cout << "::find(), milli-seconds :" << (clock() - timeStart) << endl;
		if (pItem != c.end())
		{
			cout << "found, " << *pItem << endl;
		}
		else
		{
			cout << "not found! " << endl;
		}
	}

	{
		timeStart = clock();
		sort(c.begin(), c.end());
		string* pItem = (string*)bsearch(&target, (c.data()), c.size(), 
			sizeof(string), compareString);
		cout << "sort() + bsearch(), milli-seconds: " << (clock() - timeStart) << endl;
		if (pItem != NULL)
		{
			cout << "found, " << *pItem << endl;
		}
		else
		{
			cout << "not found! " << endl;
		}
	}

}