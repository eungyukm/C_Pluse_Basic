// C++20
#include <iostream>
#include <string>
using namespace std;

struct Equipment
{
    string name;
    int level{ 0 };
};

bool Enhance(Equipment& eq, int& gold, int& material)
{
    if (gold < 100 || material < 1)
    {
        cout << "재료나 골드가 부족합니다." << endl;
        return false;
    }

    gold -= 100;
    material--;

    if (rand() % 100 < 70)
    {
        eq.level++;
        cout << eq.name << "강화 성공! +" << eq.level << endl;
        return true;
    }
    else
    {
        cout << eq.name << " 강화 실패..." << endl;
        return false;
    }
}

int main()
{
    srand((unsigned)time(nullptr));

    Equipment sword{ "초심자의 검" };
    int gold = 500;
    int material = 5;

    while (material > 0)
    {
        Enhance(sword, gold, material);
    }
}
