// C++17
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Character 
{
public:
    unordered_map<string, int> stats
    {
        {"Strength", 0},
        {"Dexterity", 0},
        {"Intelligence", 0},
        {"Vitality", 0}
    };

    int availablePoints;

    Character(int initialPoints) :
        availablePoints(initialPoints) {}

    void DistributeStat
    (const string& statName, int points)
    {
        if (availablePoints >= points
            && stats.count(statName))
        {
            stats[statName] += points;
            availablePoints -= points;

            cout << points
                << " points added to "
                << statName << ".\n";
        }
        else
        {
            cout << "Cannot distribute points to "
                << statName << ".\n";
        }
    }

    void ShowStats() const
    {
        cout << "=== Character Stats ===\n";
        for (const auto& [name, value] : stats)
        {
            cout << name << ": " << value << "\n";
        }
        cout << "Available Points: "
            << availablePoints << "\n";
    }
};

int main()
{
    Character myCharcter(10);

    myCharcter.ShowStats();

    myCharcter.DistributeStat("Strength", 3);
    myCharcter.DistributeStat("Dexterity", 3);
    myCharcter.DistributeStat("Intelligence", 4);

    myCharcter.ShowStats();
    return 0;
}
