#include <iostream>
#include <string>
using namespace std;

struct Unit
{
    string name;
    int hp, maxHp, regen;

    Unit(string n, int h, int r)
        : name(n), hp(h), maxHp(h), regen(r) {}

    void TakeDamage(int dmg)
    {
        hp -= dmg;
        if (hp < 0) hp = 0;
        cout << name << "가 " << dmg << " 피해를 입음 (남은 체력: " << hp << ")\n";
    }

    void EndTurn()
    {
        if (hp == 0)
        {
            // 사망 시 회복 없음
            return; 
        }
        hp += regen;
        if (hp > maxHp)
        {
            hp = maxHp;
        }
        cout << name << "가 " << regen << " 회복 (현재 체력: " << hp << ")\n";
    }

    void PrintStatus() const
    {
        cout << name << " 체력: " << hp << "/" << maxHp << '\n';
    }
};

int main()
{
    Unit u("Knight", 100, 10); // 체력 100, 턴당 10 회복
    u.PrintStatus();

    u.TakeDamage(30);
    for (int i = 1; i <= 3; i++)
    {
        cout << "\n턴 " << i << " 시작\n";
        u.EndTurn();
        u.PrintStatus();
    }
}
