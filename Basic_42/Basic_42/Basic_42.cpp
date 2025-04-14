#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
	forward_list<int> f1 = { 3, 2, 1 };

	f1.push_front(0);

	cout << "초기 상태 : " << endl;

	for (int n : f1)
	{
		cout << n << " ";
	}

	cout << endl;

	f1.remove(2);

	cout << "[2 제거 후 출력]" << endl;

	for (int n : f1)
	{
		cout << n << " ";
	}

	cout << endl;
}