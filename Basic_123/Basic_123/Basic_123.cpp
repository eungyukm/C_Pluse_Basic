#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Vec2
{
    float x, y;
    float Distance(const Vec2& other) const
    {
        return hypot(x - other.x, y - other.y);
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
    int hunger = 100;
    Vec2 position;

    void Tick(const vector<Object>& objects)
    {
        hunger -= 5;

        if (hunger <= 30)
        {
            const Object* food = FindNearestFood(objects);
            if (food)
            {
                MoveTo(food->position);
                Eat();
            }
        }
    }

    const Object* FindNearestFood(const vector<Object>& objects)
    {
        const Object* nearest = nullptr;
        float minDist = 9999;

        for (const auto& obj : objects)
        {
            if (obj.tag != "food") continue;
            float dist = position.Distance(obj.position);
            if (dist < minDist)
            {
                minDist = dist;
                nearest = &obj;
            }
        }
        return nearest;
    }

    void MoveTo(const Vec2& dest)
    {
        cout << name << " moves to (" << dest.x << ", " << dest.y << ")\n";
        position = dest;
    }

    void Eat()
    {
        hunger += 20;
        cout << name << " eats and restores hunger to " << hunger << endl;
    }
};

int main()
{
    vector<Object> objects = {
        { "tree", {5, 5} },
        { "food", {2, 3} },
        { "food", {8, 1} }
    };

    Pal wildPal{ "Goblin", 35, {0, 0} };

    wildPal.Tick(objects);
}