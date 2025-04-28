#include <iostream>
#include <vector>

using namespace std;

int CalculateLevel(int totalExp,
	const vector<int>& expThresholds)
{
	int level = 1;
	for (const auto& threshold : expThresholds)
	{
		if (totalExp >= threshold)
		{
			level++;
		}
		else
		{
			break;
		}
		return level;
	}
}
int main()
{
	vector<int> expThresholds =
	{ 0, 100, 300, 600, 1000 };

	int currentExp = 450;
	int level = CalculateLevel(currentExp, expThresholds);
	cout << "Current Level:" << level << endl;
}
