#include <iostream>
using namespace std;
int main()
{
	int kind, total_money;
	int coin[11];
	cin >> kind >> total_money;

	// 동전은 오름차순으로 입력
	for (int i = 0; i < kind; i++)
		cin >> coin[i];

	// 시작은 0부터 시작한다.
	int sum = 0;

	// Greedy로 풀어나가기 위해서, 큰 동전부터 처리 (역순)
	for (int i = kind - 1; i >= 0; i--)
	{
		// 동전이 여러개가 될 수 있음..
		// 4200원이면 1000x4, 100x2
		sum += (total_money / coin[i]);
		total_money %= coin[i];
	}

	cout << sum << '\n';
}