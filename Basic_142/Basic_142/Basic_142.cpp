// C++ 20
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item
{
    string name;
    float speedBonus;
};

struct Pal
{
    string name;
    float baseSpeed = 5.0f;
    float currentSpeed = 5.0f;
    Item* equippedSaddle = nullptr;

    void UpdateStats()
    {
        currentSpeed = baseSpeed;
        if (equippedSaddle)
        {
            currentSpeed += equippedSaddle->speedBonus;
        }
    }

    void Equip(Item* item)
    {
        if (item)
        {
            equippedSaddle = item;
            UpdateStats();
            cout << name << " equipped " << item->name
                << ". Speed: " << currentSpeed << endl;
        }
    }

    void Unequip()
    {
        if (equippedSaddle)
        {
            equippedSaddle = nullptr;
            UpdateStats();
            cout << name << " unequipped " << " Speed: " << currentSpeed << endl;
        }
    }
};

int main()
{
    Item saddle = { "Swift Saddle", 2.5f };
    Pal pal = { "Pengullet" };

    pal.Equip(&saddle);
    pal.Unequip();
}
