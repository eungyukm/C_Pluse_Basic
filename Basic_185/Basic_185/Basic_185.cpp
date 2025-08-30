// C++20
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

struct DropItem
{
    string name;
    float probability; // 0.0 ~ 1.0
};

string GetDrop(const vector<DropItem>& drops)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.0f, 1.0f);

    float randValue = dist(gen);
    float sum = 0.0f;

    for (auto& item : drops)
    {
        sum += item.probability;
        if (randValue <= sum)
        {
            return item.name;
        }
        return "Nothing";
    }
}

int main()
{
    vector<DropItem> drops =
    {
        {"Potion", 0.5f},
        {"Sword", 0.3f}
    };

    for (int i = 0; i < 5; i++)
    {
        cout << "Drop: " << GetDrop(drops) << endl;
    }
}
