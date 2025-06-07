// C++20 기준
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
    TimeOfDay time = TimeOfDay::Day;

public:
    void AdvanceTime()
    {
        tick++;
        if (tick % 6 == 0)
        {
            time = (time == TimeOfDay::Day) ? TimeOfDay::Night : TimeOfDay::Day;
            cout << "== Time changed to: " << GetTimeString() << " ==\n";
        }
    }
    TimeOfDay GetCurrentTime() const { return time; }

    string GetTimeString() const
    {
        return (time == TimeOfDay::Day) ? "Day" : "Night";
    }
};

struct Pal
{
    string name;
    int health = 100;

    void Act(TimeOfDay time)
    {
        if (time == TimeOfDay::Night)
        {
            health -= 10;
            cout << name << " is freezing at night! (-10 HP)" << endl;
        }
    }

    void ShowStatus() const
    {
        cout << name << " | Health: " << health << endl;
    }
};

int main()
{
    World world;
    vector<Pal> pals = { { "Pengullet" } };

    for (int t = 1; t <= 18; ++t)
    {
        cout << "\n== Tick " << t << " (" 
            << world.GetTimeString() << ") ==\n";

        for (auto& pal : pals)
        {
            pal.Act(world.GetCurrentTime());
        }

        world.AdvanceTime();
    }
}
