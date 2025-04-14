// Basic_39.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

// priority_queue
// 자동으로 가장 큰 값부터 꺼내는 힙 구조
// 기본적으로 최댓값 우선 큐.

int main()
{
	priority_queue<int> pq;

	pq.push(30);
	pq.push(10);
	pq.push(50);

	while (!pq.empty())
	{
		cout << pq.top() << " "; // 가장 큰 값
		pq.pop();
	}

	cout << endl;
}