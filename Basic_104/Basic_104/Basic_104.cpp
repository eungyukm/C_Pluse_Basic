// C++20 기준
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Vec2
{
    float x;
    float y;

    float DistanceTo(const Vec2& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Campfire
{
public:
    Vec2 position;
    float burnRadius = 3.0f;

    Campfire(float x, float y)
    {
        position = { x, y };
    }

    bool IsNear(const Vec2& palPos) const
    {
        return position.DistanceTo(palPos) <= burnRadius;
    }
};

class Pal
{
public:
    string name;
    Vec2 position;
    bool isBurning = false;

    Pal(string name, float x, float y)
        : name(name), position{ x, y } {}

    void CheckCampfire(const Campfire& campfire)
    {
        bool nearFire = campfire.IsNear(position);
        if (nearFire && !isBurning)
        {
            isBurning = true;
            cout << name << " is now on fire!" << endl;
        }
        else if (!nearFire && isBurning)
        {
            isBurning = false;
            cout << name << "'s fire has gone out." << endl;
        }
    }

    void MoveTo(float x, float y)
    {
        position = { x, y };
        cout << name << " moved to (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Campfire campfire(0.0f, 0.0f);
    Pal fox("Foxparks", 5.0f, 5.0f);

    fox.CheckCampfire(campfire);  // 멀리 있음
    fox.MoveTo(1.0f, 1.0f);       // 가까이 이동
    fox.CheckCampfire(campfire); // 불 붙음
    fox.MoveTo(5.0f, 5.0f);       // 다시 멀어짐
    fox.CheckCampfire(campfire); // 불 꺼짐

    return 0;
}
