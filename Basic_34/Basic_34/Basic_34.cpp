// Basic_34.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// C++20 기준으로 작성됩니다.
#include <iostream>
#include <set>

using namespace std;

// set은 중복을 허용하지 않고 정렬된 순서로
// 값을 저장하는 컨테이너 입니다.
int main()
{
	set<int> numbers = { 3, 1, 4, 1, 2, 5 };

	// 중복된 1을 무시됨
	for (auto n : numbers)
	{
		cout << n << " ";
	}

	cout << "\n";

	numbers.insert(6);
	numbers.erase(3);

	cout << "\n[변경 후 출력]\n";

	for (auto n : numbers)
	{
		cout << n << " ";
	}

	cout << endl;
}