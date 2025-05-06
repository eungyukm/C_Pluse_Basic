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

    bool operator==(const CellCoord& other) const
    {
        return x == other.x && y == other.y;
    }
};

CellCoord GetCellCoord(const Vector2& pos, float size)
{
    return {
        static_cast<int>(floor(pos.x / size)),
        static_cast<int>(floor(pos.y / size))
    };
}

int main()
{
    float cellSize = 10.0f;

    Vector2 oldPos = { 5.0f, 5.0f };
    Vector2 newPos = { 16.0f, 7.0f };

    CellCoord from = GetCellCoord(oldPos, cellSize);
    CellCoord to = GetCellCoord(newPos, cellSize);

    if (!(from == to))
    {
        cout << "Player moved from cell (" << from.x;
        cout << ", " << from.y << ") to (" << to.x;
        cout << ", " << to.y << ")" << endl;
    }
    else
    {
        cout << "Player stayed in the same cell." << endl;
    }
    return 0;
}
