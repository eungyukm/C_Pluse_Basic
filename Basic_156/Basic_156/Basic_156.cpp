// C++20
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

enum class EStatusEffect
{
    None,
    Frozen,
    Paralyzed,
    Burned
};

enum class ESpearType
{
    Normal,
    Advanced,
    Master
};

// 상태 이상에 따른 보정값
float GetStatusEffectBonus(EStatusEffect status)
{
    switch (status)
    {
    case EStatusEffect::Frozen:
    case EStatusEffect::Paralyzed:
        return 1.5f;
    case EStatusEffect::Burned:
        return 1.2f;
    default:
        return 1.0f;
    }
}

// 스피어 종류에 따른 보정값
float GetSpearBonus(ESpearType spear)
{
    switch (spear)
    {
    case ESpearType::Normal:
        return 1.0f;
    case ESpearType::Advanced:
        return 1.5f;
    case ESpearType::Master:
        return 2.0f;
    default:
        return 1.0f;
    }
}

// 포획 성공 확률 계산 함수
float CalculateCaptureChance(float currentHP, float maxHP, 
    ESpearType spearType, EStatusEffect status)
{
    if (maxHP <= 0.0f) return 0.0f;
    // 체력이 낮을수록 유리
    float hpRate = max(0.0f, min(1.0f, 1.0f - currentHP / maxHP));
    float spearBonus = GetSpearBonus(spearType);
    float statusBonus = GetStatusEffectBonus(status);
    // 기본확률 20%
    float baseChance = 0.2f;
    float finalChance = baseChance + hpRate * 0.5f;
    finalChance *= spearBonus;
    finalChance *= statusBonus;
    // 최대 95%
    return min(finalChance, 0.95f);
}

// 예시
int main()
{
    float hp = 30.0f;
    float maxHp = 100.0f;
    ESpearType spear = ESpearType::Advanced;
    EStatusEffect status = EStatusEffect::Frozen;

    float chance = CalculateCaptureChance(hp, maxHp, spear, status);
    cout << "포획 확률: " << chance * 100 << "%" << endl;

    return 0;
}
