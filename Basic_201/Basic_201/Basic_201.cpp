// C++ 20
#include <iostream>
#include <string>
#include <optional>
#include <vector>

using namespace std;

struct Nameplate
{
    string name;
    optional<string> title;
};

void ApplyTitle(Nameplate& np, string_view newTitle)
{
    np.title = string(newTitle);
}

void ClearTitle(Nameplate& np)
{
    np.title.reset();
}

void RenderNameplate(const Nameplate& np)
{
    if (np.title.has_value())
    {
        cout << "[" << *np.title << "]" << endl;
    }
    cout << np.name << endl;
}

int main()
{
    vector<Nameplate> actors
    {
        {"아르", nullopt},
    };

    ApplyTitle(actors[0], "용의 학살자");

    for (size_t i = 0; i < actors.size(); i++)
    {
        RenderNameplate(actors[i]);
        cout << "----" << endl;
    }

    ClearTitle(actors[0]);
    cout << "타이틀 해제" << endl;
    for (size_t i = 0; i < actors.size(); i++)
    {
        RenderNameplate(actors[i]);
        cout << "----" << endl;
    }

    return 0;
}
