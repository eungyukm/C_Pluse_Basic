// C++20
#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 5;

int main()
{
	vector<vector<int>> terrain(HEIGHT, vector<int>(WIDTH));
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 9);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			terrain[y][x] = dist(gen);
		}
	}

	for (const auto& row : terrain)
	{
		for (int h : row)
		{
			cout << h << ' ';
		}
		cout << endl;
	}
	return 0;
}
