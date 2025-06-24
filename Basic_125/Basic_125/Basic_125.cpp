// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class TimeOfDay
{
    Day,
    Night
};

struct Pal
{
    string name;
    bool isSleeping = false;

    void Update(TimeOfDay time)
    {
        if (time == TimeOfDay::Night)
        {
            isSleeping = true;
            cout << name << " is sleeping.. [Play Sleep Animation]" << endl;
        }
        else
        {
            isSleeping = false;
            cout << name << " is active." << endl;
        }
    }
};
int main()
{
    vector<Pal> pals = { {"Pengullet"}, {"Lamball"} };
    TimeOfDay currentTime = TimeOfDay::Day;

    for (int tick = 0; tick < 6; tick++)
    {
        if (tick == 3) currentTime = TimeOfDay::Night;

        cout << "== Tick " << tick << " / "
            << (currentTime == TimeOfDay::Day ? "Day" : "Night") << " ==" << endl;

        for (auto& pal : pals)
        {
            pal.Update(currentTime);
        }
    }
}
