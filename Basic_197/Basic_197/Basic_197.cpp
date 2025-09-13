// C++20
#include <iostream>
#include <string>
using namespace std;

struct Item
{
    string name;
};

struct Player
{
    void GetItem(const Item& item)
    {
        cout << "획득: " << item.name << endl;
    }
};

struct Monster
{
    Item Drop()
    {
        return { "드롭 장비" };
    }
};

struct Quest
{
    Item Reward()
    {
        return { "퀘스트 보상 장비" };
    }
};
int main()
{
    Player player;
    Monster monster;
    Quest quest;

    player.GetItem(monster.Drop());
    player.GetItem(quest.Reward());
    return 0;
}
