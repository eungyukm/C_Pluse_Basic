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
    int hp;
};

class AggroTable
{
    unordered_map<int, int> aggroMap;

public:
    void AddAggro(int id, int value) { aggroMap[id] += value; }

    int GetTopTarget() const
    {
        return max_element(aggroMap.begin(), aggroMap.end(),
            [](auto& a, auto& b) 
            { 
                return a.second < b.second; 
            })->first;
    }
};

void MonsterAct(const AggroTable& aggro, 
    const vector<Player>& players)
{
    int targetId = aggro.GetTopTarget();
    auto it = find_if(players.begin(), players.end(),
        [&](const Player& p)
        {
            return p.id == targetId;
        });

    if (it != players.end())
    {
        if (it->hp < 30)
        {
            cout << "몬스터가 " << it->name
                << "에게 독을 뿌린다!" << endl;
        }
        else
        {
            cout << "몬스터가 " << it->name
                << "에게 화염구를 날린다!" << endl;
        }
    }
}

int main()
{
    vector<Player> players = {
        {"Knight", 1, 80},
        {"Archer", 2, 25},
        {"Cleric", 3, 60}
    };

    AggroTable aggro;
    aggro.AddAggro(1, 50);
    aggro.AddAggro(2, 80);
    aggro.AddAggro(3, 20);

    MonsterAct(aggro, players);

    return 0;
}
