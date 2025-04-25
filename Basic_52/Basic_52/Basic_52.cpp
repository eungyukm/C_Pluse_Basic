#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(0));

	int upgradeChance = 40;
	int level = 0;

	int roll = rand() % 100;
	if (roll < upgradeChance)
	{
		level++;
		cout << " 강화 성공! + (레벨 :"
			<< level << " )" << endl;
	}
	else
	{
		cout << " 강화 실패!" << endl;
	}
}