#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
int arr[101];
bool visit[101];
void dfs(int current, int start)
{
	if (visit[current])
	{
		if (start == current)	// 1->3   3->1 까지가버렸네..
		{
			v.push_back(current);
		}
		return;
	}

	visit[current] = true;
	dfs(arr[current], start);
}

int main()
{
	cin >> N;
	arr[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}

	//sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}