// Basic_13.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

// 함수나 클래스를 다양한 타입에 대해 재사용할 수 있게
// 해주는 기능입니다.
// 중복 코드를 줄이고 유연한 프로그래밍이 가능하게 합니다.

template <typename T>
T add(T a, T b)
{
	return a + b;
}
int main()
{
	cout << add<int>(3, 4) << endl;
	cout << add<double>(3.1, 4.2) << endl;
}