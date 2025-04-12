// Basic_26.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// unique_lock
// lock_gurad보다 유연한 락 도구입니다.
// lock_gurad는 생성과 동시에 lock()
// 소멸 시 unlock()으로 고정된 반면,
// unique_lock은 lock/unlock을 수동 제어하거나
// 지연(lock later) 타임아웃 기반 락도
// 지원합니다.

int counter = 0;
mutex m;

void add()
{
	for (int i = 0; i < 1000; i++)
	{
		unique_lock<mutex> loc(m);
		++counter;
	}
}
int main()
{
	thread t1(add);
	thread t2(add);

	t1.join();
	t2.join();

	cout << "Counter : " << counter << endl;
}