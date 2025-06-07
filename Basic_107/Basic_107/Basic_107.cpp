// C++ 20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item
{
    string name;
};

struct Pal
{
    string name;
    int health = 100;
    vector<Item> equipment;

    void TakeDamage(int dmg)
    {
        health -= dmg;
        cout << name << " took " << dmg << " damage. (HP: "
            << health << ")" << endl;

        if (health <= 0)
        {
            Die();
        }
    }

    void Die()
    {
        cout << name << " has died." << endl;
        for (const auto& item : equipment)
        {
            cout << item.name << " dropped on the ground!" << endl;
        }
        equipment.clear();
    }

    void ShowStatus()
    {
        cout << name << " | HP: " << health << " | Equip: ";
        for (const auto& item : equipment)
        {
            cout << item.name << " ";
        }
        cout << endl;
    }
};
int main()
{
    Pal daedream{ "Daedream", 50 };
    daedream.equipment = {
        {{"Wooden Sowrd"}, {"Berry Pouch"}}
    };
    daedream.ShowStatus();
    daedream.TakeDamage(30);
    daedream.TakeDamage(25);// 사망
    return 0;
}