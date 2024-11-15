#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
	int N;
	map<string, int> count;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string filename;
		cin >> filename;
		int dot_pos = filename.find('.');
		string ext = filename.substr(dot_pos + 1);

		count[ext]++;
	}

	for (auto& a : count)
	{
		cout << a.first << " " << a.second << endl;
	}
}