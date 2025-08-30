// C++20
#include<string>
#include<iostream>
using namespace std;

enum class eInputState
{
    Pressed,
    Released
};

struct InputEvent
{
    string key;
    eInputState state;
};

class PlayerActions
{
public:
    void Collect()
    {
        cout << "[Action] Collect Resource" << endl;
    }
};

class InputRouter
{
public:
    InputRouter(PlayerActions& a) : _act(a)
    {

    }

    void Handle(const InputEvent& ev)
    {
        if (ev.state == eInputState::Released && ev.key == "E")
        {
            _act.Collect();
        }
    }
private:
    PlayerActions& _act;
};

int main()
{
    PlayerActions actions;
    InputRouter router(actions);

    router.Handle({ "E", eInputState::Pressed });
    router.Handle({ "E", eInputState::Released });

    return 0;
}
