// C++20 기준
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Buff
{
    string name;
    int duration;       // 지속 턴 수
    float attackModifier; // 공격력 배율 (예: 1.5배, 0.8배)

    Buff(const string& n, int d, float mod)
        : name(n), duration(d), attackModifier(mod)
    {
    }
};

struct Unit
{
    string name;
    int baseAttack;
    vector<Buff> buffs;

    Unit(const string& n, int atk)
        : name(n), baseAttack(atk)
    {
    }

    float GetModifiedAttack() const
    {
        float modifier = 1.0f;
        for (const auto& buff : buffs)
        {
            modifier *= buff.attackModifier;
        }
        return baseAttack * modifier;
    }

    void ApplyBuff(const Buff& buff)
    {
        buffs.push_back(buff);
        cout << name << "에게 " << buff.name << " 버프 적용! ("
            << buff.duration << "턴, 배율 " 
            << buff.attackModifier << ")\n";
    }

    void EndTurn()
    {
        for (auto& buff : buffs)
        {
            buff.duration--;
        }

        // 지속 시간이 끝난 버프 제거
        buffs.erase(
            remove_if(buffs.begin(), buffs.end(),
                [](const Buff& b)
                {
                    return b.duration <= 0;
                }),
            buffs.end()
        );
    }

    void PrintStatus() const
    {
        cout << name << " 공격력: " << GetModifiedAttack() << " (기본: "
            << baseAttack << ")" << endl;
        if (!buffs.empty())
        {
            cout << " -> 활성 버프: ";
            for (const auto& buff : buffs)
            {
                cout << buff.name << "(" << buff.duration << "턴) ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Unit garen("Garen", 100);

    garen.PrintStatus();

    // 버프 적용
    garen.ApplyBuff(Buff("분노", 2, 1.5f)); // 1.5배 공격력, 2턴

    // 턴 진행
    for (int i = 1; i <= 3; i++)
    {
        cout << "\n턴 " << i << " 시작\n";
        garen.PrintStatus();
        garen.EndTurn();
    }
}
