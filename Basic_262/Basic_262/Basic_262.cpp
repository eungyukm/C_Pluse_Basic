// C++20
#include <iostream>
#include <string>
using namespace std;

enum class GuildWarResult
{
    Win,
    Lose,
    Draw
};

struct Guild
{
    string name;
    int score;
    int reward = 0;
};

GuildWarResult CalcResult(int aScore, int bScore)
{
    if (aScore > bScore) return GuildWarResult::Win;
    if (aScore < bScore) return GuildWarResult::Lose;
    return GuildWarResult::Draw;
}

void GiveReward(Guild& a, Guild& b)
{
    GuildWarResult result = CalcResult(a.score, b.score);

    if (result == GuildWarResult::Win)
    {
        a.reward = 100;
        b.reward = 50;
    }
    else if (result == GuildWarResult::Lose)
    {
        a.reward = 50;
        b.reward = 100;
    }
    else
    {
        a.reward = 70;
        b.reward = 70;
    }
}

int main()
{
    Guild red{ "RedGuild", 120 };
    Guild blue{ "BlueGuild", 110 };

    GiveReward(red, blue);

    cout << red.name << " 보상: " << red.reward << "\n";
    cout << blue.name << " 보상: " << blue.reward << "\n";

    return 0;
}
