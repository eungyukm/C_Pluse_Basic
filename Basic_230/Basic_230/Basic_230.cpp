// C++20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Buff
{
    int atk{ 0 };
    int def{ 0 };
    int left{ 0 }; // 남은 턴
};

struct Player
{
    int baseAtk{ 10 };
    int baseDef{ 5 };
    vector<Buff> buffs;

    void UseFood(const Buff& b) { buffs.push_back(b); }

    int Atk() const
    {
        int v = baseAtk;
        for (auto& b : buffs)
        {
            v += b.atk;
        }
        return v;
    }
    int Def() const
    {
        int v = baseAtk;
        for (const auto& b : buffs)
        {
            v += b.def;
        }
        return v;
    }
    void Tick()
    {
        for (auto& b : buffs)
        {
            b.left--;
        }

        buffs.erase(remove_if(buffs.begin(), buffs.end(),
            [](const Buff& b)
            {
                return b.left <= 0;
            }),
            buffs.end()
        );
    }
};

int main()
{
    Player you;
    Buff Stew{ +3, +1, 3 };    // 3턴 동안 공격+3, 방어+1
    Buff Skewer{ +1, +2, 2 };  // 2턴 동안 공격+1, 방어+2

    you.UseFood(Stew); // 시작에 스튜 사용

    for (int t = 0; t < 5; t++)
    {
        if (t == 2) you.UseFood(Skewer); // 2턴에 꼬치 사용
        cout << "턴 " << t << " | ATK:" << you.Atk()
            << " DEF:" << you.Def()
            << " 버프수:" << you.buffs.size() << '\n';
        you.Tick();
    }
}