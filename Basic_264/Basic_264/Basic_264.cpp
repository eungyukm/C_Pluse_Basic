// C++20
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item
{
    string name;
    int    count;
};

struct Listing
{
    int    id;
    Item   item;
    int    price;      // 개당 가격
    bool   isSold = false;
};

struct Inventory
{
    vector<Item> items;
    int          gold = 0;

    bool RemoveItem(const string& name, int count)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name == name && items[i].count >= count)
            {
                items[i].count -= count;
                if (items[i].count == 0)
                {
                    items.erase(items.begin() + i);
                }
                return true;
            }
        }
        return false;
    }

    void AddItem(const Item& item)
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].name == item.name)
            {
                items[i].count += item.count;
                return;
            }
        }
        items.push_back(item);
    }
};

void RegisterListing(vector<Listing>& market, 
    Inventory& seller, int listingId, const string& itemName, 
    int count, int price)
{
    if (!seller.RemoveItem(itemName, count))
    {
        cout << "판매 등록 실패: 아이템 부족\n";
        return;
    }

    Listing l;
    l.id = listingId;
    l.item = Item{ itemName, count };
    l.price = price;
    l.isSold = false;

    market.push_back(l);
    cout << "거래소에 아이템 등록 완료\n";
}


int main()
{
    Inventory seller;
    seller.items.push_back(Item{ "포션", 10 });

    Inventory buyer;
    buyer.gold = 1000;

    vector<Listing> market;

    RegisterListing(market, seller, 1, "포션", 5, 50);
    
    return 0;
}
