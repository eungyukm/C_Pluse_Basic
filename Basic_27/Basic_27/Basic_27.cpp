// Basic_27.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

// atomic
// mutex 없이도 동기화된 변수 접근이 가능하게
// 해주는 도구입니다.
// 기본 타입만 사용 가능 (int, bool 등)
// 성능이 더 좋고 코드도 간결함

atomic<int> counter(0);

void add()
{
	for (int i = 0; i < 10000; i++)
	{
		++counter;
	}
}
int main()
{
	thread t1(add);
	thread t2(add);

	t1.join();
	t2.join();

	cout << "Counter: " << counter << endl;
}