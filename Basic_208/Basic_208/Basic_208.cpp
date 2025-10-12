// C++20
#include <iostream>
using namespace std;

struct Skill
{
    int level{ 0 };
    int max{ 10 };
};

struct Player
{
    int sp{ 0 };
};

bool SpendSkillPoint(Player& p, Skill& s)
{
    if (p.sp <= 0 || s.level >= s.max)
    {
        return false;
    }
    p.sp--;
    s.level++;
    return true;
}

// N개 한 번에 분배
int SpendSkillPoints(Player& p, Skill& s, int cnt)
{
    int used{ 0 };
    while (cnt-- > 0 && SpendSkillPoint(p, s))
    {
        used++;
    }
    return used;
}

int main()
{
    Player me{ 5 };      // 스킬 포인트 5
    Skill  fire{ 0, 7 }; // 파이어 스킬: 최대 7레벨

    SpendSkillPoints(me, fire, 3); // 3포인트 사용 → 레벨 +3

    cout << "남은 포인트: " << me.sp << "\n";
    cout << "파이어 레벨: " << fire.level << "/" << fire.max << "\n";
    return 0;
}
