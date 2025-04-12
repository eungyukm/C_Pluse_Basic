#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// thread_local
// 스레드마다 독립적인 로컬 변수를 만들고
// 싶을 때 사용 전역 변수처럼 보이지만,
// 스레드마다 별도 복사본을 가짐
// 주로 로그, 임시 버퍼, 스레드별 상태 관리
// 등에 사용

thread_local int local_counter = 0;
mutex cout_mutex;

void work()
{
	for (int i = 0; i < 3; ++i)
	{
		++local_counter;
		// 출력 전체를 하나의 락으로 보호
		{
			lock_guard<mutex> lock(cout_mutex);
			cout << "Thread "
				<< this_thread::get_id()
				<< " counter: "
				<< local_counter
				<< endl;
		}
	}
}
int main()
{
	thread t1(work);
	thread t2(work);

	t1.join();
	t2.join();
}
