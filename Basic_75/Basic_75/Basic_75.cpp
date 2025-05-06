// C++20
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
    // playerId -> aggro point
    unordered_map<int, float> aggroMap; 

public:
    void AddAggro(int playerId, float amount)
    {
        aggroMap[playerId] += amount;
    }

    void DecayAggro(float decayRate)
    {
        for (auto& [id, aggro] : aggroMap)
        {
            // 0.1 -> 10% 감소
            aggro *= (1.0f, decayRate);
            if (aggro < 1.0f)
            {
                aggro = 0.0f;
            }
        }
    }

    int GetTopAggroTarget() const
    {
        int topId = -1;
        float maxAggro = -1.0f;
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

    void PrintAggroTable(const vector<Player>& players) const
    {
        cout << "\n=== Aggro Table ===" << endl;
        for (const auto& [id, aggro] : aggroMap)
        {
            auto it = find_if(players.begin(), players.end(),
                [&](const Player& p) { return p.id == id; });
            if (it != players.end())
            {
                cout << it->name << " (" << id << "): "
                    << static_cast<int>(aggro) << endl;
            }
        }
    }
};

int main()
{
    vector<Player> players = {
        {"Knight", 1},
        {"Archer", 2},
        {"Cleric", 3}
    };

    AggroTable aggro;
    aggro.AddAggro(1, 100); // Knight hits
    aggro.AddAggro(2, 80);  // Archer hits
    aggro.AddAggro(3, 120); // Cleric heals ally

    aggro.PrintAggroTable(players);

    // 시간 경과 시 aggro 감소
    for (int tick = 1; tick <= 3; ++tick)
    {
        cout << "\n--- Tick " << tick << ": Aggro Decay ---" << endl;
        aggro.DecayAggro(0.2f); // 20%씩 감소
        aggro.PrintAggroTable(players);
    }

    int targetId = aggro.GetTopAggroTarget();
    auto it = find_if(players.begin(), players.end(),
        [&](const Player& p) { return p.id == targetId; });

    if (it != players.end())
    {
        cout << "\n>> Monster targets: " << it->name << "!" << endl;
    }

    return 0;
}
