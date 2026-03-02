// C++20
#include <iostream>
#include <string>
using namespace std;

enum class ActivityType
{
    Dungeon,
    Raid,
    ChaosGate
};

int GetSeasonPassExp(ActivityType type)
{
    switch (type)
    {
        case ActivityType::Dungeon:   return 10;   // 일반 던전
        case ActivityType::Raid:      return 30;   // 레이드
        case ActivityType::ChaosGate: return 50;   // 카오스 게이트
    }
    return 0;
}

struct SeasonPass
{
    int level;
    int exp;
    int expToNext;

    void GainFromActivity(ActivityType type)
    {
        int gain = GetSeasonPassExp(type);
        exp += gain;

        cout << "시즌 패스 경험치 +" << gain
            << " (현재 경험치 " << exp << ")" << endl;

        while (exp >= expToNext)
        {
            exp -= expToNext;
            level++;

            cout << "시즌 패스 레벨 업! 현재 레벨"
                << level << ", 남은 경험치 " << exp << endl;
        }
    }
};

int main()
{
    SeasonPass pass{ 1, 0, 100 };

    pass.GainFromActivity(ActivityType::Dungeon);
    pass.GainFromActivity(ActivityType::Raid);
    pass.GainFromActivity(ActivityType::ChaosGate);

    cout << "최종 시즌 패스 레벨 " << pass.level
        << ", 경험치 " << pass.exp << endl;

    return 0;
}
