// C++20
#include <iostream>
#include <string>

using namespace std;

// === 피격 부위 열거형 ===
enum class EHitPart
{
    Body,
    Head
};

// === 팰 캐릭터 클래스 ===
class APalCharacter
{
public:
    string Name;
    int HP;

    APalCharacter(string name, int hp)
        : Name(name), HP(hp)
    {}

    void TakeDamage(int baseDamage, EHitPart hitPart)
    {
        float multiplier = 1.0f;

        if (hitPart == EHitPart::Head)
        {
            multiplier = 1.5f;
            cout << "[CRITICAL HIT] Headshot! ";
        }

        int finalDamage = static_cast<int>(baseDamage * multiplier);
        HP -= finalDamage;
        if (HP < 0)
        {
            HP = 0;
        }
        cout << Name << " took " << finalDamage << " dmage (HP: " << HP << ")"
            << endl;
    }
};

// === 테스트 ===
int main()
{
    APalCharacter pal("FireFoxPal", 100);

    cout << "--- 일반 공격 ---\n";
    pal.TakeDamage(20, EHitPart::Body);

    cout << "--- 머리 공격 ---\n";
    pal.TakeDamage(20, EHitPart::Head);

    return 0;
}
