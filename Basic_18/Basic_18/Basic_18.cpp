// Basic_18.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
using namespace std;

// 람다 함수로 쓰레드 실행
int main()
{
	thread t([]() {
		cout << "Hello from lambda thread!" << endl;
		});

	t.join();
}