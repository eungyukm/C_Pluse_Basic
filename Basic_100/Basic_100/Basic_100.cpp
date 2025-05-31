#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

using Inventory = unordered_map<string, int>;

struct Recipe
{
    string itemName;
    unordered_map<string, int> requiredMaterials;

    bool CanCraft(const Inventory& inventory) const
    {
        for (const auto& [material, amount] : requiredMaterials)
        {
            if (inventory.find(material) == inventory.end()
                || inventory.at(material) < amount)
            {
                return false;
            }
        }
        return true;
    }

    void Craft(Inventory& inventory) const
    {
        if (!CanCraft(inventory))
        {
            cout << "Not enough materials to carft" << itemName << "!" << endl;
            return;
        }
        for (const auto& [material, amount] : requiredMaterials)
        {
            inventory[material] -= amount;
        }
        cout << itemName << " has been crafted!" << endl;
    }

    void ShowRequirements() const
    {
        cout << "To craft " << itemName << ": ";
        for (const auto& [mat, amt] : requiredMaterials)
        {
            cout << mat << " x" << amt << " ";
        }
        cout << endl;
    }
};

void ShowInventory(const Inventory& inv)
{
    cout << "Current Inventory:\n";
    for (const auto& [item, count] : inv)
    {
        cout << " - " << item << ": " << count << endl;
    }
    cout << endl;
}

int main()
{
    Inventory playerInventory = {
        { "Wood", 5 },
        { "Stone", 3 },
        { "Fiber", 2 }
    };

    Recipe axeRecipe = {
        "Axe",
        {
            { "Wood", 3 },
            { "Stone", 2 }
        }
    };

    ShowInventory(playerInventory);
    axeRecipe.ShowRequirements();

    axeRecipe.Craft(playerInventory); // 성공
    ShowInventory(playerInventory);

    axeRecipe.Craft(playerInventory); // 실패
}
