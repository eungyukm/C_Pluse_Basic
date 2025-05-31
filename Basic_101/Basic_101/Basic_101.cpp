// C++ 20
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

using Inventory = unordered_map<string, int>;

struct BuildingPlan
{
    string name;
    unordered_map<string, int> requiredMaterials;

    bool CanBuild(const Inventory& inventory) const
    {
        for (const auto& [mat, amt] : requiredMaterials)
        {
            if (inventory.find(mat) == inventory.end() ||
                inventory.at(mat) < amt)
            {
                return false;
            }
        }
        return true;
    }

    void Build(Inventory& inventory) const
    {
        if (!CanBuild(inventory))
        {
            cout << "Not enough materials to build "
                << name << "!" << endl;
            return;
        }

        for (const auto& [mat, amt] : requiredMaterials)
        {
            inventory[mat] -= amt;
        }

        cout << name << " has been successfully built!"
            << endl;
    }

    void ShowRequirements() const
    {
        cout << "[Plan] " << name << " requires:" << endl;
        for (const auto& [mat, amt] : requiredMaterials)
        {
            cout << " - " << mat << ": " << amt << endl;
        }
        cout << endl;
    }
};

void ShowInventory(const Inventory& inv)
{
    cout << "[Inventory]" << endl;
    for (const auto& [item, count] : inv)
    {
        cout << " - " << item << ": " << count << endl;
    }
    cout << endl;
}

int main()
{
    Inventory playerInventory = {
        { "Wood", 10 },
        { "Stone", 6 },
        { "Fiber", 4 }
    };

    vector<BuildingPlan> buildOptions = {
        { "Wooden Hut", { { "Wood", 6 }, { "Fiber", 2 } } },
        { "Stone Furnace", { { "Stone", 5 }, { "Wood", 2 } } }
    };

    ShowInventory(playerInventory);

    for (const auto& plan : buildOptions)
    {
        plan.ShowRequirements();
        plan.Build(playerInventory);
        ShowInventory(playerInventory);
    }
}
