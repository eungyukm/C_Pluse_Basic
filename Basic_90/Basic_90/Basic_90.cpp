// C++20 기준
#include <iostream>
#include <vector>

using namespace std;

struct Rect
{
    float x, y, w, h;

    bool Contains(float px, float py) const
    {
        return (px >= x - w && px <= x + w &&
            py >= y - h && py <= y + h);
    }
};

struct Point
{
    float x, y;
    int id;
};

class QuadTree
{
    static constexpr int Capacity = 4;
    Rect boundary;
    vector<Point> points;

public:
    QuadTree(const Rect& boundary) : boundary(boundary) {}

    bool Insert(const Point& p)
    {
        if (!boundary.Contains(p.x, p.y))
        {
            return false;
        }

        if (points.size() < Capacity)
        {
            points.push_back(p);
            return true;
        }

        // Subdivide 생략 -> 연습용
        return false;
    }

    void PrintPoints()
    {
        for (const auto& p : points)
            cout << "Point ID: " << p.id << " (" << p.x << ", " << p.y << ")\n";
    }
};

int main()
{
    QuadTree qt({ 0, 0, 10, 10 });

    qt.Insert({ 1, 1, 1 });
    qt.Insert({ -2, -3, 2 });
    qt.Insert({ 4, 5, 3 });
    qt.Insert({ 15, 15, 4 }); // 밖이라 삽입 안됨

    qt.PrintPoints();
}
