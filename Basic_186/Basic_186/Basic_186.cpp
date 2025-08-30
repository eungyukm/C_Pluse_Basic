// C++20
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item
{
    string name;
    int count;
};

struct Chest
{
    vector<Item> items;
};

// 아이템을 모두 Chest 0으로 모으는 함수
void GatherItem(vector<Chest>& chests, const string& itemName)
{
    if (chests.empty())
    {
        return;
    }

    int total = 0;

    // Chest 0을 제외한 나머지에서 수집
    for (size_t i = 1; i < chests.size(); i++)
    {
        for (auto& it : chests[i].items)
        {
            if (it.name == itemName)
            {
                total += it.count;
                it.count = 0;
            }
        }
    }

    // chest 0에도 같은 아이템이 있다면 더해줌
    for (auto& it : chests[0].items)
    {
        if (it.name == itemName)
        {
            it.count += total;
            break;
        }
    }
}

int main()
{
    vector<Chest> chests(3);
    chests[0].items.push_back({ "PalMeat", 2 });
    chests[1].items.push_back({ "PalMeat", 5 });
    chests[2].items.push_back({ "PalMeat", 3 });

    cout << "[Before Gather]\n";
    for (size_t i = 0; i < chests.size(); i++)
    {
        for (auto& it : chests[i].items)
        {
            cout << "Chest " << i << " -> " << it.name
                << ": " << it.count << '\n';
        }
    }
        
    // 버튼 클릭
    GatherItem(chests, "PalMeat");

    cout << "\n[After Gather]\n";
    for (size_t i = 0; i < chests.size(); i++)
    {
        if (chests[i].items.empty())
        {
            cout << "Chest " << i << " is empty\n";
        }
        else
        {
            for (auto& it : chests[i].items)
            {
                cout << "Chest " << i << " -> " 
                    << it.name << ": " << it.count << '\n';
            }
        }
    }
}
