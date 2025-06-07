// C++20 기준
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pal
{
    string name;
    int health = 100;
    int hunger = 0; // 0~100

    void Tick()
    {
        hunger = min(hunger + 5, 100); // 허기 증가

        if (hunger >= 60)
        {
            health -= 5;
            cout << name << " is starving! (-5 HP)" << endl;
        }
        ShowStatus();
    }

    void EatFood(int foodAmount)
    {
        if (hunger == 0)
        {
            cout << name << " is not hungry." << endl;
            return;
        }

        hunger = max(hunger - foodAmount, 0);
        cout << name << " ate some food. (-" << foodAmount << " Hunger)\n";
    }

    void ShowStatus() const
    {
        cout << name << " | Health: " << health
            << " | Hunger: " << hunger << endl;
    }
};

int main()
{
    Pal lamball{ "Lamball" };

    for (int tick = 1; tick <= 10; ++tick)
    {
        cout << "\n== Tick " << tick << " ==\n";
        lamball.Tick();

        // 3틱마다 음식 먹기
        if (tick % 3 == 0)
        {
            lamball.EatFood(20);
        }
    }

    return 0;
}