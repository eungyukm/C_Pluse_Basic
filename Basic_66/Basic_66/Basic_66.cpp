// C++17
#include <iostream>

using namespace std;

struct Vector2
{
    float x, y;

    Vector2 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y };
    }

    Vector2 operator*(float scalar) const
    {
        return { x * scalar, y * scalar };
    }
};

// Dead Reconing(데드 레커닝)은 멀티플레이 게임에서
// 위치 예측 보정 알고리즘으로, 서버의 위치 업데이트
// 주기가 느릴 때, 클라이언트가 예측 이동을 해주는
// 기술입니다.

// 시간 기반 위치 예측
Vector2 PredictPosition(Vector2 lastPos, 
    Vector2 velocity, float elapsedTime)
{
    return lastPos + velocity * elapsedTime;
}

int main()
{
    Vector2 lastPosition = { 0.0f, 0.0f };

    // 오른쪽으로 1m/s
    Vector2 velocity = { 1.0f, 0.0f };
    // 200ms 경과 가정
    float elapsed = 0.2f;

    Vector2 predicated =
        PredictPosition(lastPosition, velocity, elapsed);

    cout << "Predicated Positon: ("
        << predicated.x << ", " << predicated.y
        << ")" << endl;
    return 0;
}
