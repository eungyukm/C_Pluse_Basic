#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

using namespace std;

// === 기본 벡터 구조 ===
struct FVector
{
    float X, Y;

    FVector(float x = 0, float y = 0) : X(x), Y(y) {}

    float DistanceTo(const FVector& other) const
    {
        return sqrt((X - other.X) * (X - other.X) + 
            (Y - other.Y) * (Y - other.Y));
    }

    bool IsInsideRect(const FVector& center, float width, float height) const
    {
        return abs(X - center.X) <= width / 2.0f && 
            abs(Y - center.Y) <= height / 2.0f;
    }
};

// === 적 유닛 ===
struct FEnemy
{
    string Name;
    FVector Position;
    int HP;

    FEnemy(string name, FVector pos, int hp) : 
        Name(name), Position(pos), HP(hp) {}

    void TakeDamage(int amount)
    {
        HP -= amount;
        cout << Name << "이 (가) " << amount << " 피해를 입었습니다. 남은 HP:"
            << HP << endl;
    }
};

// === 스킬 판정 함수 ===
void ApplySkillDamage(const FVector& skillCenter, float radius, 
    int damage, vector<shared_ptr<FEnemy>>& enemies)
{
    for (auto& enemy : enemies)
    {
        if (enemy->Position.DistanceTo(skillCenter) <= radius)
        {
            enemy->TakeDamage(damage);
        }
    }
}

void ApplyRectSkillDamage(const FVector& skillCenter, 
    float width, float height, int damage, vector<shared_ptr<FEnemy>>& enemies)
{
    for (auto& enemy : enemies)
    {
        if (enemy->Position.IsInsideRect(skillCenter, width, height))
        {
            enemy->TakeDamage(damage);
        }
    }
}

// === 예제 실행 ===
int main()
{
    vector<shared_ptr<FEnemy>> enemies = {
        make_shared<FEnemy>("까부냥", FVector(2, 3), 100),
        make_shared<FEnemy>("청부리", FVector(5, 5), 120),
    };

    FVector skillPosition(5, 5);
    float skillRadius = 3.0f;
    int skillDamage = 50;

    cout << "[원형 범위 스킬 발동!]" << endl;
    ApplySkillDamage(skillPosition, skillRadius, skillDamage, enemies);

    cout << "\n[사각형 범위 스킬 발동!]" << endl;
    ApplyRectSkillDamage(skillPosition, 6.0f, 4.0f, skillDamage, enemies);

    return 0;
}
