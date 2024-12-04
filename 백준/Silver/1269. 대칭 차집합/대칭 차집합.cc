#include <iostream>
#include <map>
using namespace std;
int main()
{
	int N;
	int M;
	map<int, bool> m;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		int num;
		cin >> num;
		if (m[num] == true)
			m.erase(num);
		else m[num] = true;
	}
	cout << m.size() << endl;
	return 0;
}