#include <iostream>
using namespace std;

int main()
{
	// auto 키워드
	// 컴파일러가 변수의 타입을 추론하도록 하여 코드 작성 시
	// 타입 명시하지 않아도 됩니다.
	auto number = 10;
	cout << number << endl;

	auto text = std::string("Hello");
	
	cout << text << endl;
}