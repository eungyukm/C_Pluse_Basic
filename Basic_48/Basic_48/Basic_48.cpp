// C++20 기준
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums = { 5, 3, 4, 1 };

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size() - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}

	for (int n : nums)
	{
		cout << n << " ";
	}
}