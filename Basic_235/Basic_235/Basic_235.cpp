// C++20
#include <iostream>
#include <algorithm>
using namespace std;

struct Ship
{
    int fuel{ 10 };
    int pos{ 0 };

    // 이동 시 연료 1씩 차감
    // 0이면 이동 불가
    // 전부 이동했으면 true
    bool Move(int steps)
    {
        for (int i = 0; i < steps; i++)
        {
            if (fuel <= 0)
            {
                return false;
                pos++;
                fuel--;
            }
            return true;
        }
    }

    void Refuel(int amount)
    {
        fuel += max(0, amount);
    }
};

int main()
{
    Ship s;
    cout << "start fuel " << s.fuel << "\n";
    bool ok = s.Move(7);
    cout << "moved " << (ok ? "all" : "partial") << "\n";
    cout << "pos " << s.pos << " fuel " << s.fuel << "\n";

    s.Refuel(5);
    cout << "refuel -> fuel " << s.fuel << "\n";

    ok = s.Move(10);
    cout << "moved " << (ok ? "all" : "partial") << "\n";
    cout << "pos " << s.pos << " fuel " << s.fuel << "\n";
}
