// C++20
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <limits>

using namespace std;

// ===== 팰월드 전투 캐릭터 (플레이어 또는 팰) =====
struct FPAL_Character
{
    string CharacterID;
    int HP;

    FPAL_Character(string id, int hp) : CharacterID(id), HP(hp) {}
};

// ===== NetID 기반 해시 및 비교 함수 =====
struct FPAL_CharacterHasher
{
    size_t operator()(const shared_ptr<FPAL_Character>& unit) const
    {
        return hash<string>()(unit->CharacterID);
    }
};

struct FPAL_CharacterEqual
{
    bool operator()(const shared_ptr<FPAL_Character>& a,
        const shared_ptr<FPAL_Character>& b) const
    {
        return a && b && a->CharacterID == b->CharacterID;
    }
};

// ===== 몬스터 AI 컨트롤러 =====
class APAL_MonsterAIController
{
public:
    void NotifyDamageFrom(shared_ptr<FPAL_Character> attacker, int damage)
    {
        if (!attacker) return;
        HateTable[attacker] += damage;

        cout << "[HATE] " << attacker->CharacterID << " 가 " << damage
            << " 피해를 입힘 (누적: " << HateTable[attacker] << ")\n";
    }

    shared_ptr<FPAL_Character> GetHighestHateTarget()
    {
        shared_ptr<FPAL_Character> topTarget = nullptr;
        int maxHate = numeric_limits<int>::min();

        for (const auto& [attacker, totalHate] : HateTable)
        {
            if (totalHate > maxHate)
            {
                maxHate = totalHate;
                topTarget = attacker;
            }
        }
        if (topTarget)
        {
            cout << "[AI] 타겟 선정됨: " << topTarget->CharacterID
                << " (누적 헤이트: " << maxHate << ")\n";
        }

        return topTarget;
    }

    void ExecuteAttack()
    {
        auto target = GetHighestHateTarget();
        if (target)
        {
            cout << "[Action] 몬스터가 " << target->CharacterID 
                << " 를 공격합니다.\n";
        }
        else
        {
            cout << "[AI] 공격 대상이 없습니다.\n";
        }
    }

private:
    unordered_map<shared_ptr<FPAL_Character>, int,
        FPAL_CharacterHasher, FPAL_CharacterEqual> HateTable;
};

// ===== 테스트 =====
int main()
{
    auto playerA1 = make_shared<FPAL_Character>("PAL_Player_A", 150);
    auto playerA2 = make_shared<FPAL_Character>("PAL_Player_A", 150); // 동일 ID
    auto playerB = make_shared<FPAL_Character>("PAL_Player_B", 200);

    APAL_MonsterAIController monsterAI;

    monsterAI.NotifyDamageFrom(playerA1, 30);
    monsterAI.NotifyDamageFrom(playerB, 50);
    monsterAI.NotifyDamageFrom(playerA2, 40); // 동일 ID로 누적됨

    monsterAI.ExecuteAttack();

    return 0;
}
