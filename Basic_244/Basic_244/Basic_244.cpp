// C++20
#include <iostream>
using namespace std;

int main()
{
	const int openAt = 5; // 입장 시작
	const int closeAt = 9; // 입장 종료(미포함)

	bool canEnter = false;

	for (int t = 0; t < 12; t++)
	{
		canEnter = (t >= openAt && t < closeAt);

		cout << "t=" << t << (canEnter ?
			"[입장 가능]" : "[입장 불가") << endl;
	}

	int arrive = 7; // 플레이어가 도착한 시간
	cout << "도착 t=" << arrive++
		<< (arrive - 1 > openAt && arrive - 1 < closeAt
		? "-> 입장 성공" : " -> 입장 실패") << endl;
}
