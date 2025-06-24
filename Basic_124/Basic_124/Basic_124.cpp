// C++20 기준
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Vec2
{
    float x, y;

    float DistanceTo(const Vec2& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

struct Object
{
    string tag;
    Vec2 position;
};

struct Pal
{
    string name;
    Vec2 position;
    int hunger = 100;

    void Tick(const vector<Object>& worldObjects)
    {
        if (hunger > 30)
        {
            return;
        }

        const Object* targetFood = nullptr;
        float minDist = 9999;

        for (const auto& obj : worldObjects)
        {
            if (obj.tag == "Food")
            {
                float dist = position.DistanceTo(obj.position);
                if (dist < minDist)
                {
                    minDist = dist;
                    targetFood = &obj;
                }
            }
        }

        if (targetFood)
        {
            cout << name << " moves to food at (" << targetFood->position.x
                << ", " << targetFood->position.y << ") and eats" << endl;
            hunger += 50;
        }
        else
        {
            cout << name << " is hungry but finds no food." << endl;
        }
    }
};

int main()
{
    Pal pal{ "Chikipi", {0, 0}, 20 };

    vector<Object> world = {
        { "Food", {2, 3} },
        { "Tree", {5, 5} },
        { "Food", {1, 1} }
    };

    pal.Tick(world);
}
