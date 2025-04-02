// Basic_17.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
using namespace std;

// 쓰레드에서 실행할 함수
void sayHello()
{
	cout << "Hello from thread!" << endl;
}

int main()
{
	// 새로운 쓰레드 시작
	thread t(sayHello);
	t.join();
	cout << "Main thread done!" << endl;
}