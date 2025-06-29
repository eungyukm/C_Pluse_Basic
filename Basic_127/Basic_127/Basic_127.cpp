// C++20
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pal
{
    string name;
    string type;
    bool isFighting = false;

    void Help()
    {
        if (!isFighting)
        {
            isFighting = true;
            cout << name << " joins the fight!" << endl;
        }
    }
};

vector<Pal> pals;

void RequestHelp(const Pal& attackedPal)
{
    cout << attackedPal.name << " is under attack! Requesting help..." << endl;
    for (auto& pal : pals)
    {
        if (pal.type == attackedPal.type && !pal.isFighting)
        {
            pal.Help();
        }
    }
}
int main()
{
    pals = { {"Pengullet", "Ice"}, {"Pengu", "Ice"}, {"Foxparks", "Fire"} };

    Pal& target = pals[0]; // Pengullet이 공격받음
    RequestHelp(target);
}
