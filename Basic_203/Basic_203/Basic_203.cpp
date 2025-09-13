// C++20
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Player
{
    unordered_map<string, int> owned;     // 세트명 → 보유 수량
    unordered_set<string> setEffects;     // 적용된 세트 효과명

    void ApplySetEffects(const unordered_map<string, int>& require)
    {
        for (auto& kv : require)
        {
            if (owned[kv.first] >= kv.second)
            {
                setEffects.insert(kv.first + "_SetEffect");
            }
        }
    }
};

int main()
{
    Player p;
    // 예시 보유 : 워리어 2개, 메이지 1개
    p.owned["Warrior"] = 2;
    p.owned["Mage"] = 1;

    //세트 요구 조건 : 워리어 2개, 메이지 3개
    unordered_map<string, int> need{ {"Warrior", 2}, {"Mage", 3} };
    p.ApplySetEffects(need);

    for (auto& name : p.setEffects)
        cout << name << "\n";

    return 0;
}
