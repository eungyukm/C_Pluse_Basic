// C++20
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Food
{
    string name;
    int sanRecovery;
};

struct FoodBox
{
    vector<Food> foods;

    Food GetBestFood()
    {
        if (foods.empty())
        {
            cout << "FoodBox is empty!" << endl;
            return { "None", 0 };
        }

        // 가장 SAN 회복량이 높은 음식 선택
        auto best = max_element(foods.begin(), foods.end(), []
        (const Food& a, const Food& b)
            {
                return a.sanRecovery < b.sanRecovery;
            });
        return *best;
    }
};

struct Pal
{
    string name;
    int san = 50;

    void Eat(FoodBox& box)
    {
        Food bestFood = box.GetBestFood();
        if (bestFood.sanRecovery > 0)
        {
            san += bestFood.sanRecovery;
            cout << name << " ate " << bestFood.name
                << " and recovered SAN to " << san << endl;
        }
        else
        {
            cout << name << " found no food to eat." << endl;
        }
    }
};

int main()
{
    FoodBox box{ { {"Apple", 10}, {"Steak", 30}, {"Bread", 20} } };
    Pal pal{ "Pengullet" };

    pal.Eat(box);
}