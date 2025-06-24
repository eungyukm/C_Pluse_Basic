#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class PalType
{
    Aggressive,
    Passive
};

struct Pal
{
    string name;
    PalType type;

    void OnDetectThreat(bool gotHit)
    {
        if (type == PalType::Aggressive)
        {
            cout << name << " attacks first!" << endl;
        }
        else if (type == PalType::Passive && gotHit)
        {
            cout << name << " couterattacks!" << endl;
        }
        else
        {
            cout << name << " stays calm." << endl;
        }
    }
};
int main()
{
    Pal goblin{ "Goblin", PalType::Aggressive };
    Pal sheep{ "Sheep", PalType::Passive };

    cout << "== Threat Detected ==" << endl;
    goblin.OnDetectThreat(false); // 선공
    sheep.OnDetectThreat(false);  // 공격 안 당함
    sheep.OnDetectThreat(true);   // 반격
}
