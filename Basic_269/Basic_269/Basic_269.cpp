// C++20
using namespace std;

#include <iostream>
#include <string>

struct Player
{
    int level = 1;
    bool hasTitle = false;
    string equippedTitle = "None";
};
void CheckAndGrantTitle(Player& p)
{
    if (p.level >= 50 && p.hasTitle == false)
    {
        p.hasTitle = true;
        cout << "칭호 획득: 성장한 모험가" << endl;
    }
}

void EquipTitle(Player& p)
{
    if (p.hasTitle == false)
    {
        cout << "장착 실패 : 칭호 없음" << endl;
        return;
    }

    p.equippedTitle = "성장한 모험가";
    cout << "칭호 장착 완료" << endl;
}

int main()
{
    Player p;

    cout << "현재 레벨: " << p.level << endl;

    p.level = 50;

    CheckAndGrantTitle(p);
    EquipTitle(p);

    cout << "장착 칭호: " << p.equippedTitle << endl;

    return 0;
}