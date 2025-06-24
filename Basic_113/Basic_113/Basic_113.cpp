// C++20 기준
#include <iostream>
#include <string>

using namespace std;

struct Vector3
{
    float x, y, z;
};

struct Water
{
    float surfaceY = 0.0f; // 수면 높이
};

struct Pal
{
    string name;
    Vector3 position;
    float mass; // 질량
    float volume; // 부피

    bool IsFloating(const Water& water) const
    {
        // 부피 = 부피 * 중력가속도
        float buoyancy = volume * 9.8f;
        // 중력 = 질량 * 중력가속도
        float weight = mass * 9.8f;

        return buoyancy >= weight && position.y <= water.surfaceY;
    }

    void Update(const Water& water)
    {
        if (IsFloating(water))
        {
            // 수면 위에 위치 고정
            position.y = water.surfaceY;
            cout << name << " is floating!" << endl;
        }
        else
        {
            // 가라앉음
            position.y -= 0.1f;
            cout << name << " is sinking..." << endl;
        }
    }
};

int main()
{
    // 수면 y = 0
    Water water{ 0.0f }; 
    // 질량 5, 부피 1이면 가라앉음
    Pal pal{ "Pengullet", {0, 1, 0}, 5.0f, 1.0f }; 

    for (int i = 0; i < 10; ++i)
    {
        cout << "[Tick " << i << "] ";
        pal.Update(water);
    }

    return 0;
}
