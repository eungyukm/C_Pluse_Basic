// C++20
#include <iostream>
#include <random>
using namespace std;

struct Player
{
    int gold = 0;
    int relic = 0;
    int mapPiece = 0;
    int attempts = 0;
};

bool ExploreWreck(Player& p, mt19937& rng)
{
    p.attempts++;
    bernoulli_distribution canExplore(0.85);
    if (!canExplore(rng))
    {
        return false;
    }

    discrete_distribution<int> pick({ 50, 30, 20 });
    switch (pick(rng))
    {
    case 0:
    {
        uniform_int_distribution<int> goldRoll(80, 100);
        p.gold += goldRoll(rng);
    }
    break;
    case 1:
    {
        uniform_int_distribution<int> relicRoll(1, 3);
        p.relic += relicRoll(rng);
    }
    break;
    default:
    {
        uniform_int_distribution<int> mapRoll(1, 2);
        p.mapPiece += mapRoll(rng);
    }
    break;
    }
    return true;
}

int main()
{
    random_device rd;
    mt19937 rng(rd());
    Player you;

    for (int i = 0; i < 5; i++)
    {
        bool ok = ExploreWreck(you, rng);
        cout << (ok ? "[성공] 보상 획득" : "[실패] 탐사 불가")
            << " | 시도:" << you.attempts
            << " | 골드:" << you.gold
            << " | 유물:" << you.relic
            << " | 지도:" << you.mapPiece << '\n';
    }
}
