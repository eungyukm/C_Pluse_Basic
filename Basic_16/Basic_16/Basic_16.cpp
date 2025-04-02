// Basic_16.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
using namespace std;

// 람다 캡처 (Lambda Capture)
// 람다 함수에서 외부 변수를 가져오는 방법입니다.
// [] 안에 변수를 넣어야 외부 값을 사용할 수 있습니다.

int main()
{
	int x = 5;
	auto func = [x]()
		{
			cout << "x = " << x << endl;
		};

	func();
}