// C++ 20
#include <iostream>
#include <string>
#include <optional>
#include <ctime>
using namespace std;

struct SecretMap { int tier{ 1 }; 
time_t expireAt{ 0 }; string zone{ "Field_A" }; int uses{ 1 }; };
struct Player { bool leader{ true }; 
string zone{ "Field_A" }; bool inCombat{ false }; 
optional<SecretMap> map; };

bool TryEnterHiddenDungeon(Player& p, string& key)
{
    if (!p.map)
    {
        return false;
    }
    if (!p.leader || p.inCombat)
    {
        return false;
    }
    if (time(nullptr) > p.map->expireAt)
    {
        return false;
    }
    if (p.zone != p.map->zone)
    {
        return false;
    }

    static int seq = 0;
    key = "HiddenDungeon_T" + to_string(p.map->tier) +
        "_#" + to_string(seq++);

    if (p.map->uses > 0)
    {
        p.map->uses--;
    }

    if (p.map->uses == 0)
    {
        p.map.reset();
    }
    return true;
}

int main()
{
    Player me;
    me.map = SecretMap{ 2, time(nullptr) + 3600, "Field_A", 1 };

    string instanceKey;
    if (TryEnterHiddenDungeon(me, instanceKey))
    {
        cout << "Enter Hidden Dungeon | key "
            << instanceKey << "\n";
    }
    else
    {
        cout << "Cannot use secret map.\n";
    }
}
