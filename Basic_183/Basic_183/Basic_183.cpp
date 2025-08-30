// C++20
#include <iostream>
#include <vector>
using namespace std;

struct Vec2
{
    int x, y;
};

class MarkerSystem
{
public:
    void AddMarker(const Vec2& p)
    {
        _markers.push_back(p);
    }

    void Render(int w, int h, const Vec2& player)
    {
        vector<string> g(h, string(w, '.'));
        for (auto& m : _markers)
        {
            if (_In(m, w, h))
            {
                g[m.y][m.x] = 'M';
            }
        }

        if (_In(player, w, h))
        {
            g[player.y][player.x] = 'P';
        }

        for (int y = 0; y < h; y++)
        {
            cout << g[y] << endl;
        }
    }

private:
    vector<Vec2> _markers;

    static bool _In(const Vec2& p, int w, int h)
    {
        return p.x >= 0 && p.y >= 0 && p.x < w && p.y < h;
    }
};

int main()
{
    MarkerSystem ms;
    Vec2 player{ 2, 3 };

    ms.AddMarker({ 5, 2 });
    ms.AddMarker({ 8, 4 });

    ms.Render(12, 7, player);
}