// C++20
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

class FPalEntity
{
public:
    float MaxShield = 100.0f;
    float CurrentShield = 50.0f;
    float ShieldRegenPerSecond = 5.0f;
    float ShieldRegenDelaySeconds = 3.0f;

private:
    float TimeSinceLastHit = 0.0f;
    bool bTookHitRecently = false;

public:
    void Tick(float DeltaTime)
    {
        if (bTookHitRecently)
        {
            TimeSinceLastHit = 0.0f;
            bTookHitRecently = false;
        }
        else
        {
            TimeSinceLastHit += DeltaTime;

            if (TimeSinceLastHit >= ShieldRegenDelaySeconds)
            {
                CurrentShield += ShieldRegenPerSecond * DeltaTime;
                CurrentShield = min(CurrentShield, MaxShield);
            }
        }
    }

    void OnHit()
    {
        bTookHitRecently = true;
        cout << ">> 피격! 실드 재생 대기 시작\n";
    }

    void PrintShield()
    {
        cout << "실드: " << CurrentShield << endl;
    }
};
int main()
{
    FPalEntity player;

    float SimulateTime = 10.0f;
    float TickRate = 0.1f;

    for (float t = 0.0f; t <= SimulateTime; t += TickRate)
    {
        if ((int)t == 2) player.OnHit(); // 2초에 피격 발생
        player.Tick(TickRate);
        player.PrintShield();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}