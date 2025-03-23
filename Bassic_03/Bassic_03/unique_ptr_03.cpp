#include "unique_ptr_03.h"
#include <memory>
#include <iostream>
using namespace std;

// unique_ptr은 C++에서 제공하는 스마트 포인터의
// 한 종류입니다.
// 단일 소유권(single ownership) 기반의
// 메모리 관리 도구입니다.
// 일반적인 포인터는 new와 delete를 통해 수동으로
// 메모리 관리를 해야하지만,
// unique_ptr은 자동 메모리 관리를 통해
// 메모리 누수를 방지합니다.
int main()
{
	unique_ptr<int> ptr = make_unique<int>(10);
	cout << *ptr << endl;
}