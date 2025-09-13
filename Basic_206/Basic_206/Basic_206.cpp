// C++20
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card
{
    string name;
};

struct Player
{
    vector<Card> deck;
    bool setEffect = false;

    void CheckSetEffect()
    {
        setEffect = false;
        int cnt = 0;
        for (auto& c : deck)
        {
            if (c.name == "Light" || c.name == "Dark")
            {
                cnt++;
            }
            if (cnt >= 2)
            {
                setEffect = true;
            }
        }
    }
};

int main()
{
    Player p;
    p.deck.push_back({ "Light" });
    p.deck.push_back({ "Dark" });

    p.CheckSetEffect();
    cout << "카드 세트 효과: " << (p.setEffect ? "활성화" : "없음") 
        << '\n';

    return 0;
}
