#include <iostream>
using namespace std;
int M, N;
int arr[9];
bool _isVisited[9];
void dfs(int k)
{
	bool _isTrue = true;
	if (k == M)
	{
		for (int i = 0; i < M; i++)
		{
			if (i > 0 && arr[i] < arr[i - 1])
			{
				_isTrue = false;
			}
		}

		for (int i = 0; i < M; i++)
		{
			if (!_isTrue) continue;
			cout << arr[i] << " ";
		}

		if(_isTrue)	cout << "\n";
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!_isVisited[i])
			{
				_isVisited[i] = true;
				arr[k] = i;
				dfs(k + 1);
				_isVisited[i] = false;
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < 9; i++)
	{
		_isVisited[i] = false;
	}
	dfs(0);
}