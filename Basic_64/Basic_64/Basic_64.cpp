// C++17
#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

struct Reward 
{
    string name;
    float chance;
};

string OpenRewardBox(const vector<Reward>& rewards)
{
    // 난수 생성기 설정
    // 하드웨어 시드용 난수 생성 (매번 다른 시드 제공)
    random_device rd;
    // (고성능 의사 난수 생성기)
    mt19937 gen(rd());

    // [0.0, 100.0] 사이 실수 난수 생성
    uniform_real_distribution<> dis(0.0, 100.0);

    // 무작위 수 뽑기
    float roll = dis(gen);
    float cumulative = 0.0f;

    // 누적 활률 기반 선택
    for (const auto& reward : rewards)
    {
        cumulative += reward.chance;
        if (roll <= cumulative)
        {
            return reward.name;
        }
    }

    return "Nothing";
}

int main() {
    // 보상 테이블 설정
    vector<Reward> box = {
        {"Gold", 40.0f},
        {"Potion", 25.0f},
        {"Gem", 10.0f},
        {"Rare Sword", 5.0f},
        {"Nothing", 20.0f}
    };

    cout << "Opening the box..." << endl;;

    string reward = OpenRewardBox(box);
    cout << "You got: " << reward << endl;

    return 0;
}
