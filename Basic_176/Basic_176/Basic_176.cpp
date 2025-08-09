// C++20
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

enum class EItemType
{
    Weapon,
    Armor,
    Consumable,
    Material,
    Etc
};

enum class ERarity : int
{
    Common = 1,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

struct FItem
{
    EItemType Type{};
    ERarity   Rarity{ ERarity::Common };
    string    Name;

    void Print() const
    {
        // enum class는 자동으로 정수형으로 변환되지 않기 때문에
        // 명시적으로 변환
        cout << "[Type:" << static_cast<int>(Type)
            << " Rarity:" << static_cast<int>(Rarity)
            << " Name:" << Name << "]\n";
    }
};

// 정렬 키: 종류(오름차순) → 등급(내림차순) → 이름(오름차순)
static inline auto MakeKey(const FItem& it)
{
    // 등급을 내림차순 만들기 위해 음수화
    return make_tuple(static_cast<int>(it.Type),
        -static_cast<int>(it.Rarity),
        it.Name);
}

void InsertionSortInventory(vector<FItem>& items)
{
    for (size_t i = 1; i < items.size(); i++)
    {
        FItem key = items[i];
        auto keyK = MakeKey(key);

        size_t j = i;
        while (j > 0 && MakeKey(items[j - 1]) > keyK)
        {
            items[j] = items[j - 1];
            j--;
        }
        items[j] = key;
    }
}

int main()
{
    vector<FItem> inventory
    {
        { EItemType::Weapon,     ERarity::Rare, "Iron Sword" },
        { EItemType::Armor,      ERarity::Epic, "Dragon Helm" },
        { EItemType::Consumable, ERarity::Common, "Apple" },
        { EItemType::Weapon,     ERarity::Legendary, "Sky Blade" },
        { EItemType::Weapon,     ERarity::Rare, "Azure Dagger" },
        { EItemType::Armor,      ERarity::Rare, "Knight Armor" },
        { EItemType::Consumable, ERarity::Epic, "Elixir" },
        { EItemType::Material,   ERarity::Uncommon, "Copper Ore" },
        { EItemType::Material,   ERarity::Legendary, "Ancient Core" }
    };

    InsertionSortInventory(inventory);

    for (const auto& it : inventory)
    {
        it.Print();
    }
    return 0;
}
