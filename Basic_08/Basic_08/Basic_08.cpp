// Basic_08.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void add(int a, int b)
{
	cout << "Add: " << (a + b) << endl;
}

void subtract(int a, int b)
{
	cout << "Subtract: " << (a - b) << endl;
}
int main()
{
	// 함수 포인터 선언
	void (*operation)(int, int);

	operation = add;
	operation(10, 5);

	operation = subtract;
	operation(10, 5);

	return 0;
}
