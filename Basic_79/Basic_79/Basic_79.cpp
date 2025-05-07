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

    void Print(const vector<Player>& players) const
    {
        cout << "\n=== 헤이트 테이블 ===\n";
        for (const auto& [id, hate] : aggroMap)
        {
            auto it = find_if(players.begin(), players.end(),
                [&](const Player& p) { return p.id == id; });

            if (it != players.end())
                cout << it->name << " : " << hate << '\n';
        }
    }

    void Taunt(int taunterId)
    {
        int totalHate = 0;
        for (auto& [id, hate] : aggroMap)
        {
            if (id != taunterId)
            {
                totalHate += hate;
                hate = 0;
            }
        }

        aggroMap[taunterId] += totalHate;

        cout << "\n>> Knight가 도발을 사용! ("
            << totalHate << " 만큼의 헤이트를 흡수)\n";
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
    aggro.AddAggro(1, 30);   // Knight
    aggro.AddAggro(2, 80);   // Archer
    aggro.AddAggro(3, 50);   // Cleric

    aggro.Print(players);

    // Knight uses Taunt
    aggro.Taunt(1);

    aggro.Print(players);

    int targetId = aggro.GetTopTarget();
    auto it = find_if(players.begin(), players.end(),
        [&](const Player& p) { return p.id == targetId; });

    if (it != players.end())
        cout << "\n>> 몬스터가 " << it->name 
        << "을(를) 타겟팅합니다!\n";

    return 0;
}
