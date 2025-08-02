// C++20
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Monster
{
    float X, Y;
    bool bHostile;

    float DistanceTo(float px, float py) const
    {
        return sqrt((X - px) * (X - px) + (Y - py) * (Y - py));
    }
};

void CheckBattleMusic(float playerX, float playerY, 
    const vector<Monster>& monsters, float range, bool& isBattlePlaying)
{
    for (const auto& m : monsters)
    {
        if (m.bHostile && m.DistanceTo(playerX, playerY) <= range)
        {
            if (!isBattlePlaying)
            {
                cout << "[BGM] 전투 음악 재생" << endl;
                isBattlePlaying = true;
            }
            return;
        }
    }

    if (isBattlePlaying)
    {
        cout << "[BGM] 평화로운 음악으로 전환" << endl;
        isBattlePlaying = false;
    }
}

int main()
{
    vector<Monster> monsters = {
        {5.0f, 0.0f, false},
        {8.0f, 0.0f, true},
        {20.0f, 0.0f, true}
    };

    float playerX = 0.0f, playerY = 0.0f;
    float detectRange = 10.0f;
    bool isBattlePlaying = false;

    CheckBattleMusic(playerX, playerY, monsters, detectRange, isBattlePlaying);

    // 플레이어 위치 이동 후 다시 체크
    playerX = 50.0f;
    playerY = 50.0f;
    CheckBattleMusic(playerX, playerY, monsters, detectRange, isBattlePlaying);
}
