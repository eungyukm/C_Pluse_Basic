// C++20
#include <iostream>
using namespace std;

int main()
{
	// 개방 시각
	const int openAt = 5;
	// 개발 유지 시간
	const int duration = 3;
	bool gateOpen = false;

	for (int t = 0; t < 12; t++)
	{
		gateOpen = (t >= openAt && t < openAt + duration);

		if (gateOpen)
		{
			cout << "t=" << t << "[카오스 게이트 개발] 입장 가능"
				<< endl;
		}
		else
		{
			cout << "t=" << t << "대기 중" << endl;
		}
	}
}
