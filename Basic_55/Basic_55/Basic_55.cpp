#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 드랍 아이템 구조체
struct DropItem
{
    string name;
    int chance; // 확률 (%)
};

// 몬스터 구조체
struct Monster
{
    string name;
    vector<DropItem> drops;
};

void DropItems(const Monster& monster)
{
    cout << "monster.name <<  처치!"<< endl;
    bool anyDrop = false;

    for (const auto& item : monster.drops)
    {
        int roll = rand() % 100;
        if (roll < item.chance)
        {
            cout << item.name << " 드랍!" << endl;
            anyDrop = true;
        }
    }

    if (!anyDrop)
    {
        cout << "아무것도 안 나옴.." << endl;
    }
}

int main() {
    srand((unsigned)time(0));

    // 몬스터 데이터 세팅
    vector<Monster> monsters = {
        {"슬라임", {{"힐 포션", 70}}},
        {"고블린", {{"무기 파편", 50}, 
        {"골드", 30}}},
        {"드래곤", {{"전설의 검", 40}, 
        {"희귀 방어구", 50}, {"골드", 60}}}
    };

    cout << "몬스터 처치 시작!\n";

    for (const auto& m : monsters)
    {
        DropItems(m);
    }
}