// C++20
#include <iostream>
#include <thread>

using namespace std;

struct FieldEvent
{
    int StartHour;
    int StartMinute;
    int CurHour = 0;
    int CurMinute = 0;
    bool IsStarted = false;

    void Tick()
    {
        if (IsStarted)
        {
            return;
        }

        if (CurHour == StartHour && CurMinute == StartMinute)
        {
            Start();
        }

        AdvanceTime();
    }

    void AdvanceTime()
    {
        CurMinute++;
        if (CurMinute >= 60)
        {
            CurMinute = 0;
            CurHour++;
            if (CurHour >= 24)
            {
                CurHour = 0;
            }
        }
    }

    void Start()
    {
        IsStarted = true;
        cout << "[FieldEvent] 가상 시간 " 
            << CurHour << ":" << CurMinute
            << " → 이벤트 시작!" << endl;
    }
};

int main()
{
    FieldEvent event{ 0, 10 };

    while (!event.IsStarted)
    {
        event.Tick();
        cout << "현재 가상 시간: "
            << event.CurHour << ":" << event.CurMinute << endl;
        this_thread::sleep_for(100ms);
    }
}
