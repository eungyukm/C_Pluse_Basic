#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(0));

	int evasionChance = 30;
	int damage = 30;

	int roll = rand() % 100;
	if (roll < evasionChance)
	{
		cout << "회피 성공! 피해 없음" <<
			endl;
	}
	else
	{
		cout << "피격! " << damage << " 데미지"
			<< endl;
	}
}
