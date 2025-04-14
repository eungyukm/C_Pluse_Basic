// Basic_36.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

// stack
// LIFO(Last-In First Out) 구조.
// 가장 나중에 넣은 값이 먼저 나옵니다.

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty())
	{
		cout << "Top: " << s.top() << endl;
		s.pop();
	}
}