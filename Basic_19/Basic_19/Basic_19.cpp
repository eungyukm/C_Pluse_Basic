// Basic_19.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
using namespace std;

// 쓰레드에서 인자 전달하기
void printNum(int x)
{
	cout << "Number: " << x << endl;
}
int main()
{
	thread t(printNum, 42);
	t.join();
}