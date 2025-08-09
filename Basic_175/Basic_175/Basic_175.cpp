// C++20
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 건물 구조체
struct FBuilding
{
    string Id;
    bool bDestroyed{ false };
    // 지지대
    int AliveSupporters{ 0 };
};

// 월드 클래스
class FWorld
{
public:
    unordered_map<string, vector<string>> G;
    unordered_map<string, FBuilding> B;
    // 건물 추가
    void AddBuilding(const string& id, int supporters)
    {
        B.try_emplace(id, FBuilding{ id, false, supporters });
    }
    // 건물의 간선 추가 (지지 역할)
    void AddSupportEdge(const string& supporter, const string& dependent)
    {
        G[supporter].push_back(dependent);
    }

    void DestroyCascade(const string& id)
    {
        // 이미 파괴된 경우 제외
        if (!B.contains(id) || B[id].bDestroyed)
        {
            return;
        }

        queue<string> q;
        // id로 들어온 값 파괴
        auto Mark = [&](const string& x)
            {
                B[x].bDestroyed = true;
                q.push(x);
            };

        Mark(id);
       
        while (!q.empty())
        {
            const string currentId = q.front();
            q.pop();

            // 건물의 간선 탐색
            auto gIt = G.find(currentId);
            if (gIt == G.end())
            {
                continue;
            }

            // gIt->second를 바로 사용
            for (const string& dependentId : gIt->second)
            {
                auto bIt = B.find(dependentId);   
                if (bIt == B.end())
                {
                    continue;
                }

                FBuilding& dependent = bIt->second;
                if (dependent.bDestroyed)
                {
                    continue;
                }
                // 건물 지지대 파괴
                dependent.AliveSupporters -= 1;

                if (dependent.AliveSupporters <= 0)
                {
                    dependent.AliveSupporters = 0;
                    Mark(dependentId);
                }
            }
        }
    }
};

int main()
{
    FWorld world;
    // 건물 파괴 알고리즘

    // 건물 추가
    world.AddBuilding("A", 0); // 토대
    world.AddBuilding("B", 1); // A가 지지
    world.AddBuilding("C", 1); // B가 지지
    world.AddBuilding("D", 2); // B, C가 지지

    // 지지 관계 설정
    world.AddSupportEdge("A", "B");
    world.AddSupportEdge("B", "C");
    world.AddSupportEdge("B", "D");
    world.AddSupportEdge("C", "D");

    // A 파괴 -> 연쇄 파괴 발생
    world.DestroyCascade("D");

    // 결과 출력
    for (auto& [id, building] : world.B)
    {
        cout << id << " : " << (building.bDestroyed ? "Destroyed" : "Alive") 
            << endl;
    }

    return 0;
}