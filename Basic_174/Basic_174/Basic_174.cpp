// C++20
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct FVec2
{
    float X;
    float Y;
};

struct FPlaceResult
{
    FVec2 Pos;    // 배치 위치 (월드 좌표)
    float YawDeg; // 회전 (0 or 90)
    string Type;  // "Foundation" or "Wall"
};

static float NearestGridLine(float v, float cell)
{
    return round(v / cell) * cell;
}

static float NearestCellCenter(float v, float cell)
{
    float base = floor(v / cell) * cell;
    return base + cell * 0.5f;
}

// 토대: 셀 센터로 스냅
FPlaceResult SnapFoundation(const FVec2& mouse, float cell)
{
    FPlaceResult r;
    r.Type = "Foundation";
    r.Pos.X = NearestCellCenter(mouse.X, cell);
    r.Pos.Y = NearestCellCenter(mouse.Y, cell);
    r.YawDeg = 0.0f;
    return r;
}

// 벽: 더 가까운 그리드 라인(세로/가로)에 맞춰 배치 + 회전 결정
FPlaceResult SnapWall(const FVec2& mouse, float cell)
{
    float vLineX = NearestGridLine(mouse.X, cell);
    float hLineY = NearestGridLine(mouse.Y, cell);
    float distToV = fabs(mouse.X - vLineX);
    float distToH = fabs(mouse.Y - hLineY);

    FPlaceResult r;
    r.Type = "Wall";

    if (distToV < distToH)
    {
        // 세로 벽: X는 그리드 라인, Y는 셀 센터
        r.Pos.X = vLineX;
        r.Pos.Y = NearestCellCenter(mouse.Y, cell);
        r.YawDeg = 90.0f;
    }
    else
    {
        // 가로 벽: Y는 그리드 라인, X는 셀 센터
        r.Pos.X = NearestCellCenter(mouse.X, cell);
        r.Pos.Y = hLineY;
        r.YawDeg = 0.0f;
    }
    return r;
}

// 간단 데모
int main()
{
    float cell = 200.0f; // 그리드 셀 크기(예: 200cm)
    FVec2 mouseA{ 312.0f, 97.0f };
    FVec2 mouseB{ 405.0f, 589.0f };

    auto f = SnapFoundation(mouseA, cell);
    cout << "[Foundation] Pos(" << f.Pos.X << ", " << f.Pos.Y
        << "), Yaw " << f.YawDeg << "\n";

    auto w1 = SnapWall(mouseA, cell);
    cout << "[Wall] Pos(" << w1.Pos.X << ", " << w1.Pos.Y
        << "), Yaw " << w1.YawDeg << "\n";

    auto w2 = SnapWall(mouseB, cell);
    cout << "[Wall] Pos(" << w2.Pos.X << ", " << w2.Pos.Y
        << "), Yaw " << w2.YawDeg << "\n";
}
