// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MedicineBox
{
    string name = "Medicine Box";
    bool available = true;
};

struct Pal
{
    string name;
    bool injured = false;
    bool isWorking = true;

    void Update(const MedicineBox& box)
    {
        if (injured)
        {
            if (box.available)
            {
                cout << name << " is moving to " << box.name << "." << endl;
            }
            else
            {
                isWorking = false;
                cout << name << " stopped all work due to injury." << endl;
            }
        }
        else
        {
            cout << name << " is working." << endl;
        }
    }
};

int main()
{
    Pal pal{ "Pengullet", true };
    MedicineBox box;

    pal.Update(box);
}