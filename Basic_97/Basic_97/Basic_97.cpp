// C++20 기준
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pal
{
    string name;
    int food = 100;
    int consumeRate;
    int isHungry = false;

    void Tick()
    {
        if (food > 0)
        {
            food -= consumeRate;
            if (food <= 0)
            {
                food = 0;
                isHungry = true;
            }
        }
    }

    void ShowStatus() const
    {
        cout << name << " - Food: " << food
            << ", Hungry: " << (isHungry ? "Yes" : "No") << endl;
    }
};
int main()
{
    vector<Pal> pals = {
        { "Leafy", 100, 15 },
        { "Torchy", 100, 25 }
    };

    for (int t = 1; t <= 5; ++t)
    {
        cout << "== Tick " << t << " ==\n";
        for (auto& p : pals)
        {
            p.Tick();
            p.ShowStatus();
        }
        cout << endl;
    }
}
