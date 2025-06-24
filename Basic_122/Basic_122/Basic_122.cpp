// C++20 기준
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Vec2
{
    float x, y;

    float DistanceTo(const Vec2& other) const
    {
        return hypot(x - other.x, y - other.y);
    }
};

struct Pal
{
    string name;
    Vec2 position;
    Vec2 spawnPoint;
    float leashRange = 20.0f;
    bool inCombat = false;

    void Update(const Vec2& enemyPos)
    {
        if (inCombat)
        {
            float distFromSpawn = position.DistanceTo(spawnPoint);
            if (distFromSpawn > leashRange)
            {
                inCombat = false;
                cout << name << " ran too far from spawn. Returning!" << endl;
            }
            else
            {
                cout << name << " is fighting at ditance "
                    << distFromSpawn << endl;
            }
        }

        if (!inCombat)
        {
            position = spawnPoint;
            cout << name << " returned to spawn point." << endl;
        }
    }
};
int main()
{
    Pal pal{ "Foxparks", {30, 40}, {10, 10} };
    pal.inCombat = true;

    Vec2 enemyPos{ 32, 42 };
    pal.Update(enemyPos);
}
