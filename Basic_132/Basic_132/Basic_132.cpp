// C++20
#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

struct Pal
{
    string name;
    int san = 100;
    bool isSick = false;

    void CheckDisease(mt19937& gen)
    {
        uniform_int_distribution<> dis(0, 100);

        int chance = 100 - san;
        int roll = dis(gen);

        cout << "Rool: " << roll << " | Chance: " << chance << endl;

        if (roll < chance)
        {
            isSick = true;
            cout << name << " got sick!" << endl;
        }
        else
        {
            cout << name << " is safe." << endl;
        }
    }
};

int main()
{
    // Windows에서 더 안정적인 시드
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(static_cast<unsigned int>(seed));

    Pal pal{ "Pengullet", 90 }; // SAN이 30

    for (int hour = 1; hour <= 5; hour++)
    {
        cout << "== Hour " << hour << " ==" << endl;
        pal.CheckDisease(gen);
        if (pal.isSick)
            break;
    }
}
