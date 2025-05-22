// C++20 기준
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pal
{
    string name;
    string role;
    int efficiency; // 생산력
};

struct Task
{
    string name;
    string requiredRole;
};

vector<string> AssignByEfficiency(const vector<Pal>& pals, const vector<Task>& tasks)
{
    vector<string> assignments(tasks.size(), "No Match");

    for (int i = 0; i < tasks.size(); i++)
    {
        int bestEff = -1;
        for (const auto& pal : pals)
        {
            if (pal.role == tasks[i].requiredRole && pal.efficiency > bestEff)
            {
                assignments[i] = pal.name;
                bestEff = pal.efficiency;
            }
        }
    }

    return assignments;
}

int main()
{
    vector<Pal> pals = {
        { "Chicklet", "farming", 50 },
        { "Moler", "farming", 80 },
        { "Burny", "factory", 70 }
    };

    vector<Task> tasks = {
        { "Harvest Wheat", "farming" },
        { "Process Ore", "factory" }
    };

    auto results = AssignByEfficiency(pals, tasks);
    for (int i = 0; i < results.size(); ++i)
    {
        cout << tasks[i].name << " -> " << results[i] << endl;
    }
}
