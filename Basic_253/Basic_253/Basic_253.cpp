// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player
{
    string name;
    bool weeklyCleared{ false }; // 주간 보상 수령 여부
    int gold{ 0 };
    int shard{ 0 };
};

void GiveLegionReward(vector<Player>& party, bool raidClear)
{
    cout << "[군단장 레이드 보상 지급]\n";

    if (!raidClear)
    {
        cout << "  레이드 미클리어 보상 없음\n";
        return;
    }

    int baseGold = 500;
    int baseShard = 50;

    for (int i = 0; i < (int)party.size(); i++)
    {
        Player& p = party[i];

        if (p.weeklyCleared)
        {
            cout << " " << p.name << " 이미 이번 주 보상 수령" << endl;
            continue;
        }

        p.gold += baseGold;
        p.shard += baseShard;
        p.weeklyCleared = true;

        cout << " " << p.name
            << " 골드 +" << baseGold
            << " 파편 +" << baseShard << endl;
    }
}

int main()
{
    vector<Player> party{
        {"Leader", false, 0, 0},
        {"Dps1",   false, 0, 0},
        {"Dps2",   true,  1000, 200}
    };

    bool raidClear = true; // 레이드 클리어 성공

    GiveLegionReward(party, raidClear);

    cout << "\n[최종 상태]\n";
    for (int i = 0; i < (int)party.size(); i++)
    {
        Player& p = party[i];
        cout << "  " << p.name
            << " gold " << p.gold
            << " shard " << p.shard << "\n";
    }
    return 0;
}
