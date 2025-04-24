#include <iostream>
#include <map>
using namespace std;

// multimap
// map과 비슷하지만 중복 key를 허용하는
// 컨테이너.

int main()
{
	multimap<string, int> grades;
	grades.insert({ "Alice", 90 });
	grades.insert({ "Bob", 85 });
	grades.insert({ "Alice", 95 });

	for (auto& [name, score] : grades)
	{
		cout << name << " : " << score
			<< endl;
	}
}
