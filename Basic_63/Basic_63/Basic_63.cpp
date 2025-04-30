// C++17
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<string> turnQueue;
	turnQueue.push("Player");
	turnQueue.push("Monster");

	for (int i = 0; i < 4; ++i)
	{
		string current = turnQueue.front();
		turnQueue.pop();
		cout << current << "'s Turn!" << endl;

		// 행동 처리
		if (current == "Player")
		{
			cout << "Player attacks!" << endl;
		}
		else
		{
			cout << "Monset bites" << endl;
		}

		// 다시 맨 뒤로
		turnQueue.push(current);
	}
}