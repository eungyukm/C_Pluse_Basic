// C++20 기준
#include <iostream>
#include <string>

using namespace std;

struct Pal
{
	string name;
	int hp;
	int atk;

	bool IsAlive() const
	{
		return hp > 0;
	}

	void Attack(Pal& target)
	{
		target.hp -= atk;
		cout << name << " attacks " << target.name
			<< " for " << atk << " damage! ("
			<< target.hp << " HP left)" << endl;
	}
};
int main()
{
	Pal a{ "Pyron", 100, 25 };
	Pal b{ "Aquan", 80, 20 };

	while (a.IsAlive() && b.IsAlive())
	{
		a.Attack(b);
		if (!b.IsAlive())
		{
			break;
		}

		b.Attack(a);
	}

	cout << (a.IsAlive() ? a.name : b.name)
		<< " wins!" << endl;
}
