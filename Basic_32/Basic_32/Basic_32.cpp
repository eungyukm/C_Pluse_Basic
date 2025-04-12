// Basic_32.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 1, 2, 3 };

	nums.push_back(4);
	nums[0] = 10;

	for (auto n : nums )
	{
		cout << n << " ";
	}
	cout << endl;
}