// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Player
{
    string name;
    int ilvl;
    bool ready;
};

bool CanEnterLegionRaid(const vector<Player>& party, 
    int requireIlvl, int minCount)
{
    cout << "[군단장 레이드 매칭]\n";
    if (party.size() < minCount)
    {
        cout << " 인원 부족 " << party.size()
            << " / " << minCount << endl;
        return false;
    }

    for (int i = 0; i < party.size(); i++)
    {
        const Player& p = party[i];
        if (p.ilvl < requireIlvl)
        {
            cout << " 아이템 레벨 부족" << p.name
                << " ilvl " << p.ilvl << " / "
                << requireIlvl << endl;
            return false;
        }

        if (!p.ready)
        {
            cout << " 준비 안됨: " << p.name << endl;
            return false;
        }
    }
    cout << "  조건 충족 입장 가능\n";
    return true;
}

int main()
{
    vector<Player> party
    {
        {"Leader", 1540, true},
        {"Dps1", 1520, true},
        {"Dps2", 1510, true}
    };

    int requireIlvl = 1500;
    int minCount = 3;

    if (CanEnterLegionRaid(party, requireIlvl, minCount))
    {
        cout << ">> 군단장 레이드 입장\n";
    }
    else
    {
        cout << ">> 입장 불가 매칭 대기 유지\n";
    }
    return 0;
}
