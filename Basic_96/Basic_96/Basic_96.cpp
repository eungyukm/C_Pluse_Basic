// C++20 기준
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pal
{
	string name;
	int friendship = 0;
	string status = "Acquaintance";

	void WorkTogether()
	{
		friendship += 10;
		if (friendship >= 50)
		{
			status = "Best Friend";
		}
	}

	void ShowStatus() const
	{
		cout << name << " - Friendship : " << friendship
			<< ", Status: " << status << endl;
	}
};
int main()
{
	Pal palA{ "Lamball" };
	Pal palB{ "Anubis" };

	cout << "== Startworking Together ==" << endl;
	for (int day = 1; day <= 6; day++)
	{
		cout << "Day " << day << ": ";
		palA.WorkTogether();
		palB.WorkTogether();
		palA.ShowStatus();
		palB.ShowStatus();
	}
}
