// C++20
#include <iostream>
#include <string>
using namespace std;

enum class eOPTION { None, PowerUp, Swift };

struct Skill
{
    string name;
    int damage;
    float cooldown;
};

Skill ApplyOption(Skill s, eOPTION opt)
{
    if (opt == eOPTION::PowerUp)
    {
        s.damage += 50;
    }
    else if (opt == eOPTION::Swift)
    {
        s.cooldown -= 2.0f;
    }
    return s;
}

int main()
{
    Skill spin{ "스핀 커터", 100, 8.0f };

    Skill a = ApplyOption(spin, eOPTION::PowerUp);
    Skill b = ApplyOption(spin, eOPTION::Swift);

    cout << a.name << " PowerUp -> 데미지: " << a.damage
        << ", 쿨다운 : " << a.cooldown << "s\n";

    cout << b.name << " Swift -> 데미지: " << b.damage
        << ", 쿨다운 : " << b.cooldown << "s\n";

    return 0;
}
