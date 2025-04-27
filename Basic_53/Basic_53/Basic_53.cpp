#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(0));

	int monsters = 5;
	cout << "몬스터 처치 시작!" << endl;

	for (int i = 0; i < monsters; i++)
	{
		cout << "\n" << i << "번째 몬스터 처치\n";

		int roll = rand() % 100;

		if (roll < 50)
		{
			cout << "일반 아이템 드랍!" << endl;
		}
		else if (roll < 80)
		{
			cout << "희귀 아이템 드랍!" << endl;
		}
		else
		{
			cout << "전설 아이템 드랍!" << endl;
		}
	}
}
