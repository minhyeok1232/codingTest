#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	map<string, int> names;
	queue<string> ans;
	for (int i = 0; i < N + M; i++)
	{
		string name;
		cin >> name;
		names[name]++;
	}

	for (auto a : names)
	{
		if (a.second == 2)
		{
			ans.push(a.first);
		}
	}
	
	cout << ans.size() << endl;
	while (!ans.empty())
	{
		cout << ans.front() << endl;
		ans.pop();
	}

	return 0;
}