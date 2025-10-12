// C++20
#include <iostream>
#include <random>
using namespace std;

struct Player
{
    int stamina = 10;
    int wood = 0;
};

struct Tool
{
    int durability = 5;
    bool usable()
    {
        return durability > 0;
    }
};

bool TryLogging(Player& p, Tool& t, mt19937& rng)
{
    if (!t.usable() || p.stamina <= 0)
    {
        return false;
    }

    uniform_real_distribution<float> dist(0.0f, 1.0f);
    float successRate = 0.65f;
    int staminaCost = 2;

    p.stamina -= staminaCost;
    t.durability--;

    if (dist(rng) <= successRate)
    {
        p.wood++;
        return true;
    }

    return false;
}

int main()
{
    mt19937 rng(random_device{}());
    Player you;
    Tool axe;

    for (int i = 0; i < 8; i++)
    {
        bool ok = TryLogging(you, axe, rng);
        cout << (ok ? "벌목 성공! " : "실패... ")
            << "나무: " << you.wood
            << ", 스태미나: " << you.stamina
            << ", 도끼 내구도: " << axe.durability << '\n';
        i++;
    }
}
