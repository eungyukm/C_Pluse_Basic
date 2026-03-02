// C++ 20
#include <iostream>
#include <string>

using namespace std;

struct Item
{
    string name;
    int id;
};

struct Listing
{
    Item item;
    int price;
    bool isSold;
};

struct Player
{
    string name;
    int gold;
    Item inventory[10];
    int inventoryCount;

    void AddItem(const Item& item)
    {
        if (inventoryCount >= 10) return;
        inventory[inventoryCount] = item;
        inventoryCount++;
    }
};

bool CanBuy(const Player& buyer, const Listing& listing)
{
    if (listing.isSold) return false;
    if (buyer.gold < listing.price) return false;
    return true;
}

void BuyItem(Player& buyer, Listing& listing)
{
    if (!CanBuy(buyer, listing))
    {
        cout << "구매 실패\n";
        return;
    }

    buyer.gold -= listing.price;
    buyer.AddItem(listing.item);
    listing.isSold = true;

    cout << buyer.name << " 가 " << listing.item.name
        << " 를 구매했습니다.\n";
}

int main()
{
    Player p{ "유저", 1000, {}, 0 };
    Listing listing{ {"전설 검", 1}, 500, false };

    BuyItem(p, listing);

    cout << "남은 골드: " << p.gold << "\n";
    cout << "인벤토리 개수: " << p.inventoryCount << "\n";

    return 0;
}
