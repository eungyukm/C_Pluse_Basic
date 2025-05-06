// C++17
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
    string name;
    int id;
};

class AggroTable
{
private:
    // key: playerId, value: aggro point
    unordered_map<int, int> aggroMap; 

public:
    void AddAggro(int playerId, int amount)
    {
        aggroMap[playerId] += amount;
    }

    int GetTopAggroTarget() const
    {
        int topId = -1;
        int maxAggro = -1;
        for (const auto& [id, aggro] : aggroMap)
        {
            if (aggro > maxAggro)
            {
                maxAggro = aggro;
                topId = id;
            }
        }
        return topId;
    }

    void PrintAggroTable
    (const vector<Player>& players) const
    {
        cout << "=== Aggro Table ===" << endl;
        for (const auto& [id, aggro] : aggroMap)
        {
            auto it = find_if(players.begin(),
                players.end(), [&](const Player& p)
                {
                    return p.id == id;
                });
            if (it != players.end())
            {
                cout << it->name << " (" << id
                    << " ): " << aggro << endl;
            }
        }
    }
};

int main()
{
    vector<Player> players = {
        {"Warrior", 1},
        {"Mage", 2},
        {"Healer", 3}
    };

    AggroTable aggro;

    aggro.AddAggro(1, 100); // Warrior hits
    aggro.AddAggro(2, 120); // Mage hits harder
    aggro.AddAggro(3, 50);  // Healer heals ally

    aggro.PrintAggroTable(players);

    int targetId = aggro.GetTopAggroTarget();
    auto targetIt = find_if(players.begin(), 
        players.end(), [&](const Player& p) 
        { return p.id == targetId; });

    if (targetIt != players.end())
    {
        cout << ">> Monster targets: " 
            << targetIt->name << "!" << endl;
    }
        
    return 0;
}
