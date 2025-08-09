// C++20
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <optional>

using namespace std;

// 알 오브젝트
struct FEgg
{
    string Species;
    FEgg(const string& species)
        : Species(species) {}

    void Print()
    {
        cout << "[생성 완료] " << Species << " 알이 생성되었습니다!" << endl;
    }
};

// 교배 목장 클래스
class FBreedingFarm
{
private:
    bool bHasCake = false;
    chrono::seconds IncubationTime = chrono::seconds(5);
    optional<shared_ptr<FEgg>> ResultEgg;

public:
    void InsertCake()
    {
        if (bHasCake)
        {
            cout << "[안내] 이미 케이크가 들어있습니다.\n";
            return;
        }

        bHasCake = true;
        cout << "[입력] 케이크가 들어갔습니다. 부화 대기 중...\n";

        thread([this]()
            {
                this_thread::sleep_for(IncubationTime);
                ResultEgg = make_shared<FEgg>("랜덤팰");

                bHasCake = false;

                cout << "[타이머 완료] 알이 생성되었습니다!" << endl;
                ResultEgg->get()->Print();
            }).detach();
    }

    bool HasEgg() const
    {
        return ResultEgg.has_value();
    }

    shared_ptr<FEgg> CollectEgg()
    {
        if (!ResultEgg.has_value())
        {
            cout << "[안내] 아직 생성된 알이 없습니다.\n";
            return nullptr;
        }

        auto egg = ResultEgg.value();
        ResultEgg.reset();
        cout << "[수집] 알을 수집했습니다.\n";
        return egg;
    }
};

// 테스트용 메인 함수
int main()
{
    FBreedingFarm Farm;
    Farm.InsertCake();

    // 유저가 기다리는 동안 메시지 반복 출력
    for (int i = 0; i < 10; ++i)
    {
        cout << ".";
        this_thread::sleep_for(chrono::seconds(1));
    }

    auto egg = Farm.CollectEgg();
    if (egg)
        cout << "수집된 알: " << egg->Species << endl;

    return 0;
}
