#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M;
	map<int, bool> check;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int card;
		cin >> card;
		check.insert({ card, true });
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int k;
		cin >> k;
		if (check[k]) cout << "1" << " ";
		else cout << "0" << " ";
	}

	return 0;
}