// C++20
// Adventure Island Token → Granted on Quest Completion
#include <iostream>
using namespace std;

int main()
{
	bool questComplete = false;
	bool tokenReceived = false;

	for (int t = 0; t < 5; t++)
	{
		if (t == 3)
		{
			// 3틱에 과제 완료
			questComplete = true;

			if (questComplete && !tokenReceived)
			{
				tokenReceived = true;
				cout << "[보상 지급] 모험 섬 토근 획득!" << endl;
			}
			else
			{
				cout << "t=" << t << " 진행 중..." << endl;
			}
		}
	}
}
