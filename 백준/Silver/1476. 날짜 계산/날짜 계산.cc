#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	int result = 0;
	cin >> A >> B >> C;

	int x = 1;
	int y = 1;
	int z = 1;

	while (!(A == x && B == y && C == z))
	{
		x++;
		y++;
		z++;
		if (x > 15) x -= 15;
		if (y > 28) y -= 28;
		if (z > 19) z -= 19;

		result++;
	}
	result++;
	cout << result;
}