// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class Rarity { Common, Rare, Epic };

struct Equipment
{
    string name;
    Rarity rarity{ Rarity::Common };
};

struct Materials
{
    int shard{ 0 };
    int powder{ 0 };
};

Materials GetDismantleReward(const Equipment& eq)
{
    switch (eq.rarity)
    {
    case Rarity::Common: return { 3, 1 };
    case Rarity::Rare:   return { 7, 3 };
    case Rarity::Epic:   return { 15, 6 };
    }
    return { 0,0 };
}

bool Dismantle(vector<Equipment>& inv, size_t idx, Materials& mat)
{
    if (idx >= inv.size())
    {
        cout << "대상이 없습니다." << endl;
        return false;
    }

    Materials r = GetDismantleReward(inv[idx]);
    mat.shard += r.shard;
    mat.powder += r.powder;

    cout << inv[idx].name << " 분해 완료 -> Shard +" << r.shard
        << ", Powder +" << r.powder << endl;
}

int main()
{
    vector<Equipment> inventory =
    {
        {"낡은 검", Rarity::Common},
        {"서리 도끼", Rarity::Rare},
        {"황혼의 창", Rarity::Epic}
    };

    Materials bag{};

    // 첫 번째 아이템부터 순서대로 해체 (로스트아크: 아이템 분해 → 재료 반환)
    for (size_t i = 0; i < inventory.size();)
    {
        Dismantle(inventory, i, bag) ? i : i++;
    }

    cout << "보유 재료: Shard " << bag.shard 
        << ", Powder " << bag.powder << "\n";
}
