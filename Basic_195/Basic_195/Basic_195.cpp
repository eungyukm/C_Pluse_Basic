// C++20
#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;

struct Vec2
{
    int x{ 0 }, y{ 0 };
};

struct Character
{
    Vec2 pos{};
    void Move(const Vec2& d) { pos.x += d.x; pos.y += d.y; }
};

int main()
{
    Character player{};
    unordered_map<char, Vec2> dir{
        {'w', { 0,  1}}, // 위
        {'s', { 0, -1}}, // 아래
        {'a', {-1,  0}}, // 왼쪽
        {'d', { 1,  0}}  // 오른쪽
    };

    cout << "W/A/S/D로 이동, q 종료\n";
    size_t step = 0;
    for (char k; (cin >> k) && k != 'q';)
    {
        k = static_cast<char>(tolower(k));
        if (auto it = dir.find(k); it != dir.end())
        {
            player.Move(it->second);
            cout << "Step " << step++ << ": pos=("
                << player.pos.x << ", " << player.pos.y << ")"
                << endl;
        }
        else
        {
            cout << "무효 입력" << endl;
        }
    }
}
