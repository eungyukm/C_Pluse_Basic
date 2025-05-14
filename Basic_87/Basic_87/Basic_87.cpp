#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Shield
{
    string name;
    int value;
    Shield(string n, int v) : name(n), value(v) {}
};

struct Unit
{
    string name;
    int hp;
    vector<Shield> shields;

    Unit(string n, int h) : name(n), hp(h) {}

    void AddShield(const string& n, int v)
    {
        shields.emplace_back(n, v);
        cout << n << " 실드 부여 (" << v << ")" << endl;
    }

    void TakeDamage(int dmg)
    {
        cout << name << "가 " << dmg << " 피해를 받음" << endl;
        for (auto& s : shields)
        {
            int absorbed = min(s.value, dmg);
            s.value -= absorbed;
            dmg -= absorbed;
            if (!dmg)
            {
                break;
            }
        }
        shields.erase(remove_if(shields.begin(), shields.end(),
            [](Shield& s)
            {
                return s.value <= 0;
            }), shields.end());

        if (dmg > 0)
        {
            hp -= dmg;
            cout << dmg << " 피해를 입음 (남은 체력 " << hp << ")" << endl;
        }
        else
        {
            cout << "실드로 모든 피해 흡수!" << endl;
        }
    }

    void PrintStatus()
    {
        cout << name << " 체력: " << hp << " 실드: ";
        for (auto& s : shields)
            cout << s.name << "(" << s.value << ") ";
        cout << endl;
    }
};

int main()
{
    Unit unit("Garen", 100);
    unit.PrintStatus();
    unit.AddShield("Divine", 50);
    unit.AddShield("Magic", 30);
    unit.PrintStatus();

    unit.TakeDamage(40); 
    unit.PrintStatus();
    unit.TakeDamage(50);
    unit.PrintStatus();
}
