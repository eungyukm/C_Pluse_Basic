// C++20
#include <iostream>
#include <cmath>

using namespace std;

struct Vector3
{
    float x, y, z;

    Vector3 operator+(const Vector3& other) const
    {
        return { x + other.x, y + other.y + other.z };
    }

    Vector3 operator*(float scalar) const
    {
        return { x * scalar, y * scalar, z * scalar };
    }
};

class Projectile
{
public:
    Vector3 Position;
    Vector3 Velocity;
    float Gravity = -9.8f;

    Projectile(Vector3 startPos, Vector3 initialVelocity)
        :Position(startPos), Velocity(initialVelocity) {}

    void Update(float deltaTime)
    {
        // 중력은 y축에만 영향을 줍니다.
        Velocity.y += Gravity * deltaTime;

        // 위치 갱신
        Position = Position + Velocity * deltaTime;
    }
};

int main()
{
    Projectile arrow({ 0, 0, 0 }, { 10, 10, 0 }); // 시작 위치, 초기 속도
    float deltaTime = 0.1f; // 1프레임 간격 (초)

    for (int i = 0; i < 20; ++i)
    {
        arrow.Update(deltaTime);
        cout << "Time: " << (i + 1) * deltaTime
            << "s, Pos: (" << arrow.Position.x << ", "
            << arrow.Position.y << ", "
            << arrow.Position.z << ")\n";
    }

    return 0;
}
