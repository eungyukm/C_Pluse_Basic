// Basic_41.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
using namespace std;

// list
// 양방향 연결 리스트
// 중간 삽입/삭제가 vector보다 효율적

int main()
{
	list<int> nums = { 1, 2, 3 };

	nums.push_front(0);
	nums.push_back(4);

	for (int n : nums)
	{
		cout << n << " ";
	}

	cout << endl;

	nums.remove(2);

	cout << "[제거 후 출력]" << endl;

	for (int n : nums)
	{
		cout << n << " ";
	}

	cout << endl;
}