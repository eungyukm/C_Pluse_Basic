// C++20
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Vec2
{
    float x, y;

    Vec2 operator-(const Vec2& other) const 
    { 
        return { x - other.x, y - other.y }; 
    }

    float Length() const 
    { 
        return sqrt(x * x + y * y); 
    }

    float Dot(const Vec2& other) const 
    { 
        return x * other.x + y * other.y; 
    }
};

struct Actor
{
    string name;
    Vec2 position;
    bool isHostile;
};
struct Pal
{
    Vec2 position;
    Vec2 forward = { 1, 0 };
    float viewAngle = 90.0f;
    float viewRange = 10.0f;

    void CheckActors(const vector<Actor>& actors)
    {
        for (const auto& actor : actors)
        {
            Vec2 dir = actor.position - position;
            float dist = dir.Length();
            if (dist > viewRange)
            {
                continue;
            }

            float dot = forward.Dot(dir) / (forward.Length() * dist);
            float angle = acos(dot) * 180.0f / 3.14159f;
            if (angle <= viewAngle * 0.5f)
            {
                cout << actor.name << " detected!" << endl;
            }
        }
    }
};
int main()
{
    Pal pal{ {0, 0} };
    vector<Actor> actors = {
        { "Player", {5, 1}, false },
        { "HostilePal", {7, 0}, true },
        { "FarAway", {20, 20}, true }
    };

    pal.CheckActors(actors);
    return 0;
}
