// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class EDungeonState
{
    Fighting,
    Cleared
};

struct Reward
{
    int gold = 0;
    int exp = 0;
    vector<string> items;
};

struct Player
{
    int gold = 0;
    int exp = 0;
    vector<string> inventory;

    void AddReward(const Reward& r)
    {
        gold += r.gold;
        exp += r.exp;
        for (size_t i = 0; i < r.items.size(); i++)
        {
            inventory.push_back(r.items[i]);
        }
    }
};

struct Dungeon
{
    bool bossDead = false;
    EDungeonState state = EDungeonState::Fighting;
    Reward clearReward{ 500, 1500, {"Epic_Shard", "Ancient_Core"} };
    bool rewardGiven = false;

    void OnBossKilled()
    {
        if (bossDead)
        {
            return;
        }
        bossDead = true;
        state = EDungeonState::Cleared;
    }

    bool CanClaimReward() const
    {
        return bossDead && state ==
            EDungeonState::Cleared && rewardGiven == false;
    }

    void GrantClearReward(Player& p)
    {
        if (CanClaimReward())
        {
            p.AddReward(clearReward);
            rewardGiven = true;
        }
    }
};

int main()
{
    Dungeon d;
    Player  p;

    d.OnBossKilled();            // 보스 처치
    d.GrantClearReward(p);       // 클리어 보상 지급

    cout << "Gold: " << p.gold << ", Exp: " << p.exp << "\n";
    cout << "Items: ";
    for (int i = 0; i < p.inventory.size(); i++)
    {
        cout << p.inventory[i] << (i + 1 < p.inventory.size() ? ", " : "\n"); // 후위
    }
    return 0;
}
