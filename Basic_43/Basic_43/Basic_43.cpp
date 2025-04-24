#include <iostream>
#include <array>
using namespace std;

// array
// vector와 비슷하지만 정적 크기를 가지는
// 배열.
// 컴파일 타임에 크기가 고정되어 있어
// 메모리 성능이 좋음
int main()
{
    array<int, 5> arr = { 1, 2, 3, 4, 5 };

    for (auto n : arr)
    {
        cout << n << " ";
    }
    cout << endl;

    arr[0] = 10;
    cout << "첫 번째 값: " << arr.front()
        << endl;

    cout << "마지막 값: " << arr.back()
        << endl;
}