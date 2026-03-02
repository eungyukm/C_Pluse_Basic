// C++20
// Chaos Dungeon Reward → Grant on Boss Defeat
#include <iostream>
using namespace std;

struct Player
{
    int gold = 0;
    int shard = 0;
};

bool DefeatBoss(bool success, Player& p)
{
    if (!success)
    {
        cout << "[실패] 보스를 처치하지 못했습니다." << endl;
        return false;
    }

    p.gold += 300;
    p.shard += 20;
    cout << "[보상 획득] 골드 +" << 300 << ", 파편 +" << 20 << endl;
    return true;
}

int main()
{
    Player you;
    bool bossDefeated = true;

    DefeatBoss(bossDefeated, you);

    cout << "현재 보유 : 골드 " << you.gold
        << ", 파편 " << you.shard << endl;
}
