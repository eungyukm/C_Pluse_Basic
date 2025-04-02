// Basic_15.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}
    void print()
    {
        cout << "Value: " << value << endl;
    }
};
int main()
{
    Box<int> intBox(10);
    Box<string> strBox("Hello");

    intBox.print();
    strBox.print();
}