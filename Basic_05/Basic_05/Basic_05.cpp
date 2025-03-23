#include <iostream>
using namespace std;

// const는 상수를 정의할 때 사용합니다.
// 상수는 한번 값이 설정되면 변경할 수 없게 되며,
// 이는 코드에서 실수를 방지하는 데 유용합니다.

int main()
{
	// number는 이제 변경할 수 없습니다.
	const int number = 10;
	cout << number << endl;

	// 컴파일 에러 발생
	//number = 20;

}