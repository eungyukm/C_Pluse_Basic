// Basic_12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>
using namespace std;

// std::function
// 함수 포인터, 람다, 일반 함수, 멤버 함수 모두를 받을 수
// 있는 범용 함수 타입입니다.
// #inclue<functional>이 필요합니다.
// 타입 안정성과 유연성 모두 챙길 수 있습니다.

int main()
{
	function<int(int, int)> function =
		[](int a, int b)
		{
			return a * b;
		};
	cout << function(2, 3) << endl;
}