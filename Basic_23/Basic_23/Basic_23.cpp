// Basic_23.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// 쓰레드 사용 시 lock()과 unlock() 대신
// 간편한 lock_guard
// RAll 방식으로 자동 잠금/해제 합니다.

int counter = 0;
mutex m;

void add()
{
	for (int i = 0; i < 10000; i++)
	{
		// 블록을 벗어나면 자동으로 unlock
		lock_guard<mutex> lock(m);
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