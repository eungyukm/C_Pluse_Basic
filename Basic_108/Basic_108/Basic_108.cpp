// c++ 20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item { string name; };
vector<Item> groundItems;

struct Pal
{
    string name;
    int hp = 100;
    vector<Item> equip;

    void Die()
    {
        cout << name << " died. " << endl;
        for (auto& item : equip)
        {
            cout << item.name << " dropped!" << endl;
            groundItems.push_back(item);
        }
    }
};

struct Player
{
    string name;
    vector<Item> inventory;

    void PickUp()
    {
        if (groundItems.empty())
        {
            cout << "Nothing to pick up." << endl;
            return;
        }
        auto item = groundItems.back();
        groundItems.pop_back();
        inventory.push_back(item);
        cout << name << " pipcked up " << item.name << "!" << endl;
    }
};
int main()
{
    Pal pal{ "Pengullet", 0, { {"Axe"}, {"Helmet"} } };
    Player player{ "You" };

    pal.Die();
    player.PickUp();
    player.PickUp();
    player.PickUp();

    return 0;
}
