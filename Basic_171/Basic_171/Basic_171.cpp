// C++20
#include <iostream>
#include <random>
#include <string>

using namespace std;

string GenerateEgg()
{
    float chance = 0.5f;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0.0f, 1.0f);

    return (dist(gen) < chance) ? "거대 알" : "일반 알";
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "[알 생성] " << GenerateEgg() << endl;
    }
    return 0;
}
