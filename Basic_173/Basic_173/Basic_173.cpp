// C++20
#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// 제작 아이템 정보 구조체
struct FCraftRequest
{
    string ItemName;
    int CraftTimeSec;

    FCraftRequest(string name, int timeSec)
        : ItemName(name), CraftTimeSec(timeSec) {}
};

// 작업대 클래스
class FWorkBench
{
private:
    queue<FCraftRequest> CraftQueue;
    bool bIsCrafting = false;

public:
    void AddCraftRequest(const FCraftRequest& request)
    {
        CraftQueue.push(request);
        cout << "[예약] " << request.ItemName << " 제작 예약됨\n";

        // 제작 중이 아니라면 즉시 제작 시작
        if (!bIsCrafting)
        {
            StartNextCraft();
        }
    }

private:
    void StartNextCraft()
    {
        if (CraftQueue.empty())
        {
            bIsCrafting = false;
            return;
        }

        bIsCrafting = true;
        FCraftRequest current = CraftQueue.front();
        CraftQueue.pop();

        cout << "[제작 시작] " << current.ItemName
            << " (" << current.CraftTimeSec << "초" << endl;

        // 비동기적 제작 진행
        thread([this, current]()
            {
                this_thread::sleep_for(chrono::seconds(current.CraftTimeSec));
                cout << "[제작 완료] " << current.ItemName << endl;
                bIsCrafting = false;
                StartNextCraft();
            }).detach();
    }
};

// 메인
int main()
{
    FWorkBench WorkBench;

    WorkBench.AddCraftRequest({ "나무 칼", 2 });
    WorkBench.AddCraftRequest({ "철 도끼", 3 });
    WorkBench.AddCraftRequest({ "물약", 1 });

    // 메인 스레드 유지용
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}
