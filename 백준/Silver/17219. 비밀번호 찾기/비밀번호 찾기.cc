#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	string ID;
	string Password;
	map<string, string> result;
	for (int i = 0; i < N; i++)
	{
		cin >> ID;
		cin >> Password;

		result.insert({ ID, Password });
	}

	for (int i = 0; i < M; i++)
	{
		cin >> ID;
		cout << result.find(ID)->second << endl;
	}


}