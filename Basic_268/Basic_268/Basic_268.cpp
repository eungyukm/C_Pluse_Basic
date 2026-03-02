using namespace std;
#include <iostream>
#include <vector>
#include <string>

struct Reward
{
    int gold = 0;
    int mats = 0;
    string item;
};

struct PassLevel
{
    int level = 0;
    Reward reward;
};

struct SeasonPass
{
    int level = 1;
    vector<PassLevel> levels;
};

void ClaimPassReward(SeasonPass& pass, int targetLevel)
{
    for (int i = 0; i < (int)pass.levels.size(); i++)
    {
        auto& lv = pass.levels[i];
        if (lv.level != targetLevel) continue;

        if (pass.level < targetLevel)
        {
            cout << "Not reached level " << targetLevel << endl;
            return;
        }

        cout << "Claimed level " << targetLevel
            << " gold " << lv.reward.gold
            << " mats " << lv.reward.mats
            << " item " << lv.reward.item << endl;
        return;
    }
    cout << "No reward for level " << targetLevel << endl;
}
int main()
{
    SeasonPass pass;
    pass.level = 3;
    pass.levels =
    {
        {1, {100, 5, "Potion"}},
        {2, {150, 7, "Chest"}},
    };
    ClaimPassReward(pass, 2);
    return 0;
}