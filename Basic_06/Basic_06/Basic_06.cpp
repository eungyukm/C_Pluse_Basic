#include <iostream>
using namespace std;

// constexpr는 컴파일 타임에 값이 결정되는 상수를
// 정의한는 데 사용됩니다.
constexpr int square(int x) { return x * x; }

int main()
{
	constexpr int value = 5;
	cout << square(value) << endl;
}