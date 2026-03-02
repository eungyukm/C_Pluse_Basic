// C++20
#include <iostream>
using namespace std;

struct Pet
{
	string name;
	int favor{ 0 };
	int maxFavor{ 5 };

	bool Care()
	{
		if (favor >= maxFavor)
		{
			cout << name << "은(는) 이미 최고 호감도입니다.\n";
			return false;
		}
		favor++;
		cout << name << " 돌봄! 호감도: " << favor
			<< " / " << maxFavor << '\n';
		return true;
	}
};

int main()
{
	Pet pet{ "루루" };
	while (pet.Care()) {}
	return 0;
}
