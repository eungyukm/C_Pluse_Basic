#include <iostream>
#include <memory>
using namespace std;

// shared_ptr은 C++에서 제공하느 스마트 포인터로,
// 복수의 포인터가 같은 객체를 고유할 수 있게 해줍니다.
// 객체에 대한 참조 카운트를 유지하여,
// 더 이상 객체를 참조하는 포인터가 없을 때
// 자동으로 메모리를 해제 합니다.
int main()
{
	shared_ptr<int> ptr1 = make_shared<int>(10);
	cout << *ptr1 << endl;

	shared_ptr<int> ptr2 = ptr1;
	cout << *ptr2 << endl;
}
