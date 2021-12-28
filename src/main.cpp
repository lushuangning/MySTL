#include <iostream>
#include <string>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<string> c;
	c.push_front("aaa");
	c.push_front("bbb");
	c.push_front("ccc");
	cout << "c.front(): " << c.front();
	return 0;
}