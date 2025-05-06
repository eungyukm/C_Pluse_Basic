// C++17
#include <iostream>
#include <cmath>

using namespace std;

struct Vector2
{
    float x, y;
};

struct AABB
{
    Vector2 min; // 왼쪽 아래
    Vector2 max; // 오른쪽 위
};

struct Circle
{
    Vector2 center;
    float radius;
};

// AABB-AABB 충돌
bool IsCollidingAABB(const AABB& a, const AABB& b)
{
    return !(a.max.x < b.min.x || a.min.x > b.max.x ||
        a.max.y < b.min.y || a.min.y > b.max.y);
}

// Circle-Circle 충돌
bool IsCollidingCircle(const Circle& a, const Circle& b)
{
    float dx = a.center.x - b.center.x;
    float dy = a.center.y - b.center.y;
    float distanceSquared = dx * dx + dy * dy;
    float radiusSum = a.radius + b.radius;
    return distanceSquared <= (radiusSum * radiusSum);
}

int main()
{
    // AABB 충돌 테스트
    AABB box1 = { {0.0f, 0.0f}, {5.0f, 5.0f} };
    AABB box2 = { {3.0f, 3.0f}, {8.0f, 6.0f} };

    if (IsCollidingAABB(box1, box2))
        cout << "AABB 충돌 발생!" << endl;
    else
        cout << "AABB 충돌 없음." << endl;

    // Circle 충돌 테스트
    Circle c1 = { {2.0f, 2.0f}, 1.5f };
    Circle c2 = { {3.0f, 2.5f}, 1.0f };

    if (IsCollidingCircle(c1, c2))
        cout << "Circle 충돌 발생!" << endl;
    else
        cout << "Circle 충돌 없음." << endl;

    return 0;
}
