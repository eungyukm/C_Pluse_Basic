#include <iostream>
#include <set>
using namespace std;

// multiset
// set과 비슷하지만 중복된 값 저장 가능.

int main()
{
	multiset<int> nums = { 1, 2, 2, 3, 3,3 };

	for (int n : nums)
	{
		cout << n << " ";
	}

	cout << endl;

	// 모든 2 제거
	nums.erase(2);

	cout << "[2 제거 후]" << endl;

	for (int n : nums)
	{
		cout << n << " ";
	}
	cout << endl;
}