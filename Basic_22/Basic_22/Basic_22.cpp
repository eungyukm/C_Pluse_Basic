// Basic_22.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// mutex란?
// 여러 스레드가 동시에 자원(변수 등)에 접근하지
// 못하도록 막아주는 도구입니다.
int counter = 0;
// mutex 선언
mutex m;

void add()
{
	for (int i = 0; i < 10000; i++)
	{
		// 잠금
		m.lock();
		++counter;
		// 잠금 해제
		m.unlock();
	}
}
int main()
{
	thread t1(add);
	thread t2(add);

	t1.join();
	t2.join();

	cout << "Couter: " << counter << endl;
}