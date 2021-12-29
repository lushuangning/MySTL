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
			c.push_back(string(buf));		//��һ���µ�Ԫ�ؼӵ�����棬λ��Ϊ��ǰ���һ��Ԫ�ص���һ��Ԫ��
		}
		catch(exception& p){
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds :" << (clock() - timeStart) << endl;
	cout << "vector.size()= " << c.size() << endl;		// �ж���Ԫ��
	cout << "vector.max_size()= " << c.max_size() << endl;		// list�����ɵ����Ԫ������
	cout << "vector.front()= " << c.front() << endl;	// ��һ��Ԫ��
	cout << "vector.back()= " << c.back() << endl;		// ���һ��Ԫ��

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);		// c.begin() Ŀǰʹ�ÿռ��ͷ��c.end() Ŀǰʹ�ÿռ��β
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
	c.sort();		// list�����Լ�Ҳ��sort��������ȫ�ֵ�sort��Ч�ʱ�ȫ��sortҪ��
	cout << "c.sort(), milli-seconds : " << (clock() - timeStart) << endl;
}