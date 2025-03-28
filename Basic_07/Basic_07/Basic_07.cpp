// Basic_07.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

// 함수 포인터는 함수를 변수처럼 전달하거나
// 저장할 수 있습니다.

void sayHello()
{
	cout << "Hello!" << endl;
}

void callFunc(void (*func)())
{
	func();
}
int main()
{
	callFunc(sayHello);
}