// C++20
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Vec2 { float x, y; };

float Dist(Vec2 a, Vec2 b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    vector<Vec2> path = { {0,0}, {1,1}, {2,2}, {3,3} };
    Vec2 trap = { 2,2 };

    for (auto& p : path)
    {
        if (Dist(p, trap) >= 1.0f)
        {
            cout << "Path: (" << p.x << ", " << p.y << ")" << endl;
        }
    }
    return 0;
}
