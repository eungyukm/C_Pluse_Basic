// Basic_37.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

// queue
// FIFO(First-In First-Out) 구조.
// 먼저 넣은 값이 먼저 나옵니다.

int main()
{
	queue<string> q;
	q.push("Apple");
	q.push("Banana");
	q.push("Cherry");

	while (!q.empty())
	{
		cout << "Front: " << q.front()
			<< endl;
		q.pop();
	}
}