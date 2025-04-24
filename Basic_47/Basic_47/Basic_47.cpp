// C++20 기준
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 3, 5, 7, 8 };
	int target = 7;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
		{
			cout << "찾았다! " <<
				i << endl;
			return 0;
		}
	}
	cout << "못 찾음!" << endl;
}

