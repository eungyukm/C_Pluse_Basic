// C++20
#include <iostream>
#include <random>
#include <string>
using namespace std;

enum class Ore { Iron, Silver, Gold };

struct Player 
{ 
    int stamina{ 10 };
    int iron{ 0 };
    int silver{ 0 };
    int gold{ 0 };
};
struct Pickaxe 
{ 
    int durability{ 6 };
    bool usable() const
    {
        return durability > 0;
    }
};

bool TryMining(Player& p, Pickaxe& px, mt19937& rng)
{
    if (!px.usable() || p.stamina <= 0)
    {
        return false;
    }

    p.stamina -= 2;
    px.durability--;

    uniform_real_distribution<float> u(0.0f, 1.0f);

    if (u(rng) > 0.7f)
    {
        return false;
    }

    float r = u(rng);
    Ore ore = (r < 0.7f) ? Ore::Iron :
        (r < 0.9f ? Ore::Silver : Ore::Gold);

    switch (ore) 
    {
    case Ore::Iron: 
        p.iron++;
        break;
    case Ore::Silver:
        p.silver++;
        break;
    case Ore::Gold:
        p.gold++;
        break;
    }
    
    return true;
}

int main()
{
    mt19937 rng(random_device{}());
    Player you;
    Pickaxe px;

    for (int i = 0; i < 10; i++)
    {
        bool ok = TryMining(you, px, rng);
        cout << (ok ? "채광 성공! " : "실패... ")
            << "철:" << you.iron << " 은:" 
            << you.silver << " 금:" << you.gold
            << " | 스태미나:" << you.stamina 
            << " 곡괭이:" << px.durability << '\n';
    }
}
