#include <iostream>
using namespace std;
int main()
{
	int X;
	cin >> X;

	int sum = 0;
	int k = 0;
	while (sum < X)
	{
		sum += ++k;
	}
	int l = 1;

	while (sum > X)
	{
		sum--;
		l++;
		k--;
	}
	if ((l + k) % 2 == 1)
	{
		cout << k << "/" << l << endl;
	}
	else
	{
		cout << l << "/" << k << endl;
	}
	return 0;
}