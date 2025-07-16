// C++20
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

using f32 = float;

struct Buff
{
    string name;
    f32 timeLeft;

    Buff(const string& name, f32 duration)
        : name(name), timeLeft(duration) {}

    void Tick(f32 dt) { timeLeft -= dt; }
    bool IsExpired() const { return timeLeft <= 0.0f; }
};

struct Pal
{
    vector<Buff> buffs;

    void AddBuff(const string& name, f32 duration)
    {
        buffs.emplace_back(name, duration);
        cout << name << " 버프가 적용되었습니다. (" << duration << "초)" << endl;
    }

    void Tick(f32 dt)
    {
        for (auto& buff : buffs)
        {
            buff.Tick(dt);
        }

        // 만료된 버프 제거
        buffs.erase(remove_if(buffs.begin(), buffs.end(),
            [](const Buff& b)
            {
                if (b.IsExpired())
                {
                    cout << b.name << "버프가 종료되었습니다." << endl;
                    return true;
                }
                return false;
            }),
            buffs.end());
    }

    void ShowBuffs() const
    {
        for (const auto& b : buffs)
            cout << "- " << b.name << ": " << b.timeLeft << "초 남음" << endl;
    }
};

int main()
{
    Pal pal;
    pal.AddBuff("공격력 증가", 3.0f);
    pal.AddBuff("방어력 감소", 5.0f);

    for (int i = 0; i < 6; ++i)
    {
        cout << "\n[시간 경과: " << i << "초]" << endl;
        pal.Tick(1.0f);
        pal.ShowBuffs();
    }

    return 0;
}
