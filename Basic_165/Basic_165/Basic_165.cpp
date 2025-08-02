// C++20
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class APalCharacter
{
public:
    bool bIsInvincible = false;
    bool bIsRolling = false;

    float RollingDuration = 0.8f; // 구르기 시간 (초)
    chrono::steady_clock::time_point RollingStartTime;

    void StartRoll()
    {
        if (bIsRolling)
            return;
        bIsRolling = true;
        bIsInvincible = true;
        RollingStartTime = chrono::steady_clock::now();
        
        cout << "[ROLL] 구르기 시작! 무적 상태 ON" << endl;
    }

    void Update()
    {
        if (!bIsRolling)
            return;

        auto now = chrono::steady_clock::now();
        float elapsed = chrono::duration<float>(now - RollingStartTime).count();

        if (elapsed >= RollingDuration)
        {
            bIsRolling = false;
            bIsInvincible = false;  
            cout << "[ROLL] 구리기 종료. 무적 상태 OFF" << endl;
        }
    }

    void TakeDamage(int damage)
    {
        Update(); // 매 데미지 시도마다 상태 갱신

        if (bIsInvincible)
        {
            cout << "[HIT] 무적 상태! 피해 없음" << endl;
            return;
        }

        cout << "[HIT]" << damage << " 피해를 입었습니다." << endl;
    }
};

int main()
{
    APalCharacter player;

    player.StartRoll();

    this_thread::sleep_for(chrono::milliseconds(300));
    player.TakeDamage(30); // 무적 상태

    this_thread::sleep_for(chrono::milliseconds(600));
    player.TakeDamage(40); // 무적 끝난 후 피해

    return 0;
}
