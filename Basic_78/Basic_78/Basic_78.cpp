// C++20
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Player
{
    string name;
    int id;
};

class AggroTable
{
    unordered_map<int, int> aggroMap;

public:
    void AddAggro(int id, int value) { aggroMap[id] += value; }

    void PrintAggroBar(const vector<Player>& players) const
    {
        cout << "\n=== 헤이트 테이블 ===\n";
        for (const auto& [id, hate] : aggroMap)
        {
            auto it = find_if(players.begin(), players.end(),
                [&](const Player& p)
                {
                    return p.id == id;
                });

            if (it != players.end())
            {
                cout << it->name << " (ID: " << id << ") :";

                int barLength = hate / 10;
                for (int i = 0; i < barLength; ++i)
                {
                    cout << "[]";
                }
                cout << " " << hate << '\n';
            }
        }
    }

    int GetTopTarget() const
    {
        return max_element(aggroMap.begin(), aggroMap.end(),
            [](auto& a, auto& b) 
            { 
                return a.second < b.second; 
            })->first;
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
    aggro.AddAggro(1, 100);
    aggro.AddAggro(2, 70);
    aggro.AddAggro(3, 110);

    aggro.PrintAggroBar(players);
    return 0;
}
