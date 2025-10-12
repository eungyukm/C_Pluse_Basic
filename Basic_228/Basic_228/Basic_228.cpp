// C++20
#include <iostream>
using namespace std;

struct Player
{
    int gold{ 0 };
    int chest{ 0 }; // 등급 보상 상자
};

struct LifeSkill
{
    int lv{ 1 };
    int exp{ 0 };
    int next{ 20 };

    void GiveLevelReward(Player& p)
    {
        if (lv % 5 == 0)
        {
            p.chest++;
        }
        else
        {
            p.gold += 100 * lv;
        }
    }

    void GainExp(Player& p, int v)
    {
        exp += v;
        while (exp >= next)
        {
            exp -= next;
            lv++;
            next = 20 + lv * 10;
            GiveLevelReward(p);
        }
    }
};

int main()
{
    Player you;
    LifeSkill skill;

    for (int i = 0; i < 6; i++)
    {
        skill.GainExp(you, 25); // 채집 성공했다고 가정(25 EXP)
        cout << "LV:" << skill.lv
            << " EXP:" << skill.exp << "/" << skill.next << '\n';
        cout << "GOLD:" << you.gold << " CHEST:" << you.chest << '\n';
    }
}
