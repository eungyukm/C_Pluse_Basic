// C++20
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
using namespace std;

struct Region
{
    int total{};
    int done{};
    double percent() const
    {
        if (total == 0)
        {
            return 0.0;
        }
        return (static_cast<double>(done) * 100.0) / total;
    }
};

struct AdventureTome
{
    unordered_map<string, Region> data;

    void addRegion(const string& name, int total)
    {
        data[name] = Region{ total, 0 };
    }

    void completeQuest(const string& name)
    {
        auto it = data.find(name);
        if (it == data.end())
        {
            return;
        }
        auto& r = it->second;
        if (r.done < r.total)
        {
            r.done++;
        }
        cout << name << " : " << r.done << " / " << r.total << " ("
            << fixed << setprecision(1) << r.percent() << "%)\n";
    }
};

int main()
{
    AdventureTome tome;
    // 지역 퀘스트 수
    tome.addRegion("Rethramis", 8);    
    tome.addRegion("Yudia", 6);

    // 지역 퀘스트 완료 시 퍼센트 증가 로직
    tome.completeQuest("Rethramis");
    tome.completeQuest("Rethramis");
    tome.completeQuest("Yudia");

    return 0;
}
