// C++20
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

struct Resource
{
    string name;
    int x, y;
};

int main()
{
    vector<string> rareTypes = { "Crystal", "Gold" };
    vector<Resource> rareResources;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> xDist(0, 9);
    uniform_int_distribution<> yDist(0, 4);
    uniform_int_distribution<> rareDist(0, rareTypes.size() - 1);
    uniform_real_distribution<> chance(0.0, 1.0);

    for (int i = 0; i < 10; i++)
    {
        if (chance(gen) < 0.2)
        {
            rareResources.push_back(
                {
                    rareTypes[rareDist(gen)],
                    xDist(gen),
                    yDist(gen)
                });
        }
    }
    for (const auto& r : rareResources)
    {
        cout << "[RARE] " << r.name 
            << " at (" << r.x << ", " << r.y << ")" << endl;
    }
}
