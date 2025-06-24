// C++20
#include <iostream>
#include <string>
#include <random>

using namespace std;
struct Pal
{
	string name;
	float size = 1.0f;
	int power = 10;

	void Show()
	{
		cout << "Pal: " << name << ", size: "
			<< size << ", Power: " << power << endl;
	}
};

Pal SpawnPal()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100);

	bool isRare = (dis(gen) <= 1);

	if (isRare)
	{
		return { "Rare Pal", 1.5f, 30 };
	}
	else
	{
		return { "Normal Pal", 1.0f, 10 };
	}
}

int main()
{
	Pal pal = SpawnPal();
	pal.Show();
}