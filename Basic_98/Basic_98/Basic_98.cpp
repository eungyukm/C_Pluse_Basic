// C++20 기준
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pal
{
	string name;
	int level = 1;
	int xp = 0;
	bool evolved = false;

	void GainXP(int amount)
	{
		xp += amount;
		while (xp >= 50)
		{
			xp -= 50;
			level++;
			if (level >= 5 && !evolved)
			{
				evolved = true;
				cout << name << " has evolved!" << endl;
			}
		}
	}
	void ShowStatus() const
	{
		cout << name << " - Level: " << level
			<< ", XP: " << xp
			<< ", Evolved: " << (evolved ? "Yes" : "No") << endl;
	}
};

int main()
{
	Pal pal{ "Foxparks" };

	for (int day = 1; day <= 6; day++)
	{
		cout << "== Day " << day << " == " << endl;
		pal.GainXP(30);
		pal.ShowStatus();
		cout << endl;
	}
}
