// C++20
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
    int id;
    string name;
    int Lv;
};

double CalcScaleLog(const vector<Player>& party)
{
    cout << "[보스 체력 스케일 계산]\n";
    int sum = 0;
    for (int i = 0; i < (int)party.size(); i++)
    {
        cout << " 파티원 " << party[i].name
            << " Lv " << party[i].Lv << endl;
        sum += party[i].Lv;
    }

    double avg = party.empty() ? 0.0 : (double)sum / party.size();
    double sizeBoost = 0.9 + 0.1 * party.size();
    double LvBoost = 0.5 + (avg / 2000.0);
    double scale = max(0.8, min(2.0, sizeBoost * LvBoost));

    cout << " 평균 LV: " << avg << endl;
    cout << " 인원 보정: " << sizeBoost << endl;
    cout << " LV 보정: " << LvBoost << endl;
    cout << " 최종 스케일: " << scale << endl;
    return scale;
}

int main()
{
    vector<Player> party{
        {1, "Archer", 1540},
        {2, "Warrior", 1500},
        {3, "Mage", 1520}
    };

    CalcScaleLog(party);
    return 0;
}
