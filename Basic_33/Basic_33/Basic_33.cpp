#include <iostream>
#include <map>

using namespace std;

// C++20 기준으로 작성됩니다.

int main()
{
	map<string, int> people{
		{"Alice", 30},
		{"Bob", 25}
	};

	people["Charlie"] = 28;

	for (auto& [name, age] : people)
	{
		cout << name << " : " << age <<
			"세\n";
	}

	if (people.contains("Bob"))
	{
		cout << "\nBob은 존재합니다. \n";
	}

	people.erase("Alice");

	cout << "\n[Alice 삭제 후]\n";

	for (auto& [name, age] : people)
	{
		cout << name << " : " << age
			<< "세\n";
	}
}
