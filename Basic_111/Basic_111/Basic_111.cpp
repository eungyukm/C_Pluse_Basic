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

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 5;

int main()
{
    vector<Resource> resources;
    vector<string> resourceTypes = { "Wood", "Stone", "Berry" };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> xDist(0, MAP_WIDTH - 1);
    uniform_int_distribution<> yDist(0, MAP_HEIGHT - 1);
    uniform_int_distribution<> typeDist(0, resourceTypes.size() - 1);

    // 자원 5개 스폰
    for (int i = 0; i < 5; i++)
    {
        Resource res
        {
            resourceTypes[typeDist(gen)],
            xDist(gen),
            yDist(gen),
        };
        resources.push_back(res);
    }

    // 출력
    for (const auto& res : resources)
    {
        cout << res.name << " spawned at (" 
            << res.x << ", " << res.y << ")" << endl;
    }
}