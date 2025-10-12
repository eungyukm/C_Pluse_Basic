// C++ 20
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct BattleItem
{
    string Name;
    int Cooldown = 0;
    int CurrentCd = 0;

    bool TryActivate()
    {
        if (CurrentCd > 0)
        {
            return false;
        }
        CurrentCd = Cooldown;
        return true;
    }

    void Tick()
    {
        if (CurrentCd > 0)
        {
            CurrentCd--;
        }
    }
};

int main()
{
    unordered_map<string, BattleItem> items;
    items["TimeStop"] = { "TimeStop", 3, 0 };
    items["Whirlwind"] = { "Whirlwind", 2, 0 };

    auto tryUse = [&](const string& key)
        {
            if (items[key].TryActivate())
                cout << items[key].Name << " 발동!\n";
            else
                cout << items[key].Name << " 쿨다운 중\n";
        };

    tryUse("TimeStop"); // 발동
    tryUse("TimeStop"); // 쿨다운
    items["TimeStop"].Tick();
    items["TimeStop"].Tick();
    items["TimeStop"].Tick();
    tryUse("TimeStop"); // 다시 발동

    return 0;
}
