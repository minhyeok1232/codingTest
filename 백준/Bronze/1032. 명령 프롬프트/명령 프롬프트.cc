#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;

	vector<string> v;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	string ans = v[0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < ans.length(); j++)
		{
			if (ans[j] == '?') continue;
			if (ans[j] == v[i][j]) continue;
			else ans[j] = '?';
		}
	}
	
	cout << ans << '\n';
	return 0;
}
