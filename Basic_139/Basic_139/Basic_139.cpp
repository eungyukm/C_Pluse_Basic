// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Enemy
{
    string name;
    int distance;
};

struct PartnerPal
{
    string name;

    void AttackNearestEnemy(const vector<Enemy>& enemies)
    {
        if (enemies.empty())
        {
            cout << name << " found no enemies." << endl;
            return;
        }

        Enemy target = enemies[0];
        for (const auto& e : enemies)
        {
            if (e.distance < target.distance)
            {
                target = e;
            }
        }
        cout << name << " is attacking " << target.name << "!" << endl;
    }
};

struct Player
{
    string name;
    PartnerPal* partner;

    void OnAttack(vector<Enemy>& enemies)
    {
        cout << name << " started attacking!" << endl;
        partner->AttackNearestEnemy(enemies);
    }

    void OnHit(vector<Enemy>& enemies)
    {
        cout << name << " was hit!" << endl;
        partner->AttackNearestEnemy(enemies);
    }
};

int main()
{
    PartnerPal pal{ "Pengullet" };
    Player player{ "You", &pal };

    vector<Enemy> enemies = { {"Wolf", 10}, {"Goblin", 5}, {"Slime", 15} };

    player.OnAttack(enemies);
    player.OnHit(enemies);
}
