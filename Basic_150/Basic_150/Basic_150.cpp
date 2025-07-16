// C++20
#include <iostream>
#include <random>
using namespace std;

struct AttackInfo
{
    int attackPower;
    float skillMultiplier;
    float hitRate;        // 0.0 ~ 1.0
    float criticalRate;   // 0.0 ~ 1.0
};

int CalculateDamage(const AttackInfo& info, int defense)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.0f, 1.0f);

    float hitRoll = dist(gen);
    if (hitRoll > info.hitRate)
    {
        cout << "Missed!" << endl;
        return 0;
    }

    float damage = (info.attackPower * info.skillMultiplier) / defense;
    float critRoll = dist(gen);
    if (critRoll < info.criticalRate)
    {
        damage *= 1.5f;
        cout << "Critical Hit!" << endl;
    }
    return static_cast<int>(damage);
}

int main()
{
    AttackInfo attack = { 100, 1.2f, 0.8f, 0.25f };
    int defense = 50;

    int damage = CalculateDamage(attack, defense);
    cout << "Damage: " << damage << endl;

    return 0;
}