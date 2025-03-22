// Bassic_03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

using namespace std;
int main()
{
    // 10 할당
    auto ptr = make_unique<int>(10);
    cout << *ptr << endl;

    // 소유권 이전 기능
    auto newPtr = move(ptr);
    cout << *newPtr << endl;
}
