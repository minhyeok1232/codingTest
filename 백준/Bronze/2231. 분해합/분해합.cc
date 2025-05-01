#include <iostream>
using namespace std;
int main()
{
	int N;
	int result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;

		int k = i;
		// N값의 각 자리수 더하기
		while (k != 0)
		{
			sum += (k % 10);
			k /= 10;
		}
		if (sum + i == N)
		{
			result = i;
			break;
		}
	}
	cout << result << '\n';
}