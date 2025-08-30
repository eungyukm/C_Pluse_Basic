// C++20
#include <iostream>
#include <cmath>
using namespace std;

struct Vec3
{
    float x, y, z;
};

float GetDistance(const Vec3& a, const Vec3& b)
{
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

float Clamp01(float v) 
{ 
    return v < 0.f ? 0.f : (v > 1.f ? 1.f : v); 
}

float Smooth01(float t) 
{ 
    t = Clamp01(t);
    return t * t * (3.f - 2.f * t);
}


struct AudioSource
{
    Vec3 pos{ 0, 0, 0 };
    float minD = 2.f;
    float maxD = 25.f;
    float vol = 0.f;
    float atkH = 8.f;
    float relH = 3.f;

    void Update(const Vec3& listener, float dt)
    {
        float d = GetDistance(pos, listener);
        float t = (d - minD) / (maxD - minD);
        float target = 1.f - Smooth01(t);
        float k = (target > vol ? atkH : relH);
        float a = 1.f - expf(-k * dt);
        vol += (target - vol) * a;
    }
};

int main()
{
    AudioSource falls{ {0,0,0}, 2.f, 25.f, 0.f, 8.f, 3.f };
    Vec3 player{ 0,0,30 };
    float dt = 0.1f;

    for (int i = 0; i < 40; i++)
    {
        player.z -= 1.f;               // 플레이어가 폭포에 다가감
        falls.Update(player, dt);
        cout << "z=" << player.z << " vol=" << falls.vol << "\n";
    }
    return 0;
}