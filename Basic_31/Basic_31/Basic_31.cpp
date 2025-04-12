// Basic_31.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <future>
using namespace std;

// promise
// promise는 값을 나중에 설정할 수 있는 객체
// 설정된 값은 future를 통해 다른 스레드에서
// 일륵 수 있습니다.
// 즉, 한 스레드에서 결과를 만들어서,
// 다른 스레드로 넘겨주는 구조

void calcuate(promise<int> prom)
{
	this_thread::sleep_for(chrono::seconds(2));
	int result = 100;
	prom.set_value(result);
}
int main()
{
	promise<int> prom;
	future<int> fut = prom.get_future();

	thread t(calcuate, move(prom));

	cout << "Doing other stuff in main..\n";

	int value = fut.get();
	cout << "Result from thread: "
		<< value << endl;

	t.join();
}