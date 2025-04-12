// Basic_29.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <future>
using namespace std;

// async는 자동으로 백그라운드 스레드에서 실행
// future는 결과를 나중에 받아올 수 있음

int slow_add()
{
	this_thread::sleep_for(chrono::seconds(2));
	return 42;
}
int main()
{
	future<int> result = async(slow_add);
	cout << "Doing other work.." << endl;
	cout << "Result: " << result.get() << endl;
}