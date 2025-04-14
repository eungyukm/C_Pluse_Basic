#include <iostream>
#include <unordered_map>
using namespace std;

// unordered_map
// 해시 기반이라 정렬은 안 되지만, map 보다
// 빠른 탐색 속도를 가짐.

int main()
{
	unordered_map<string, int> scores;
	scores["Alice"] = 90;
	scores["Bob"] = 85;
	scores["Charlie"] = 92;

	for (auto& [name, score] : scores)
	{
		cout << name << " : " << score
			<< "점\n";
	}

	if (scores.contains("Alice"))
	{
		cout << "Alice는 존재합니다."
			<< endl;
	}
}