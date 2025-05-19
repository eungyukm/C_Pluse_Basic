// C++20 기준
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pal
{
    string name;
    string role; // "farming", "factory", "combat"
};

struct Task
{
    string name;
    string requiredRole;
};

vector<string> AssignTasks(const vector<Pal>& pals, const vector<Task>& tasks)
{
    vector<string> assignments(tasks.size(), "No Match");

    for (int i = 0; i < tasks.size(); i++)
    {
        for (const auto& pal : pals)
        {
            if (pal.role == tasks[i].requiredRole)
            {
                assignments[i] = pal.name;
                break;
            }
        }
    }
    return assignments;
}

int main()
{
    vector<Pal> pals = {
        { "Foxy", "farming" },
        { "Torrex", "factory" },
        { "Blazey", "combat" }
    };

    vector<Task> tasks = {
        { "Harvest Corn", "farming" },
        { "Smelt Iron", "factory" },
        { "Defend Base", "combat" }
    };

    auto result = AssignTasks(pals, tasks);
    for (int i = 0; i < result.size(); i++)
    {
        cout << tasks[i].name << " -> " << result[i] << endl;
    }
}