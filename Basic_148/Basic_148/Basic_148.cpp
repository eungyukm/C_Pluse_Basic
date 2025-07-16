// C++20
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

double GetDamageMultiplier(const string& attackerType, const string& defenderType)
{
    // 속성 인덱스를 위한 맵
    unordered_map<string, int> typeIndex = {
        {"Fire", 0},
        {"Water", 1},
        {"Grass", 2}
    };

    // 2차원 배열로 대미지 배율 정의
    double multiplier[3][3] = {
        {1.0, 0.5, 2.0},
        {2.0, 1.0, 0.5},
        {0.5, 2.0, 1.0}
    };

    int attacker = typeIndex[attackerType];
    int defender = typeIndex[defenderType];

    return multiplier[attacker][defender];
}

int main()
{
    cout << "Fire vs Grass: " << GetDamageMultiplier("Fire", "Grass") << endl;
    cout << "Water vs Fire: " << GetDamageMultiplier("Water", "Fire") << endl;
    cout << "Grass vs Water: " << GetDamageMultiplier("Grass", "Water") << endl;
}
