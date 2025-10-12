// C++ 20
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 장착 각인의 포인트를 합산해 효과 레벨(1~3)을 계산하는 로직
struct Engraving
{
    string name;
    int points; // 각인 포인트 (예: 5/10/15가 Lv1/2/3)
};

int main()
{
    vector<Engraving> equipped =
    {
        {"Grudge", 3},
        {"Grudge", 2},
        {"CursedDoll", 10},
    };

    unordered_map<string, int> sum;
    for (int i = 0; i < equipped.size(); i++)
    {
        sum[equipped[i].name] += equipped[i].points;
    }

    cout << "[Applied Engravings]" << endl;
    for (auto it = sum.begin(); it != sum.end(); it++)
    {
        int tier = min(it->second / 5, 3);
        if (tier > 0)
        {
            cout << it->first << " Lv" << tier << " ("
                << it->second << " pts" << ")" << endl;
        }
    }
    return 0;
}
