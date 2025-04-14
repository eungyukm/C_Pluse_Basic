// Basic_38.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <deque>
using namespace std;

// deque
// 양쪽 끝에서 삽입/삭제가 모두 가능한 양방향
// 큐
// queue와 비슷하지만 더 유연함.

int main()
{
	deque<int> dq = { 1, 2, 3 };

	dq.push_back(0);
	dq.push_back(4);

	for (int n : dq)
	{
		cout << n << " ";
	}

	cout << endl;

	// 앞 제거
	dq.pop_front();
	// 뒤 제거
	dq.pop_back();

	cout << "[변경 후 출력]" << endl;

	for (int n : dq)
	{
		cout << n << " ";
	}

	cout << endl;
}