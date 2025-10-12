// C++20
#include <iostream>
#include <vector>
using namespace std;

struct Vec3
{
    float x{}, y{}, z{};
};

struct Checkpoint
{
    Vec3 pos;
    bool reached{ false };
};

struct Player
{
    Vec3 pos;
    Vec3 respawnPos;
    int reachedCount{ 0 };
};

struct Dungeon
{
    vector<Checkpoint> cps;
    int midIndex() const
    {
        return cps.empty() ? 0 : (cps.size() - 1) / 2;
    }
};

static float DistSq(const Vec3& a, const Vec3& b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

void UpdateCheckpoint(Dungeon& d, Player& p)
{
    const float r2 = 3.0f * 3.0f;
    for (int i = 0; i < d.cps.size(); ++i)
    {
        auto& cp = d.cps[i];
        if (cp.reached)
        {
            continue;
        }

        if (DistSq(p.pos, cp.pos) > r2)
        {
            continue;
        }

        cp.reached = true;
        p.reachedCount++;

        if (i >= d.midIndex())
        {
            p.respawnPos = cp.pos;
        }
        break;
    }
}

int main()
{
    Dungeon d{ { {{0,0,0}}, {{10,0,0}}, {{20,0,0}}, {{30,0,0}} } };
    Player  p{ {0,0,0}, d.cps.front().pos };

    vector<Vec3> path = { {10,0,0}, {20,0,0}, {30,0,0} };
    for (auto& step : path)
    {
        p.pos = step;
        UpdateCheckpoint(d, p);
    }

    cout << p.respawnPos.x << "," << p.respawnPos.y
        << "," << p.respawnPos.z << "\n";
    return 0;
}