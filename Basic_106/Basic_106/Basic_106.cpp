// c++ 20
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct Vec2
{
    float x, y;
    float Distance(const Vec2& other) const
    {
        return sqrt((x - other.x) * (x - other.x) +
            (y - other.y) * (y - other.y));
    }
};

struct Resource
{
    string name;
    Vec2 pos;
    bool collected = false;
};

struct Pal
{
    string name;
    Vec2 pos;

    void TryGather(vector<Resource>& resources)
    {
        for (auto& r : resources)
        {
            if (!r.collected && pos.Distance(r.pos) <= 2.0f)
            {
                r.collected = true;
                cout << name << " gathered " << r.name << "!" << endl;
                return;
            }
        }
        cout << name << " found nothing." << endl;
    }
};
int main()
{
    Pal pal{ "Foxparks", {1, 1} };
    vector<Resource> resources = {
        {"Berry", {2, 2}}
    };
    
    pal.TryGather(resources);
    pal.TryGather(resources);
    return 0;
}