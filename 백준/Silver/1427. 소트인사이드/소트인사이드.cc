#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	sort(s.begin(), s.end());
	for (int i = s.length() - 1; i >= 0; i--)
	{
		cout << s[i];
	}
	return 0;
}