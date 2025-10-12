// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player
{
    int meat{ 2 }, herb{ 2 }, water{ 2 }, spice{ 1 };
    int stew{ 0 }, skewer{ 0 };
};

bool Consume(Player& p, int m, int h, int w, int s)
{
    if (p.meat < m || p.herb < h || p.water < w || p.spice < s)
    {
        return false;
    }
    p.meat -= m; p.herb -= h; p.water -= w; p.spice -= s;
    return true;
}

bool CraftFood(Player& p, const string& recipe)
{
    if (recipe == "Stew") // 고기스튜: 고기1, 허브1, 물1 -> 스튜+1
    {
        if (!Consume(p, 1, 1, 1, 0))
        {
            return false;
        }
        p.stew++;
        return true;
    }
    if (recipe == "Skewer") // 고기꼬치: 고기1, 향신료1 -> 꼬치+1
    {
        if (!Consume(p, 1, 0, 0, 1))
        {
            return false;
        }
        p.skewer++;
        return true;
    }
    return false;
}

int main()
{
    Player you;
    vector<string> queue = { "Stew", "Skewer", "Stew" };

    for (int i = 0; i < queue.size(); i++)
    {
        bool ok = CraftFood(you, queue[i]);
        cout << (ok ? "제작 성공: " : "재료 부족: ") 
            << queue[i] << '\n';
    }

    cout << "보유 재료  고기:" << you.meat 
        << " 허브:" << you.herb
        << " 물:" << you.water << " 향신료:" 
        << you.spice << '\n';
    cout << "완성 음식  스튜:" << you.stew << " 꼬치:" 
        << you.skewer << '\n';
}
