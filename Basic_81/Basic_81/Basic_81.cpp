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

// 맨해튼 거리 계산
int Distance(const Unit& a, const Unit& b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// 가장 가까운 적 찾기
const Unit* FindNearestEnemy(const Unit& self, 
    const vector<Unit>& units)
{
    const Unit* target = nullptr;
    int minDist = numeric_limits<int>::max();

    for (const auto& other : units)
    {
        if (other.isEnemy == self.isEnemy)
        {
            continue;
        }
        int dist = Distance(self, other);
        if (dist < minDist)
        {
            minDist = dist;
            target = &other;
        }
    }
    return target;
}

int main() {
    vector<Unit> units = {
        {"Garen", 1, 0, false},  // 아군
        {"Ashe", 3, 0, false},
        {"Zed", 1, 6, true},     // 적군
        {"Kennen", 2, 5, true}
    };

    for (const auto& u : units)
    {
        if (!u.isEnemy)
        {
            const Unit* target = FindNearestEnemy(u, units);
            if (target)
                cout << u.name << " -> " << target->name
                << " (거리: " << Distance(u, *target) << ")\n";
        }
    }
}
