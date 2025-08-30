// C++20
#include <vector>
#include <string>
#include <optional>
#include <iostream>

using namespace std;

// 팰월드 아이템수리
struct FItem
{
    string Name;
    int Durability{ 0 };
    int MaxDurability{ 0 };
    bool bQueuedForRepair{ false };

    bool IsBroken() const
    {
        return Durability <= 0;
    }
};

class FInventory
{
public:
    void AddItem(const FItem& item)
    {
        Items.push_back(item);
    }

    vector<FItem>& All()
    {
        return Items;
    }

private:
    vector<FItem> Items;
};

class FRepairBench
{
public:
    // 내구도 0 아이템을 수리 목록에 추가
    void Enqueue(FItem& item)
    {
        if (item.bQueuedForRepair)
        {
            return;
        }
        Queue.push_back(&item);
        item.bQueuedForRepair = true;
    }

    // 다음 아이템 수리 수행
    optional<string> RepairNext()
    {
        if (Queue.empty())
        {
            return nullopt;
        }

        FItem* it = Queue.front();
        Queue.erase(Queue.begin());

        if (!it)
        {
            return nullopt;
        }

        it->Durability = it->MaxDurability;
        it->bQueuedForRepair = false;
        return it->Name;
    }

    const vector<FItem*>& GetQueue() const
    {
        return Queue;
    }

private:
    vector<FItem*> Queue;
};

// 고칠 아이템 Scan
void ScanAndQueueRepairs(FInventory& inv, FRepairBench& bench)
{
    auto& items = inv.All();

    for (size_t i = 0; i < items.size(); i++)
    {
        auto& it = items[i];
        if (it.IsBroken())
        {
            bench.Enqueue(it);
        }
    }
}

int main()
{
    FInventory inv;
    inv.AddItem({ "Stone Axe", 0, 50, false });
    inv.AddItem({ "Wood Pickaxe", 10, 40, false });
    inv.AddItem({ "Copper Sword", 0, 60, false });

    FRepairBench bench;
    ScanAndQueueRepairs(inv, bench);

    while (auto name = bench.RepairNext())
    {
        cout << "Repaired: " << *name << "\n";
    }
}
