// C++20 기준
#include <iostream>
#include <vector>

using namespace std;

struct Pal
{
    string name;
    int fatigue; // 0 ~ 100
    bool resting = false;

    void TickFatigue()
    {
        if (resting)
        {
            fatigue = max(0, fatigue - 5);
        }
        else
        {
            fatigue = min(100, fatigue + 3);
            if (fatigue >= 80)
            {
                resting = true;
            }
        }
    }
};

int main()
{
    vector<Pal> pals = {
        {"Leafy", 20},
        {"Drillax", 75}
    };

    for (int t = 0; t < 10; t++)
    {
        cout << "== Tick " << t << " ==\n";
        for (auto& pal : pals)
        {
            pal.TickFatigue();
            cout << pal.name << " - Fatigue: " << pal.fatigue
                << ", Resting: " << (pal.resting ? "Yes" : "No") << endl;
        }
    }
}
