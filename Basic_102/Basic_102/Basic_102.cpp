#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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
            currentTime = (currentTime == TimeOfDay::Day)
                ? TimeOfDay::Night : TimeOfDay::Day;
            cout << "== Time chagned to: "
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

enum class WorkType
{
    None,
    Building,
    Farming,
    Guarding
};

string GetWorkName(WorkType type)
{
    switch (type)
    {
    case WorkType::Building: return "Building";
    case WorkType::Farming: return "Farming";
    case WorkType::Guarding: return "Guarding";
    default: return "Idle";
    }
}

struct Pal
{
    string name;
    WorkType assignedWork = WorkType::None;

    void Assign(WorkType work)
    {
        assignedWork = work;
        cout << name << " assigned to : " << GetWorkName(work) << endl;
    }

    void Act(TimeOfDay time)
    {
        if (time == TimeOfDay::Night || assignedWork == WorkType::None)
        {
            cout << name << " is sleeping." << endl;
        }
        else
        {
            cout << name << " is working on: " <<
                GetWorkName(assignedWork) << endl;
        }
    }
};

int main()
{
    World world;
    vector<Pal> pals = {
        { "Foxparks" },
        { "Tanzee" },
        { "Lamball" }
    };

    // 초기 작업 배정
    pals[0].Assign(WorkType::Building);
    pals[1].Assign(WorkType::Farming);
    pals[2].Assign(WorkType::Guarding);

    for (int t = 1; t <= 12; ++t)
    {
        cout << "\n== Tick " << t 
            << " (" << world.GetTimeString() << ") ==\n";
        for (auto& pal : pals)
        {
            pal.Act(world.GetCurrentTime());
        }
        world.AdvanceTime();
    }
}
