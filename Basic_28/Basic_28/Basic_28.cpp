// Basic_28.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
// condition_variable
// 스레드 간의 조건 기다리기/깨우기를 구현할
// 수 있는 도구입니다.
// 주로 생산자/소비자(Producer/Consumer)
// 패턴에서 사용됩니다.
// 어떤 조건이 만족될 때까지 기다리게 할 수
// 있습니다.
mutex m;
condition_variable cv;
bool ready = false;

void worker()
{
	unique_lock<mutex> lock(m);
	cv.wait(lock, [] {return ready; });
	cout << "thread is running!" << endl;
}
int main()
{
	thread t(worker);

	this_thread::sleep_for(chrono::seconds(3));
	{
		lock_guard<mutex> lock(m);
		ready = true;
	}
	cv.notify_one();
	t.join();
}
