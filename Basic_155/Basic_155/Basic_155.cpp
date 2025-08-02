// C++20
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;

struct FPalCharacter
{
    float MaxStamina = 100.0f;
    float Stamina = 100.0f;

    float RunStaminaCostPerSec = 10.0f;
    float RecoverRatePerSec = 5.0f;

    bool bIsRunning = false;

    void Tick(float DeltaTime)
    {
        if (bIsRunning)
        {
            Stamina -= RunStaminaCostPerSec * DeltaTime;
            if (Stamina <= 0.0f)
            {
                Stamina = 0.0f;
                bIsRunning = false;
                cout << "[LOG] 스태미나 부족으로 달리기를 멈춥니다." << endl;
            }
        }
        else
        {
            Stamina += RecoverRatePerSec * DeltaTime;
            if (Stamina > MaxStamina)
            {
                Stamina = MaxStamina;
            }
        }
    }

    void SetRunning(bool bRun)
    {
        if (bRun && Stamina <= 0.0f)
        {
            cout << "[LOG] 스태미나가 부족하여 달릴 수 없습니다." << endl;
            return;
        }

        bIsRunning = bRun;
    }

    void PrintStatus()
    {
        cout << "현재 스태미나: " << round(Stamina) << " / " 
            << MaxStamina << endl;
    }
};

int main()
{
    FPalCharacter Pal;
    float DeltaTime = 1.0f;

    for (int i = 0; i < 20; ++i)
    {
        if (i == 2) Pal.SetRunning(true);  // 2초부터 달리기 시작
        if (i == 10) Pal.SetRunning(false); // 10초에 멈춤

        Pal.Tick(DeltaTime);
        Pal.PrintStatus();

        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return 0;
}
