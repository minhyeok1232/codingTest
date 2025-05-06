#include <iostream>
#include <vector>
using namespace std;
int White;
int Blue;

void DFS(int x, int y, int size, vector<vector<int>> arr)
{
	bool isZero = true;
	bool isOne  = true;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			// 한 영역에 다른 숫자라도 나오면 false
			if (arr[i][j] == 1) isZero = false;
			if (arr[i][j] == 0) isOne  = false;
		}
	}

	// 0 -> White
	if (isZero)
	{
		White++;
		return;
	}
	// 1 -> Blue
	if (isOne)
	{
		Blue++;
		return;
	}

	// 수가 다르면 재귀를 해야함..
	DFS(x, y, size / 2, arr);
	DFS(x + size / 2, y, size / 2, arr);
	DFS(x, y + size / 2, size / 2, arr);
	DFS(x + size / 2, y + size / 2, size / 2, arr);
}
int main()
{
	int N;
	cin >> N;
	vector<vector<int>> v(N);


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	DFS(0, 0, N, v);
	cout << White << '\n' << Blue << '\n';
	return 0;
}