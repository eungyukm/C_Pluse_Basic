// C++20
#include <iostream>
#include <cmath>
using namespace std;

struct Vec2 { float x, y; };
float Dist(const Vec2& a, const Vec2& b) 
{ 
    return hypot(a.x - b.x, a.y - b.y); 
}

int main()
{
    Vec2 ship{ 0, 0 }, treasure{ 5, 3 };
    float speed = 1.0f, arriveRange = 1.0f;

    for (int tick = 0; tick < 10; tick++)
    {
        if (Dist(ship, treasure) <= arriveRange)
        {
            cout << "[보물 등장] 위치("
                << treasure.x << ", "
                << treasure.y << ")\n";
            break;
        }

        ship.x += (treasure.x - ship.x) * 0.3f;
        ship.y += (treasure.y - ship.y) * 0.3f;

        cout << "이동 " << tick
            << " -> (" << ship.x << ", "
            << ship.y << ")\n";
    }
}
