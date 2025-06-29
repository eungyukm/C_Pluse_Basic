// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pal
{
    string name;
    int hunger = 100;

    void Tick()
    {
        hunger = max(0, hunger - 1);
        cout << name << " Hunger: " << hunger << endl;
    }
};
int main()
{
    vector<Pal> pals = { {"Pengullet"}, {"Foxparks"}, {"Lamball"} };

    for (int t = 0; t < 5; t++)
    {
        cout << "== Second " << t + 1 << " ==\n";
        for (auto& pal : pals)
        {
            pal.Tick();
        }
    }
    return 0;
}