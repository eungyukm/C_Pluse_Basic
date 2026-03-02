// C++20
#include <iostream>
#include <string>

using namespace std;

struct SeasonReward
{
    string grade;
    int crystal;
    int honor;
};

SeasonReward CalcSeasonReward(int rating)
{
    SeasonReward r;

    if (rating >= 2100)
    {
        r.grade = "Legend";
        r.crystal = 2000;
        r.honor = 500;
    }
    else if (rating >= 1900)
    {
        r.grade = "GrandMaster";
        r.crystal = 1500;
        r.honor = 350;
    }
    else
    {
        r.grade = "Gold";
        r.crystal = 200;
        r.honor = 400;
    }

    return r;
}

int main()
{
    int rating = 1780;

    SeasonReward reward = CalcSeasonReward(rating);

    cout << "Rating " << rating
        << " Grade " << reward.grade
        << " Crystal " << reward.crystal
        << " Honor " << reward.honor << endl;

    return 0;
}