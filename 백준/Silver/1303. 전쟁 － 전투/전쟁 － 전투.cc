#include <iostream>
using namespace std;
char arr[101][101];
bool _isVisited[101][101];
int N, M, W_ans, B_ans, W_result, B_result;
void dfs(int x, int y)
{
	_isVisited[x][y] = true;

	if (arr[x][y] == 'W')
	{
		W_ans++;
	}
	if (arr[x][y] == 'B')
	{
		B_ans++;
	}

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;

		if (arr[x][y] != arr[nx][ny]) continue;

		if (!_isVisited[nx][ny])
		{
			dfs(nx, ny);
		}
	}


}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!_isVisited[i][j])
			{
				W_ans = 0;
				B_ans = 0;
				dfs(i, j);
				W_result += W_ans * W_ans;
				B_result += B_ans * B_ans;
			}
		}
	}

	cout << W_result << " " << B_result << "\n";
	return 0;
}