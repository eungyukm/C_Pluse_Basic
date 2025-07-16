// C++20
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pal
{
    string name;

    Pal(string n) : name(n) {}
};

queue<Pal> waitingQueue;

void EnterFacility(Pal pal)
{
    waitingQueue.push(pal);
    cout << pal.name << " is wating for the facility." << endl;
}

void UseFacility()
{
    if (waitingQueue.empty())
    {
        cout << "No one is wating." << endl;
        return;
    }

    Pal pal = waitingQueue.front();
    waitingQueue.pop();
    cout << pal.name << " is using the facility." << endl;
}

int main()
{
    EnterFacility(Pal("Pengullet"));
    EnterFacility(Pal("Foxparks"));
    EnterFacility(Pal("Lamball"));

    UseFacility();
    UseFacility();
    UseFacility();
    UseFacility();
}
