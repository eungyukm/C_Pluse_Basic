// C++20
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Player
{
    string Name;
    int    Score = 0;   // 보스에게 준 기여 점수(=대미지 등)
    int    Gold = 0;   // 분배 골드
    string Item;        // 랭크 보상
};

void DistributeRewards(vector<Player>& ps, int bossGold)
{
    int n = (int)ps.size();
    int total = 0;
    for (int i = 0; i < n; i++) total += ps[i].Score;
    if (total == 0) return;

    // 기여도 비율 기반 골드 분배
    for (int i = 0; i < n; i++)
        ps[i].Gold = (ps[i].Score * bossGold) / total;

    // 랭크 보상 (Top 1~3)
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) { return ps[a].Score > ps[b].Score; });

    vector<string> rankItems{ "전설 상자", "영웅 상자", "희귀 상자" };
    for (int r = 0; r < (int)rankItems.size() && r < n; r++)
        ps[idx[r]].Item = rankItems[r];
}

int main()
{
    vector<Player> players{
        {"A", 1200}, {"B", 800}, {"C", 500}, {"D", 500}
    };

    DistributeRewards(players, 10000); // 보스 골드 풀 10,000

    for (int i = 0; i < (int)players.size(); i++)
        cout << players[i].Name << " 기여=" << players[i].Score
        << " → Gold=" << players[i].Gold
        << " / Item=" << (players[i].Item.empty() ? "-" : players[i].Item) << "\n";
}
