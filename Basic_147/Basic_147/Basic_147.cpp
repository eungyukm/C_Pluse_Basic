// C++20
#include <iostream>
using namespace std;

float CalculateDamage(int attack, float skillPower, int defense)
{
    if (defense <= 0)
    {
        defense = 1; // 방어력이 0 이하일 경우 최소값 보정
    }
    float damage = (attack * skillPower) / defense;
    return damage;
}

int main()
{
    int attack = 100;
    int skillPower = 1.5f;
    int defense = 50;

    float damage = CalculateDamage(attack, skillPower, defense);
    cout << "Damage: " << damage << endl;
    return 0;
}
