// C++17
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

struct Vector2
{
    float x, y;

    float DistanceTo(const Vector2& other) const
    {
        return sqrt((x - other.x) * (x - other.x) +
            (y - other.y) * (y - other.y));
    }
};

struct Unit
{
    string name;
    Vector2 pos;
    int hp;
    int atk;
    float critRate;
};

// 치명타 판정 함수
bool IsCrit(float rate) 
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) < rate;
}

int main() 
{
    Unit player = { "Player", {0, 0}, 100, 30, 0.3f };

    vector<Unit> monsters = 
    {
        {"Goblin", {1, 1}, 50, 10, 0.0f},
        {"Orc", {4, 4}, 80, 15, 0.0f}
    };

    float range = 3.0f;

    return 0;
}