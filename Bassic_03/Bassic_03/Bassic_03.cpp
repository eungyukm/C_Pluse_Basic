#include <iostream>
#include <memory>
using namespace std;

// move는 C++에서 소유권을 이전하거나 자원을 이동할 때
// 사용하는 함수입니다.

// 주로 복사가 아닌 이동(이전)을 통해 불필요한
// 복사를 방지하고 성능을 개선하기 위해 사용됩니다.
//int main()
//{
//	// 10 할당
//	auto ptr = make_unique<int>(10);
//	cout << *ptr << endl;
//
//	// 소유권 이전 기능
//	auto newPtr = move(ptr);
//	cout << *newPtr << endl;
//}
