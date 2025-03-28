// Basic_09.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

// 함수 포인터 배열로 여러 함수 관리
void hello()
{
    cout << "Hello" << endl;
}

void bye()
{
    cout << "Bye" << endl;
}

int main()
{
    // 함수 포인터 배열
    void (*funcs[2])() = { hello, bye };

    for (int i = 0; i < 2; i++)
    {
        // 순서대로 hello, bye 호출
        funcs[i]();
    }
}