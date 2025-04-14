// Basic_40.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_set>
using namespace std;

// unordered_set
// set과 비슷하지만 정렬되지 않음, 대신 빠름
// 중복 없는 데이터 저장할 때 유용함.

int main()
{
	unordered_set<string> fruits =
	{
		"Apple", "Banana", "Apple", "Cherry"
	};

	for (auto& fruit : fruits)
	{
		cout << fruit << " ";
	}
	cout << endl;

	fruits.insert("Orange");
	fruits.erase("Banana");

	cout << "[변경 후 출력]" << endl;
	for (auto& fruit : fruits)
	{
		cout << fruit << " ";
	}
	cout << endl;
}