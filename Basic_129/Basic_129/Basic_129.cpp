// C++20
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FoodBox
{
    string name = "Food Box";
};

struct Pal
{
    string name;
    int hunger = 100;
    bool isWorking = true;

    void Tick()
    {
        hunger -= 5;
        cout << name << " Hunger: " << hunger << endl;

        if (hunger <= 30)
        {
            isWorking = false;
            FindFood();
        }
    }

    void FindFood()
    {
        cout << name << " is looking for food!" << endl;
        Eat(FoodBox{});
    }

    void Eat(const FoodBox& foodBox)
    {
        hunger += 50;
        isWorking = true;
        cout << name << " ate food from " << foodBox.name
            << " and resumed working." << endl;
    }
};

int main()
{
    Pal pal{ "Foxparks" };

    for (int i = 0; i < 20; i++)
    {
        pal.Tick();
        if (!pal.isWorking)
            break;
    }
}
