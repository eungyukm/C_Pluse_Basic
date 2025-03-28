// Basic_10.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    return a * b;
}

int operate(int x, int y, int (*func)(int, int))
{
    return func(x, y);
}

int main()
{
    int result = operate(3, 4, multiply);
    cout << "Result: " << result << endl;
}