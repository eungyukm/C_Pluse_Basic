// C++20
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

enum class PalType
{
    Normal,
    Flying,
    Aquatic
};

struct Vec3
{
    float x, y, z;
};

struct Obstacle
{
    Vec3 position;
    bool isWater;
    bool isWall;
};

class Pal
{
public:
    Pal(PalType type, Vec3 pos) : type(type), position(pos) {}

    void MoveTo(const Vec3& target, const vector<Obstacle>& obstacles)
    {
        cout << "[PalType: " << GetTypeName() << "] ";
        if (type == PalType::Flying)
        {
            cout << "비행으로 장애물 무시하고 이동" << endl;
        }
        else if (type == PalType::Aquatic)
        {
            if (IsPathInWater(target, obstacles))
            {
                cout << "수중 이동 경로 설정" << endl;
            }
            else
            {
                cout << "물 속이 아니라 이동 불가" << endl;
            }
        }
        else
        {
            if (IsPathBlocked(target, obstacles))
            {
                cout << "장애물로 이동 경로 차단됨" << endl;
            }
            else
            {
                cout << "일반 이동 경로 설정" << endl;
            }
        }
    }

private:
    PalType type;
    Vec3 position;

    bool IsPathBlocked(const Vec3& target, const vector<Obstacle>& obstacles)
    {
        for (const auto& o : obstacles)
            if (o.isWall)
                return true;
        return false;
    }

    bool IsPathInWater(const Vec3& target, const vector<Obstacle>& obstacles)
    {
        for (const auto& o : obstacles)
            if (o.isWater)
                return true;
        return false;
    }

    string GetTypeName()
    {
        switch (type)
        {
        case PalType::Normal: return "Normal";
        case PalType::Flying: return "Flying";
        case PalType::Aquatic: return "Aquatic";
        }
        return "Unknown";
    }
};

int main()
{
    vector<Obstacle> obstacles = {
        { {5, 0, 0}, true, false },  // 물
        { {6, 0, 0}, false, true }   // 벽
    };

    Pal flying(PalType::Flying, { 0, 0, 0 });
    Pal aquatic(PalType::Aquatic, { 0, 0, 0 });
    Pal normal(PalType::Normal, { 0, 0, 0 });

    flying.MoveTo({ 10, 0, 0 }, obstacles);
    aquatic.MoveTo({ 10, 0, 0 }, obstacles);
    normal.MoveTo({ 10, 0, 0 }, obstacles);

    return 0;
}
