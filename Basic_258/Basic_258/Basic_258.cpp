// C++20
#include <iostream>
#include <string>

using namespace std;

struct Guild
{
    string name;
    int gold{ 0 };
    int resourcePoint{ 0 };   // 길드 자원 포인트
};

struct GuildMember
{
    string name;
    int todayDonateGold{ 0 }; // 오늘 기부한 골드
    int dailyLimit{ 1000 };   // 하루 최대 기부 가능 골드
    int donatePoint{ 0 };     // 개인 기여도 포인트
};

int CalcDonatePoint(int gold)
{
    return gold / 10;         // 10골드당 1포인트
}

bool DonateGuildGold(GuildMember& m, Guild& g, int gold)
{
    if (gold <= 0)
        return false;

    int remain = m.dailyLimit - m.todayDonateGold;
    if (remain <= 0)
    {
        cout << m.name << " 오늘 기부 한도 초과" << endl;
        return false;
    }

    if (gold > remain)
        gold = remain;

    m.todayDonateGold += gold;

    int point = CalcDonatePoint(gold);
    m.donatePoint += point;

    g.gold += gold;
    g.resourcePoint += point;

    cout << m.name << " 길드 기부 "
        << gold << "골드 "
        << "개인 기여도 +" << point
        << " 길드 자원 +" << point << endl;

    return true;
}

int main()
{
    Guild g{ "ObliyGuild" };
    GuildMember m{ "Obliy" };

    DonateGuildGold(m, g, 500);
    DonateGuildGold(m, g, 800);
    DonateGuildGold(m, g, 300);

    cout << "길드 총 골드 " << g.gold
        << " 자원 포인트 " << g.resourcePoint << endl;

    return 0;
}
