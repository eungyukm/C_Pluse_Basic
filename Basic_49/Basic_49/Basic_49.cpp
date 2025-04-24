// C++20 기준
#include <iostream>
using namespace std;

int main()
{
	int n = 1234;
	int rev = 0;

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	cout << "뒤집은 숫자:"
		<< rev << endl;
}