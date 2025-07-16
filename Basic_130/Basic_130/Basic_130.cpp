// C++20
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pal
{
    string name;

    int fatigue = 0; // 피로 (0~100)
    int hunger = 0;  // 허기 (0~100)
    int san = 100;   // SAN (0~100)

    // 상태 출력 함수
    void PrintStatus(const string& title)
    {
        cout << "== " << title << " ==" << endl;
        cout << "Name    : " << name << endl;
        cout << "Fatigue : " << fatigue << endl;
        cout << "Hunger  : " << hunger << endl;
        cout << "SAN     : " << san << endl;
        cout << "-------------------------" << endl;
    }

    // 1틱 진행 함수
    void Tick()
    {
        fatigue = min(100, fatigue + 5);
        hunger = min(100, hunger + 5);

        if (fatigue >= 80 || hunger >= 80)
        {
            san = max(0, san - 5);
            cout << "[Warning] " << name << "'s SAN decreased to " << san << endl;
        }
    }

    // 온천 사용 함수
    void UseHotSpring()
    {
        fatigue = max(0, fatigue - 30);
        hunger = max(0, hunger - 20);
        san = min(100, san + 20);

        cout << name << " used the hot spring. SAN recovered to" << san << endl;
    }
};

int main()
{
    Pal pal{ "Pengullet" };

    // 초기 상태 출력
    pal.PrintStatus("Initial Status");

    // 5틱 진행
    for (int t = 0; t < 5; t++)
    {
        cout << "\n[Tick " << t + 1 << "]" << endl;
        pal.Tick();
        pal.PrintStatus("Current Status");
    }

    // 온천 사용
    cout << "\n[Hot Spring]" << endl;
    pal.UseHotSpring();
    pal.PrintStatus("After Hot Spring");
}
