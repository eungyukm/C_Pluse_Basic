// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Unit
{
    string name;
    bool isAlly{};
    bool inCombat{};
    bool buffed{};
};

void UseMagicCircle(Unit& caster, vector<Unit>& party)
{
    if (!caster.inCombat)
    {
        return;
    }
    for (auto& u : party)
    {
        if (u.isAlly)
        {
            u.buffed = true;
        }
    }
}

int main()
{
    Unit caster{ "Mage", true, true };
    vector<Unit> party{ caster, { "Warrior", true, true }, 
        { "Rogue", true, true } 
    };

    UseMagicCircle(caster, party);

    for (auto& u : party)
        cout << u.name << ": " 
        << (u.buffed ? "Buffed" : "None") << endl;

    return 0;
}
