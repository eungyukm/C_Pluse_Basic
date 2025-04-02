// Basic_20.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
using namespace std;

// 여러 개의 쓰레드 실행
void task(int id)
{
    cout << "\nThread " << id << " is working\n";
}
int main()
{
    thread t1(task, 1);
    thread t2(task, 2);

    t1.join();
    t2.join();
}