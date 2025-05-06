// C++17
#include <iostream>
#include <cmath>

using namespace std;

struct Vector2
{
    float x, y;
};

struct CellCoord
{
    int x, y;
};

CellCoord GetCellCoord(const Vector2& pos, float size)
{
    return
    {
        static_cast<int>(floor(pos.x / size)),
        static_cast<int>(floor(pos.y / size))
    };
}
int main()
{
    Vector2 playerPos = { 25.0f, 18.0f };
    float cellSize = 10.0f;

    CellCoord cell = GetCellCoord(playerPos, cellSize);

    cout << "Player is in cell (" << cell.x;
    cout << ", " << cell.y << ")" << endl;
    return 0;
}
