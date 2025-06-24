// C++20
#include <iostream>
#include <cmath>

using namespace std;

struct Vec2
{
    float x, y;

    Vec2 operator-(const Vec2& other) const 
    { 
        return { x - other.x, y - other.y }; 
    }
    Vec2 operator+(const Vec2& other) const 
    {
        return { x + other.x, y + other.y }; 
    }
    Vec2 operator*(float s) const 
    { 
        return { x * s, y * s }; 
    }

    Vec2 Normalized() const
    {
        float len = sqrt(x * x + y * y);
        return (len > 0) ? Vec2{ x / len, y / len } : Vec2{ 0, 0 };
    }
};

struct Pal
{
    string name;
    float hp = 100.0f;
    float maxHp = 100.0f;
    Vec2 position;

    void UpdateAI(const Vec2& threatPos)
    {
        float ratio = hp / maxHp;
        if (ratio < 0.3f)
        {
            Vec2 away = (position - threatPos).Normalized();
            position = position + away * 1.0f;
            cout << name << " is fleeing to ("
                << position.x << ", " << position.y << ")" << endl;
        }
    }
};
int main()
{
    Pal pal{ "Pengullet", 20.0f, 100.0f, { 5, 5 } };
    Vec2 threat{ 7, 5 };

    pal.UpdateAI(threat);
}
