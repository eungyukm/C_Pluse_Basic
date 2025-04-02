// Basic_21.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
using namespace std;

// detach()는 쓰레드를 분리해서 백그라운드로 실행합니다.
void backgroundTask()
{
    cout << "Doing background work..." << endl;
}

int main()
{
    thread t(backgroundTask);
    t.detach(); // 메인 쓰레드랑 독립 실행

    // 백그라운드 작업 기다리기
    this_thread::sleep_for(chrono::seconds(1));
}