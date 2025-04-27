#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// 드랍 아이템 구조체
struct DropItem {
    string name;
    int chance; // 확률 (%)
};

// 몬스터 구조체
struct Monster {
    string name;
    vector<DropItem> drops;
};

void dropItem(const Monster& monster)
{
    cout << monster.name << " 처치!" << endl;

    int roll = rand() % 100;
    int accumulated = 0;

    for (const auto& item : monster.drops)
    {
        accumulated += item.chance;
        if (roll < accumulated)
        {
            cout << item.name << " 드랍" << endl;
            return;
        }
    }
    cout << "아무것도 안 나옴.." << endl;
}

int main()
{
    srand((unsigned)time(0));

    // 몬스터 데이터 세팅
    vector<Monster> monsters = {
        {"슬라임", {{"힐 포션", 70}}},
        {"고블린", {{"무기 파편", 50},
        {"골드", 30}}},
        {"드래곤", {{"전설의 검", 40},
        {"희귀 방어구", 50}}}
    };

    cout << "몬스터 처치 시작!" << endl;
    for (const auto& m : monsters)
    {
        dropItem(m);
    }
}