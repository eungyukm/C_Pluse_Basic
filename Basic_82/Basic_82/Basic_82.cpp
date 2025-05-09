// C++20 기준
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Unit {
    string name;
    vector<string> traits;
};

// 시너지 카운트
unordered_map<string, int> CountSynergies(const vector<Unit>& units)
{
    unordered_map<string, int> counts;
    for (const auto& u : units)
    {
        for (const auto& trait : u.traits)
        {
            counts[trait]++;
        }
    }
    return counts;
}

int main() {
    vector<Unit> board = {
        {"Garen", {"Warlord", "Vanguard"}},
        {"Jarvan", {"Warlord"}},
        {"Katarina", {"Warlord"}},
        {"Annie", {"Mage"}},
        {"Lulu", {"Mage"}},
        {"Veigar", {"Mage"}}
    };

    auto counts = CountSynergies(board);
    cout << "시너지 카운트" << endl;
    for (const auto& [trait, count] : counts)
    {
        cout << " - " << trait << " : " << count << endl;
    }
}
