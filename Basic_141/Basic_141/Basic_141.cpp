// C++20
#include <iostream>
#include <cmath>
#include <memory>

using namespace std;

struct Vector3
{
    float x, y, z;

    float DistanceTo(const Vector3& other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        float dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
};

struct Player
{
    Vector3 position;
};

struct PartnerPal
{
    Vector3 position;

    void TeleportTo(const Vector3& newPos)
    {
        position = newPos;
        cout << "Partner teleported to ("
            << position.x << ", "
            << position.y << ", "
            << position.z << ")" << endl;
    }
};

void OnBattleEnd(Player& player, PartnerPal& pal, float maxDistance = 1000.0f)
{
    if (pal.position.DistanceTo(player.position) > maxDistance)
    {
        Vector3 nearPlayer = player.position;
        nearPlayer.x += 100.0f;
        pal.TeleportTo(nearPlayer);
    }
    else
    {
        cout << "Partner is close enough. No teleport needed." << endl;
    }
}

int main()
{
    Player player{ { 0, 0, 0 } };
    PartnerPal pal{ { 1500, 0, 0 } };

    OnBattleEnd(player, pal);
}
