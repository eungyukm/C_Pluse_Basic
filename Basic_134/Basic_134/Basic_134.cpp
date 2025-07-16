// C++20
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Vector2
{
    float x, y;

    bool IsNear(const Vector2& other, float threshold = 0.1f) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2)) < threshold;
    }
};

struct Pal
{
    string name;
    Vector2 position;
    Vector2 spawnPosition;

    int stuckTimer = 0;
    Vector2 lastPosition;

    void Update()
    {
        if (position.IsNear(lastPosition))
        {
            stuckTimer++;
            if (stuckTimer > 5)
            {
                cout << name << " is stuck! Moving to spawn position." << endl;
                position = spawnPosition;
                stuckTimer = 0;
            }
        }
        else
        {
            stuckTimer = 0;
            lastPosition = position;
        }
    }
    void ShowPosition() const
    {
        cout << name << " is at (" << position.x << ", " 
            << position.y << ")" << endl;
    }
};

int main()
{
    Pal pal{ "Foxparks", {0, 0}, {0, 0} };

    // 10틱 동안 위치가 고정된 상황 시뮬레이션
    for (int t = 0; t < 10; t++)
    {
        cout << "== Tick " << t << " ==" << endl;
        pal.Update();
        pal.ShowPosition();
    }

    return 0;
}
