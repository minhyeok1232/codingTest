#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare(pair<int, int>x, pair<int, int>y)
{
	if (x.first == y.first)
	{
		return x.second < y.second;
	}
	else
	{
		return x.first < y.first;
	}
}
int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), Compare);
	for (int i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << "\n";

	return 0;
}