// C++20 기준
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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

// AoE 대상 판정: attacker 기준, range 이내 적 탐색
void AoETargeting
(const Unit& attacker, const vector<Unit>& units, int range) 
{
    cout << attacker.name
        << "의 AoE 범위 공격 (" << range << "칸)" << endl;
    for (const auto& u : units)
    {
        if (u.isEnemy != attacker.isEnemy &&
            Distance(attacker, u) <= range)
        {
            cout << " -> " << u.name << " 적중!\n";
        }
    }
}

int main() {
    vector<Unit> units = {
        {"Garen", 2, 2, false},
        {"Ashe", 1, 2, false},
        {"Zed", 2, 3, true},
        {"Kennen", 3, 2, true},
        {"Talon", 4, 4, true}
    };

    for (const auto& u : units)
    {
        // 아군만 AoE 사용
        if (!u.isEnemy)
        {
            // 범위 1칸
            AoETargeting(u, units, 1); 
        }
    }
}
