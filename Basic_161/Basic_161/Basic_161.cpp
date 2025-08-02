// C++20
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item
{
    string Name;
    int Count;
};

struct FVector
{
    float X, Y, Z;
};

class Player
{
public:
    int HP = 100;
    FVector Location = { 0, 0, 0 };
    vector<Item> Inventory;

    void TakeDamage(int damage)
    {
        HP -= damage;
        cout << "피해: " << damage << " -> HP: " << HP << endl;

        if (HP <= 0)
        {
            DropAllItems();
        }
    }

    void DropAllItems()
    {
        cout << "[사망] 아이템 드롭 중..." << endl;
        for (const auto& item : Inventory)
        {
            cout << item.Name << " x" << item.Count
                << " 드롭됨 at (" << Location.X << ", "
                << Location.Y << ", " << Location.Z << ")" << endl;
        }
        Inventory.clear();
    }
};

int main()
{
    Player player;
    player.Location = { 100, 200, 300 };
    player.Inventory.push_back({ "나무", 5 });
    player.Inventory.push_back({ "돌", 3 });

    player.TakeDamage(120); // 체력 0 이하 → 아이템 드롭

    return 0;
}
