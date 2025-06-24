// C++20
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Vec2
{
    int x, y;
};

struct Pal
{
    string name = "Pengullet";
    Vec2 pos{ 0, 0 }, target{ 0, 0 };

    void SetTarget()
    {
        target.x = rand() % 11 - 5;
        target.y = rand() % 11 - 5;
    }

    void Move()
    {
        if (pos.x != target.x)
        {
            pos.x += (target.x > pos.x ? 1 : -1);
        }
        if (pos.y != target.y)
        {
            pos.y += (target.y > pos.y ? 1 : -1);
        }
        cout << name << ": (" << pos.x << ", " << pos.y << ")" << endl;
    }
};
int main()
{
    srand((unsigned)time(0));
    Pal pal;
    pal.SetTarget();

    for (int i = 0; i < 20; ++i)
    {
        pal.Move();
        if (pal.pos.x == pal.target.x && pal.pos.y == pal.target.y)
        {
            pal.SetTarget();
        }
    }
}