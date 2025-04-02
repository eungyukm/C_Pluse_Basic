// Basic_14.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
using namespace std;

// 템플릿은 여러 타입에 쓸 수 있습니다.
// 특정 타입에 대해 다르게 동작하도록 만들 수 있습니다.

template <typename T>
void printType()
{
	cout << "일반 타입입니다." << endl;
}

// int에 대한 특수화
template <>
void printType<int>()
{
	cout << "int 타입입니다!" << endl;
}

int main()
{
	// 일반 타입입니다.
	printType<double>();

	// int 타입입니다.
	printType<int>();
}