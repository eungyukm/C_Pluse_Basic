// C++20
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>

using namespace std;

struct Vec2
{
    float x, y;
    Vec2(float x = 0, float y = 0) : x(x), y(y) {}

    Vec2 operator-(const Vec2& other) const 
    { 
        return Vec2(x - other.x, y - other.y); 
    }

    Vec2 Normalized() const
    {
        float len = sqrt(x * x + y * y);
        return (len > 0) ? Vec2(x / len, y / len) : Vec2();
    }

    Vec2 operator*(float scale) const 
    { 
        return Vec2(x * scale, y * scale); 
    }
};

class Player
{
public:
    Vec2 pos;
    bool canMove = true;

    void TakeDamage(const Vec2& attackerPos)
    {
        canMove = false;

        // 넉백
        Vec2 knockback = (pos - attackerPos).Normalized() * 50.0f;
        pos.x += knockback.x;
        pos.y += knockback.y;
        cout << "넉백 위치: (" << pos.x << ", " << pos.y << ")\n";

        // 1초 후 조작 가능
        thread([this]()
            {
                this_thread::sleep_for(chrono::seconds(1));
                canMove = true;
                cout << "조작 가능해짐" << endl;
            }).detach();
    }

    void Move(float dx, float dy)
    {
        if (!canMove)
        {
            cout << "움직일 수 없음 (피격중)" << endl;
            return;
        }
        pos.x += dx;
        pos.y += dy;
        cout << "이동 위치: (" << pos.x << ", " << pos.y << ")" << endl;
    }
};

int main()
{
    Player p;
    p.TakeDamage(Vec2(1, 0)); // 피격
    p.Move(1, 0);              // 조작 안 됨

    this_thread::sleep_for(chrono::seconds(2));
    p.Move(1, 0);              // 조작 가능
}
