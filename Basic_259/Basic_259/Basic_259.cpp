// C++20
#include <iostream>
#include <string>

using namespace std;

struct GuildResearch
{
    string name;
    int startTime{ -1 };   // 시작 시간 (분 단위 가정)
    int duration{ 60 };    // 연구 소요 시간
    bool inProgress{ false };
    bool completed{ false };
};

bool StartResearch(GuildResearch& r, int nowTime)
{
    if (r.inProgress == true || r.completed == true)
        return false;

    r.startTime = nowTime;
    r.inProgress = true;
    cout << r.name << "연구 시작 시간 " << nowTime << endl;
    return true;
}

void UpdateResearch(GuildResearch& r, int nowTime)
{
    if (r.inProgress == false)
        return;

    int elapsed = nowTime - r.startTime;
    if (elapsed >= r.duration)
    {
        r.inProgress = false;
        r.completed = true;
        cout << r.name << " 연구 완료 시간 " << nowTime << endl;
    }
    else
    {
        cout << r.name << " 연구 진행 중 경과 " << elapsed << "분"
            << endl;
    }
}

int main()
{
    GuildResearch r{ "길드 경험치 증가", -1, 60 };

    int t1 = 0;
    int t2 = 30;
    int t3 = 60;
    int t4 = 80;

    StartResearch(r, t1);
    UpdateResearch(r, t2);
    UpdateResearch(r, t3);
    UpdateResearch(r, t4);

    return 0;
}
