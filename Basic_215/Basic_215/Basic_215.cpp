// C++ 20
#include <iostream>
#include <vector>
#include <optional>
using namespace std;

enum class eDUNGEON_STATE
{
    Run,
    BossSpawned,
    Cleared
};

struct Player
{
    float distance = 0.f;
};

struct Boss
{
    string name = "Gatekeeper";
    bool isAlive = false;
};

struct Dungeon
{
    eDUNGEON_STATE state = eDUNGEON_STATE::Run;
    Boss boss{};
    vector<float> spawnSections{ 120.f, 300.f };
    size_t nextSectionIdx = 0;
    int spawnTryCount = 0;

    void Update(Player& p)
    {
        if (state != eDUNGEON_STATE::Run)
        {
            return;
        }

        if (nextSectionIdx >= spawnSections.size())
        {
            return;
        }

        float threshold = spawnSections[nextSectionIdx];
        if (p.distance >= threshold)
        {
            TrySpawnBoss();
        }

        if (boss.isAlive && p.distance >= threshold + 50.f)
        {
            boss.isAlive = false;
            state = (++nextSectionIdx < spawnSections.size())
                ? eDUNGEON_STATE::Run
                : eDUNGEON_STATE::Cleared;
        }
    }

    void TrySpawnBoss()
    {
        spawnTryCount++;
        if (boss.isAlive)
        {
            return;
        }
        boss.isAlive = true;
        state = eDUNGEON_STATE::BossSpawned;

        cout << "Boss Summoned: " << boss.name << endl;
        cout << "SpawnTryCount: " << spawnTryCount << endl;
    }
};

// 샘플 실행
int main()
{
    Player player{};
    Dungeon dungeon{};

    for (int t = 0; t < 400; t++)
    {
        player.distance += 10.f;
        dungeon.Update(player);
        if (dungeon.state == eDUNGEON_STATE::Cleared)
        {
            break;
        }
    }

    cout << "Dungeon State: "
        << (dungeon.state == eDUNGEON_STATE::Cleared ? 
            "Cleared" : "InProgress")
        << "\n";
    return 0;
}
