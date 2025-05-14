// C++20 기준
#include <iostream>
#include <array>
#include <cmath>

using namespace std;

constexpr float DEG2RAD = 3.14159265f / 180.0f;

struct Vector3
{
    float x, y, z;
};

using M4x4 = array<array<float, 4>, 4>;

// 단위 행렬 생성
M4x4 CreateIdentityM()
{
    return { {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    } };
}

// 이동 변환 행렬 생성
M4x4 CreateTranslationM(const Vector3& translation)
{
    M4x4 m = CreateIdentityM();
    m[0][3] = translation.x;
    m[1][3] = translation.y;
    m[2][3] = translation.z;
    return m;
}

// Z축 회전 변환 행렬 생성
M4x4 CreateRotationZM(float angleDegrees)
{
    float radians = angleDegrees * DEG2RAD;
    float cosA = cos(radians);
    float sinA = sin(radians);

    M4x4 m = CreateIdentityM();
    m[0][0] = cosA;
    m[0][1] = -sinA;
    m[1][0] = sinA;
    m[1][1] = cosA;
    return m;
}

// 행렬을 이용한 벡터 변환
Vector3 TransformPoint(const M4x4& m, const Vector3& point)
{
    Vector3 result;
    result.x = m[0][0] * point.x + m[0][1] * point.y + 
        m[0][2] * point.z + m[0][3];
    result.y = m[1][0] * point.x + m[1][1] * point.y + 
        m[1][2] * point.z + m[1][3];
    result.z = m[2][0] * point.x + m[2][1] * point.y + 
        m[2][2] * point.z + m[2][3];
    return result;
}

int main()
{
    Vector3 point{ 1, 0, 0 };

    M4x4 translateM = CreateTranslationM({ 2, 3, 0 });
    M4x4 rotateM = CreateRotationZM(90);

    Vector3 translatedPoint = TransformPoint(translateM, point);
    Vector3 rotatedPoint = TransformPoint(rotateM, translatedPoint);

    cout << "Original: (" << point.x << ", "
        << point.y << ", " << point.z << ")\n";
    cout << "Translated: (" << translatedPoint.x << ", "
        << translatedPoint.y << ", " << translatedPoint.z << ")\n";
    cout << "Rotated: (" << rotatedPoint.x << ", "
        << rotatedPoint.y << ", " << rotatedPoint.z << ")\n";
}
