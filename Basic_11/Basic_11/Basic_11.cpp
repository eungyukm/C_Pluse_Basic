// Basic_11.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
using namespace std;

// 익명 함수는 이름 없는 함수를 말합니다.
// 함수 포인터보다 간단하고 유연하게 사용할 수 있습니다.
// 함수 처럼 변수에 저장하고 인자로 전달할 수 있습니다.

auto add = [](int a, int b)
	{
		return a + b;
	};

int main()
{
	cout << add(3, 5) << endl;
}