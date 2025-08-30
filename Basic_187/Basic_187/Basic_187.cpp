// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> jobs =
    {
        "Warrior",
        "Mage",
        "Gunner",
        "Assassin"
    };

    cout << "=== Character Creation ===" << endl;
    for (int i = 0; i < jobs.size(); i++)
    {
        cout << i + 1 << ") " << jobs[i] << endl;
    }

    int pick;
    cout << "Choose Job : ";
    cin >> pick;
    if (pick < 1 || pick > jobs.size())
    {
        cout << "Invalid selection" << endl;
        return 0;
    }

    string name;
    cout << "Enter Name: ";
    cin >> name;

    cout << "character Created Job: " << jobs[pick - 1]
        << ", Name: " << name << endl;
    return 0;
}
