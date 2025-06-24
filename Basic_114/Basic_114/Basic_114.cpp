// C++20 기준
#include <iostream>
#include <memory>
using namespace std;

struct WeatherState
{
	virtual void Apply() const = 0;
	virtual ~WeatherState() = default;
};

struct Sunny : WeatherState
{
	void Apply() const override
	{
		cout << "맑음" << endl;
	}
};

struct Rainy : WeatherState
{
	void Apply() const override
	{
		cout << "비" << endl;
	}
};

class WeatherSystem
{
	unique_ptr<WeatherState> state;

public:
	void Set(unique_ptr<WeatherState> s)
	{
		state = move(s);
	}

	void Update() const
	{
		if (state)
		{
			state->Apply();
		}
	}
};
int main()
{
	WeatherSystem ws;
	ws.Set(make_unique<Sunny>());
	ws.Update();
	ws.Set(make_unique<Rainy>());
	ws.Update();
}