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

struct Mail
{
    int          id;
    string       title;
    vector<Item> items;
    bool         isClaimed = false;
};

struct Inventory
{
    vector<Item> items;

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

void SendMail(vector<Mail>& mailBox, int mailId, 
    const string& title, const vector<Item>& items)
{
    Mail mail;
    mail.id = mailId;
    mail.title = title;
    mail.items = items;
    mail.isClaimed = false;
    mailBox.push_back(mail);
}

void ClaimMailItems(Inventory& inv, Mail& mail)
{
    if (mail.isClaimed || mail.items.empty())
    {
        cout << "이미 수령했거나 아이템이 없습니다\n";
        return;
    }

    for (int i = 0; i < mail.items.size(); i++)
    {
        inv.AddItem(mail.items[i]);
    }

    mail.items.clear();
    mail.isClaimed = true;
    cout << "우편 아이템 수령 완료\n";
}

int main()
{
    vector<Mail> mailBox;
    Inventory    inv;

    SendMail(mailBox, 1, "레이드 보상 우편", 
        { 
            Item{"골드", 100}, Item{"포션", 5} 
        });

    ClaimMailItems(inv, mailBox[0]);

    return 0;
}