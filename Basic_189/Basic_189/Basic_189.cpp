// C++20
#include <iostream>
#include <string>
using namespace std;

struct Skill
{
    string name;
    float cooldown;
    float currentCD;

    Skill(string n, float cd) : 
        name(n), cooldown(cd), currentCD(0) 
    {
    }

    bool CanUse() const
    {
        return currentCD <= 0;
    }

    void Use()
    {
        if (CanUse())
        {
            cout << name << " 스킬 사용!" << endl;
            currentCD = cooldown;
        }
        else
        {
            cout << name << "은 아직"
                << currentCD << "초 남음" << endl;
        }
    }

    void Tick(float delta)
    {
        if (currentCD > 0)
        {
            currentCD -= delta;
        }
        if (currentCD < 0)
        {
            currentCD = 0;
        }
    }
};

int main()
{
    Skill skill("파이어볼", 5.0f);

    skill.Use();
    for (int i = 0; i < 6; i++)
    {
        skill.Tick(1.0f);
        skill.Use();
    }
}
