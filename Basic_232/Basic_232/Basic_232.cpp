// C++20
#include <iostream>
#include <vector>
using namespace std;

struct Quest
{
    string title;
    int need;
    int prog{ 0 };
    int goldReward;
    string itemReward;

    bool DoWork()
    {
        if (prog >= need)
        {
            cout << "이미 완료한 의뢰입니다.\n";
            return false;
        }
        prog++;
        cout << title << " 진행 " 
            << prog << " / " << need << '\n';
        return true;
    }

    bool IsDone() const { return prog >= need; }
};

struct Player
{
    int gold{ 0 };
    vector<string> bag;

    void ReceiveReward(int g, const string& item)
    {
        gold += g;
        if (!item.empty())
        {
            bag.push_back(item);
            cout << "보상 획득! 골드 " << g << ", 아이템: " <<
                item << '\n';
            cout << "현재 골드: " << gold << ", 가발 크기: "
                << bag.size() << '\n';
        }
    }
};

struct NPC
{
    string name;
    Quest GiveQuest()
    {
        cout << name << ": 생활 의뢰를 부탁하네.\n";
        return Quest{ "약초 3개 채집", 3, 0, 50, "생활 포션" };
    }

    void GrantReward(Player& p, Quest& q)
    {
        if (!q.IsDone())
        {
            cout << name << ": 아직 완료하지 않았군.\n";
            return;
        }
        p.ReceiveReward(q.goldReward, q.itemReward);
        cout << name << ": 수고했네!\n";
    }
};

int main()
{
    Player you{};
    NPC npc{ "마을 장로" };
    auto q = npc.GiveQuest();

    while (!q.IsDone())
    {
        q.DoWork();
    }

    npc.GrantReward(you, q);
    return 0;
}
