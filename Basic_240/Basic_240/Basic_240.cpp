// C++20
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> contrib = { 2, 4, 2 }; // 유저별 기여도
	int target = 8, sum = 0;

	for (int c : contrib)
	{
		sum += c;
	}

	if (sum >= target)
	{
		cout << "[협동 미션 완료]" << endl;
		for (int i = 0; i < contrib.size(); i++)
		{
			cout << "유저" << i + 1 << " 보상 +"
				<< contrib[i] * 10 << "골드" << endl;
		}
	}
	else
	{
		cout << "[실패] 목표 미달 (" << sum << "/"
			<< target << ")" << endl;
	}

}
