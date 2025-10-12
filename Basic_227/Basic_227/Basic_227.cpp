// C++20
#include <iostream>
#include <random>
using namespace std;

struct GatherSkill
{
    int lv{ 1 };
    int exp{ 0 };
    int next{ 20 };
    void gain(int v)
    {
        exp += v;
        while (exp >= next)
        {
            exp -= next;
            lv++;
            next = 20 + lv * 10;
        }
    }
};

bool TryGather(GatherSkill& s, mt19937& rng)
{
    uniform_real_distribution<float> u(0.0f, 1.0f);
    if (u(rng) <= 0.7f)
    {
        s.gain(7);
        return true;
    }
    return false;
}

int main()
{
    mt19937 rng(random_device{}());
    GatherSkill skill;

    for (int i = 0; i < 12; i++)
    {
        bool ok = TryGather(skill, rng);
        cout << (ok ? "채집 성공 " : "실패    ")
            << "| LV:" << skill.lv
            << " EXP:" << skill.exp << "/" << skill.next << '\n';
    }
}
