// C++20
#include <iostream>
#include <random>

using namespace std;

bool IsHit(float hitRate) // hitRate: 0.0 ~ 100.0 (%)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.0f, 100.0f);

    float roll = dist(gen);
    return roll < hitRate;
}

int main()
{
    float hitRate = 75.0f; // 명중률 75%
    if (IsHit(hitRate))
    {
        cout << "공격이 명중했습니다!" << endl;
    }
    else
    {
        cout << "공격이 빗나갔습니다!" << endl;
    }

    return 0;
}
