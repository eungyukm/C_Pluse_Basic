// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item
{
    string name;
};

struct Chest
{
    string name;
    int capacity;
    vector<Item> items;

    bool store(const Item& item)
    {
        if (items.size() < capacity)
        {
            items.push_back(item);
            cout << "Stored " << item.name << " in " << name << endl;
            return true;
        }
        return false;
    }
};

struct AI
{
    void storeItem(const Item& item, vector<Chest>& chests)
    {
        for (auto& chest : chests)
        {
            if (chest.store(item))
            {
                return;
            }
        }
        cout << "No space for " << item.name << endl;
    }
};
int main()
{
    vector<Chest> chests = {
        {"WoodenChest", 2},
        {"MetalChest", 3}
    };

    vector<Item> items = {
        {"Wheat"}, {"Berry"}, {"Stone"}, {"Iron"}, {"Honey"}
    };

    AI ai;
    for (const auto& item : items)
    {
        ai.storeItem(item, chests);
    }

    return 0;
}
