// C++20
#include <iostream>
#include <string>

using namespace std;

struct Stats
{
    int atk = 0;
    int def = 0;
};

struct Avatar
{
    string look;
    Stats bonus;
};

struct Player
{
    string look = "Basic";
    Stats base{ 10, 10 };
    Stats total{ 10, 10 };

    void Equip(const Avatar& av)
    {
        look = av.look;
        total.atk = base.atk + av.bonus.atk;
        total.def = base.def + av.bonus.def;
    }
};

int main()
{
    Player p;
    Avatar angel{ "Angel Wings", { 5, 2 } };

    p.Equip(angel);

    cout << "Look: " << p.look << '\n';
    cout << "ATK: " << p.total.atk << '\n';
    cout << "DEF: " << p.total.def << '\n';

    return 0;
}
