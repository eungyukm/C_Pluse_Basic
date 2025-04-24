#include <iostream>
#include <span>
#include <vector>
using namespace std;

// span
// 배열이나 vector등을 포인터처럼
// 얇게 참조할 수 있음.

void print(span<int> s)
{
	for (int n : s)
	{
		cout << n << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	print(arr);

	vector<int> v = { 6, 7, 8 };
	print(v);
}