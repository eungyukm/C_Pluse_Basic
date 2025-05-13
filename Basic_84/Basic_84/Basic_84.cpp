// C++20 기준
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

struct Unit {
    string name;
    int x, y;
    bool isEnemy;
};

int Distance(const Unit& a, const Unit& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

const Unit* FindNearestEnemy
(const Unit& self, const vector<Unit>& units) 
{
    const Unit* target = nullptr;
    int minDist = numeric_limits<int>::max();
    for (const auto& u : units)
    {
        if (u.isEnemy == self.isEnemy)
        {
            continue;
        }
        int dist = Distance(self, u);
        if (dist < minDist) 
        {
            minDist = dist;
            target = &u;
        }
    }
    return target;
}

void CheckAttack(const vector<Unit>& units, int attackRange = 1) 
{
    for (const auto& u : units)
    {
        if (!u.isEnemy)
        {
            const Unit* target = FindNearestEnemy(u, units);
            if (target)
            {
                int dist = Distance(u, *target);
                if (dist <= attackRange)
                {
                    cout << u.name << " -> " << target->name
                        << "을(를) 공격!" << endl;
                }
                else
                {
                    cout << u.name << " -> " << target->name
                        << " (거리: " << dist << ") - 사거리 밖"
                        << endl;
                }
            }
        }
    }
}

int main() {
    vector<Unit> units = {
        {"Garen", 1, 1, false},
        {"Ashe", 3, 1, false},
        {"Zed", 1, 2, true},
        {"Kennen", 3, 3, true}
    };

    CheckAttack(units, 1); // 사거리 1칸
}
