// C++ 20
#include <iostream>
#include <algorithm>
using namespace std;

// 항해 중 암초 충돌 시 내구도 손상
// speed: 선속(노트), severity: 암초 위험도(0~1), armor: 선체 방어(0~1)
float ApplyReefDamage(float durability,
    float speed, float severity, float armor)
{
    // 속도에 비례해 손상 증가
    float dmgBase = 2.f + speed * 0.5f;
    // 위험도, 방어 반영
    float dmg = dmgBase * severity * (1.f - armor);
    // 최소/최대 손상 제한
    dmg = clamp(dmg, 1.f, 35.f);
    return max(0.f, durability - dmg);
}

int main()
{
    float durability = 100.f;
    float speed = 18.f;        // 빠를수록 타격 큼
    float severity = 0.6f;     // 암초 지역 위험도
    float armor = 0.2f;        // 선체 보강

    durability =
        ApplyReefDamage(durability, speed, severity, armor);
    cout << "remain durability " << durability << "\n";
    return 0;
}