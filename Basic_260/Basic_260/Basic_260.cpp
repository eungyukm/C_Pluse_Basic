// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct GuildMember
{
    string name;
    int contribution{ 0 };   // 길드 기여도
};

struct GuildShopItem
{
    int id;
    string name;
    int cost;                // 필요 기여도
    int stock;               // 남은 수량
};

bool TryBuyGuildShopItem(GuildMember& m, GuildShopItem& item)
{
    if (item.stock <= 0)
    {
        cout << item.name << " 품절" << endl;
        return false;
    }

    if (m.contribution < item.cost)
    {
        cout << m.name << " 기여도 부족 "
            << "현재 " << m.contribution
            << " 필요 " << item.cost << endl;
        return false;
    }

    m.contribution -= item.cost;
    item.stock--;

    cout << m.name << " " << item.name << " 구매 성공 "
        << "기여도 남음 " << m.contribution
        << " 아이템 재고 " << item.stock << endl;
    return true;
}

int main()
{
    GuildMember me{ "Obliy", 120 };
    GuildShopItem potion{ 1, "길드 전투 물약", 50, 2 };
    GuildShopItem box{ 2, "길드 상자", 100, 1 };

    TryBuyGuildShopItem(me, potion);
    TryBuyGuildShopItem(me, box);
    TryBuyGuildShopItem(me, box);

    return 0;
}
