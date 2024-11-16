#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		map<string, int> passion;

		cin >> M;
		cin.ignore();
		for (int j = 0; j < M; j++)
		{
			string s;
			getline(cin, s);				// 한줄 전체를 입력받기위해서 사용하는 것임('띄어쓰기')
			int pos = s.find(' ');
			string k = s.substr(pos);
			passion[k]++;
		}

		// N이 0일때와 1일때는 따로해야함...
		int result = 1;

		for (auto a : passion)
		{
			result = result * (a.second + 1);
		}
		result--;
		cout << result << endl;
	}
}