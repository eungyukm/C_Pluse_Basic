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

int Distance(const Unit& a, const Unit& b) 
{
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

void MoveToward(Unit& self, const Unit& target)
{
    if (self.x != target.x)
    {
        self.x += (target.x > self.x) ? 1 : -1;
    }
    else if (self.y != target.y)
    {
        self.y += (target.y > self.y) ? 1 : -1;
    }
}

int main() 
{
    vector<Unit> units = {
        {"Garen", 1, 0, false},
        {"Ashe", 3, 0, false},
        {"Zed", 1, 6, true},
        {"Kennen", 2, 5, true}
    };

    cout << "이동 전:" << endl;
    for (auto& u : units)
    {
        cout << u.name << ": (" << u.x << "," << u.y << ")" << endl;
    }
        

    for (auto& u : units)
    {
        if (!u.isEnemy)
        {
            const Unit* target = FindNearestEnemy(u, units);
            if (target)
            {
                MoveToward(u, *target);
            }
        }
    }

    cout << "\n이동 후:" << endl;
    for (auto& u : units)
    {
        cout << u.name << ": (" << u.x << "," << u.y << ")" << endl;
    }
}
