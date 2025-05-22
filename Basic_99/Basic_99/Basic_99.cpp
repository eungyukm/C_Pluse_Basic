#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class TimeOfDay
{
    Day,
    Night
};

class World
{
private:
    int tick = 0;
    TimeOfDay currentTime = TimeOfDay::Day;

public:
    void AdvanceTime()
    {
        tick++;

        if (tick % 6 == 0)
        {
            currentTime = (currentTime == TimeOfDay::Day) ?
                TimeOfDay::Night : TimeOfDay::Day;
            cout << "== The time has changed to: "
                << GetTimeString() << " ==" << endl;
        }
    }

    string GetTimeString() const
    {
        return (currentTime == TimeOfDay::Day) ? "Day" : "Night";
    }

    TimeOfDay GetCurrentTime() const
    {
        return currentTime;
    }
};
struct Pal
{
    string name;

    void Act(TimeOfDay time)
    {
        if (time == TimeOfDay::Day)
        {
            cout << name << " is gathering resources.\n";
        }
        else
        {
            cout << name << " is sleeping.\n";
        }
    }
};

int main()
{
    World world;
    vector<Pal> pals = {
        { "Daedream" },
        { "Chikipi" }
    };

    for (int t = 1; t <= 12; ++t)
    {
        cout << "== Tick " << t << " (" << world.GetTimeString() << ") ==\n";
        for (auto& pal : pals)
        {
            pal.Act(world.GetCurrentTime());
        }
        cout << endl;
        world.AdvanceTime();
    }
}
