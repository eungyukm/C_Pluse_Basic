// C++20
#include <iostream>
#include <string>
using namespace std;

struct Equipment
{
    string name;
    int enhance{ 0 }; // 현재 강화 수치
    int cap{ 15 };    // 장비 최대 강화 한도
};

// 승계: 이전 장비의 강화 수치를 새 장비에 계승(한도까지만), 골드 소모
bool InheritEnhance(Equipment& from, Equipment& to, 
    int& gold, int costPerLevel = 100)
{
    if (from.enhance <= 0)
    {
        cout << "승계할 강화 수치가 없습니다." << endl;
        return false;
    }

    int transferable = min(from.enhance, to.cap - to.enhance);
    if (transferable <= 0)
    {
        cout << "대상 장비가 이미 한도입니다." << endl;
        return false;
    }

    int needGold = transferable * costPerLevel;
    if (gold < needGold)
    {
        cout << "골드가 부족합니다. " << needGold << endl;
        return false;
    }

    for (int i = 0; i < transferable; i++)
    {
        gold -= costPerLevel;
        to.enhance++;
    }
    from.enhance = 0;
    cout << "승계 완료: " << to.name << " +" << to.enhance
        << " (골드 남음 " << gold << ")\n";
    return true;
}

int main()
{
    Equipment oldWpn{ "구식 장검", 7, 15 };
    Equipment newWpn{ "신형 장검", 0, 5 };

    int gold = 1000;

    // 장비 승계 → 이전 강화 수치 계승(로스트 아크 로직 예시)
    InheritEnhance(oldWpn, newWpn, gold);

    cout << oldWpn.name << " 남은 강화: +" << oldWpn.enhance << "\n";
    cout << newWpn.name << " 최종 강화: +" << newWpn.enhance << "\n";
}
