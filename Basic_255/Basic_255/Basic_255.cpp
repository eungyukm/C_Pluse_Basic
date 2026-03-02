// C++20
#include <iostream>
#include <string>

using namespace std;

struct SeasonPlayer
{
    string name;
    int rating{ 1400 };
    int win{ 0 };
    int lose{ 0 };
    int winStreak{ 0 };
};

int CalcSeasonGain(int myRating, int enemyRating, int winStreak)
{
    int gain = 15;
    if (myRating < enemyRating)
        gain += 5;

    if (winStreak >= 3)
        gain += 5;

    if (myRating >= 1800)
        gain -= 5;

    if (gain < 1)
        gain = 1;

    return gain;
}

void ApplySeasonResult(SeasonPlayer& me, int enemyRating, 
    bool isWin)
{
    if (isWin == true)
    {
        int gain = CalcSeasonGain(me.rating, enemyRating,
            me.winStreak);
        me.rating += gain;
        me.win++;
        me.winStreak;
        cout << me.name << " 승리 +" << gain
            << " 현재 점수 " << me.rating << endl;
    }
    else
    {
        int losePoint = 10;
        me.rating -= losePoint;
        if (me.rating < 0)
            me.rating = 0;

        me.lose++;
        me.winStreak = 0;

        cout << me.name << " 패배 -" << losePoint
            << " 현재 점수 " << me.rating << endl;
    }
}

int main()
{
    SeasonPlayer me{ "Obliy", 1450 };
    int enemyRating = 1500;

    cout << "=== PvP 시즌 점수 예시 ===" << endl;
    ApplySeasonResult(me, enemyRating, true);
    ApplySeasonResult(me, enemyRating, true);
    ApplySeasonResult(me, enemyRating, false);

    return 0;
}
