// C++20
#include <iostream>
#include <random>
#include <string>

using namespace std;

enum class StatusEffect
{
    None,
    Burn,
    Freeze
};

struct Pal
{
    string name;
    StatusEffect status = StatusEffect::None;

    void ApplyStatus(StatusEffect effect)
    {
        status = effect;

        switch (effect)
        {
        case StatusEffect::Burn:
            cout << name << "는 화상 상태에 걸렸습니다!\n";
            break;
        case StatusEffect::Freeze:
            cout << name << "는 빙결 상태에 걸렸습니다!\n";
            break;
        default:
            break;
        }
    }
};

StatusEffect GetRandomStatusEffect()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    int roll = dist(gen);

    if (roll <= 15)
    {
        return StatusEffect::Burn;
    }
    else if (roll <= 45)
    {
        return StatusEffect::Freeze;
    }
    else
    {
        return StatusEffect::None;
    }
}

void OnSkillHit(Pal& attacker, Pal& target)
{
    cout << attacker.name << "의 스킬이 " << target.name 
        << "에게 명중했습니다!\n";

    StatusEffect effect = GetRandomStatusEffect();

    if (effect != StatusEffect::None)
    {
        target.ApplyStatus(effect);
    }
    else
    {
        cout << target.name << "는 상태 이상에 걸리지 않았습니다.\n";
    }
}

int main()
{
    Pal pengullet{ "펭키 (Pengullet)" };
    Pal pururu{ "푸루 (Pururu)" };

    OnSkillHit(pengullet, pururu);

    return 0;
}
