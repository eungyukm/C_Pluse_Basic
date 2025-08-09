// C++20
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 기술 이름 정의
enum class ETechType
{
    WoodWorking,
    MetalCraft,
    Cooking,
    Alchemy
};

// 아이템 구조체
struct FCraftableItem
{
    string Name;
    unordered_set<ETechType> RequiredTechs;

    FCraftableItem(string name, initializer_list<ETechType> techs)
        : Name(name), RequiredTechs(techs) {}
};

// 플레이어 클래스
class FPlayer
{
public:
    unordered_set<ETechType> OwnedTechs;

    void LearnTech(ETechType tech)
    {
        OwnedTechs.insert(tech);
    }

    vector<FCraftableItem> FilterCraftableItems
    (const vector<FCraftableItem>& allItems) const
    {
        vector<FCraftableItem> result;

        for (const auto& item : allItems)
        {
            bool canCraft = true;
            for (const auto& requiredTech : item.RequiredTechs)
            {
                if (!OwnedTechs.contains(requiredTech))
                {
                    canCraft = false;
                    break;
                }
            }

            if (canCraft)
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

// 출력 함수
void PrintCraftableItems(const vector<FCraftableItem>& items)
{
    for (const auto& item : items)
    {
        cout << "- " << item.Name << endl;
    }
}

int main()
{
    // 전체 아이템 목록
    vector<FCraftableItem> allItems = {
        { "Wooden Spear", { ETechType::WoodWorking } },
        { "Iron Sword", { ETechType::MetalCraft } },
        { "Healing Potion", { ETechType::Alchemy } },
        { "Cooked Meat", { ETechType::Cooking } },
        { "Enchanted Spear", { ETechType::WoodWorking, ETechType::Alchemy } }
    };

    // 플레이어가 보유한 기술
    FPlayer player;
    player.LearnTech(ETechType::WoodWorking);
    player.LearnTech(ETechType::Alchemy);

    cout << "[제작 가능한 아이템 목록]" << endl;
    vector<FCraftableItem> availableItems = 
        player.FilterCraftableItems(allItems);
    PrintCraftableItems(availableItems);

    return 0;
}
