// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player
{
    vector<string> inventory;

    void AddFish(const string& fish)
    {
        inventory.push_back(fish);
    }

    void ShowInventory() const
    {
        cout << "획득한 물고기: ";
        for (int i = 0; i < inventory.size(); i++)
        {
            cout << inventory[i] << (i + 1 < inventory.size() ?
                ", " : "\n");
        }
    }
};

struct Fishing
{
    void TryFishing(Player& p)
    {
        p.AddFish("붉은 잉어");
        cout << "낚시에 성공했습니다!" << endl;
    }
};

int main()
{
    Player p;
    Fishing f;

    f.TryFishing(p); // 낚시 시도
    f.TryFishing(p); // 두 번 시도

    p.ShowInventory();
    return 0;
}
