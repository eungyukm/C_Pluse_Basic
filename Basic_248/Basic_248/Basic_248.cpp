// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player
{
    int Gold = 0;
    vector<string> Items;
};

struct Quest
{
    int Target;
    int Progress = 0;
    bool Completed = false;
    bool Rewarded = false;

    int RewardGold = 100;
    string RewardItem = "희귀 상자";

    void OnKill(Player& p)
    {
        if (Completed)
            return;
        if (Progress < Target)
        {
            Progress++;
            if (Progress == Target)
            {
                Completed = true;
                Reward(p); // 완료 시 즉시 보상
            }
        }
    }

    void Reward(Player& p)
    {
        if (Rewarded)
            return;
        Rewarded = true;
        p.Gold += RewardGold;
        if (!RewardItem.empty())
            p.Items.push_back(RewardItem);
        cout << "[Quest] 완료 즉시 보상: Gold +"
            << RewardGold << ", Item: " << RewardItem <<
            endl;
    }
};

int main()
{
    Player p;
    Quest q{ 3 }; // 3킬 목표

    for (int i = 0; i < 3; i++)
    {
        q.OnKill(p);
        cout << "Kill " << i + 1 
            << " / Progress " << q.Progress 
            << "/" << q.Target << "\n";
    }

    cout << "Player Gold: " << p.Gold << "\n";
    cout << "Player Items: ";
    for (int i = 0; i < (int)p.Items.size(); i++) 
        cout << p.Items[i] << " ";
    cout << "\n";
    return 0;
}
