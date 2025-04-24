#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(0));

	int critChance = 20;
	int baseDmg = 10;
	int totalDmg = 0;

	for (int i = 1; i <= 10; i++)
	{
		int roll = rand() % 100;
		int dmg = baseDmg;

		cout << i << " 번째 공격 : ";

		if (roll < critChance)
		{
			dmg *= 2;
			cout << "크리티컬";
		}
		else
		{
			cout << "일반 공격!";
		}
		cout << dmg << "데미지\n";
		totalDmg += dmg;
	}

	cout << "\n 총 누적 데미지 : "
		<< totalDmg << endl;
}