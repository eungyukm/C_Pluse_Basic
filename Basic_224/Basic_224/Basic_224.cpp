// C++20
#include <iostream>
#include <random>
using namespace std;

struct Player
{
    int stamina{ 10 };
    int meat{ 0 }, leather{ 0 }, bone{ 0 };
};

struct Bow
{
    int durability{ 6 };
    bool usable() const
    {
        return durability > 0;
    }
};

bool TryHunting(Player& p, Bow& b, mt19937& rng)
{
    if (!b.usable() || p.stamina <= 0) return false;

    p.stamina -= 2;
    b.durability--;

    uniform_real_distribution<float> u(0.0f, 1.0f);
    if (u(rng) > 0.6f)
    {
        return false;
    }

    float r = u(rng);
    if (r < 0.6f)
    {
        p.meat++;
    }
    else if (r < 0.9f)
    {
        p.leather++;
    }
    else
    {
        p.bone++;
    }
    return true;
}

int main()
{
    mt19937 rng(random_device{}());
    Player you;
    Bow bow;

    for (int i = 0; i < 8; i++)
    {
        bool ok = TryHunting(you, bow, rng);
        cout << (ok ? "수렵 성공! " : "실패... ")
            << "고기:" << you.meat
            << " 가죽:" << you.leather
            << " 뼈:" << you.bone
            << " | 스태미나:" << you.stamina
            << " 활내구도:" << bow.durability << '\n';
    }
}
