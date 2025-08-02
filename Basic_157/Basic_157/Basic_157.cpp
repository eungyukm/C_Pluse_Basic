// C++20
#include <iostream>
#include <random>
#include <string>

using namespace std;

// 포획 시뮬레이션 함수
bool TryCapture(float catchRate)
{
    random_device rd;
    mt19937 rng(rd());
    uniform_real_distribution<float> dist(0.0f, 1.0f);

    const int maxShake = 3;
    int shakeCount = 0;

    for (int i = 0; i < maxShake; i++)
    {
        float roll = dist(rng);
        if (roll > catchRate)
        {
            cout << "Ball shook " << shakeCount
                << " time(s), then broke free " << endl;
            return false;
        }

        shakeCount++;
        cout << "Shake " << shakeCount << endl;
    }
}

// 테스트
int main()
{
    float catchRate = 0.4f; // 포획 확률 (0.0 ~ 1.0)
    TryCapture(catchRate);
    return 0;
}
