// C++20
#include <iostream>
#include <string>

using namespace std;

struct GuildMember
{
    string name;
    int lastAttendDay{ -1 };   // 마지막 출석 일자 (예: 일 단위)
    int attendStreak{ 0 };     // 연속 출석 수
    int guildToken{ 0 };       // 길드 출석 토큰
};

int CalcAttendReward(int streak)
{
    int base = 10;
    int bonus = (streak - 1) * 2;
    int reward = base + bonus;

    if (reward > 30)
        reward = 30;

    return reward;
}

bool TryGuildAttend(GuildMember& m, int todayDay)
{
    if (m.lastAttendDay == todayDay)
    {
        cout << m.name << " 이미 출석함" << endl;
        return false;
    }

    if (m.lastAttendDay == todayDay - 1)
        m.attendStreak++;
    else
        m.attendStreak = 1;

    m.lastAttendDay = todayDay;

    int gain = CalcAttendReward(m.attendStreak);
    m.guildToken += gain;
    cout << m.name << " 출석 성공 연속 "
        << m.attendStreak << "일 "
        << "토큰 +" << gain
        << " 총 " << m.guildToken << endl;

    return true;
}

int main()
{
    GuildMember m{ "Obliy" };

    int day1 = 1;
    int day2 = 2;
    int day4 = 4;

    TryGuildAttend(m, day1);
    TryGuildAttend(m, day1);
    TryGuildAttend(m, day2);
    TryGuildAttend(m, day4);

    return 0;
}
