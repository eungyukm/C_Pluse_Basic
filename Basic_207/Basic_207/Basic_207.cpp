// C++20
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Equipment
{
    string setName;
};

struct Player
{
    vector<Equipment> equips;
    bool setEffect = false;

    void CheckSetEffect()
    {
        int count = 0;
        for (auto& e : equips)
        {
            if (e.setName == "Dragon")
            {
                count++;
            }
        }
        setEffect = (count >= 3);
    }
};

int main()
{
    Player p;
    p.equips.push_back({ "Dragon" });
    p.equips.push_back({ "Dragon" });
    p.equips.push_back({ "Dragon" });

    p.CheckSetEffect();
    cout << "세트 효과 : " << (p.setEffect ? "발동" : "없음") << endl;
    return 0;
}
