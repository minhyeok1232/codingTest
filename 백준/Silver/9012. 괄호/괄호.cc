#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		
		stack<char> s;

		string ans = "YES";

		for (int j = 0; j < str.length(); j++)
		{
			// 조건세우기
			if (str[j] == '(')
			{
				s.push('(');
			}
			else if (str[j] == ')' && !s.empty() && s.top() == '(')
			{
				s.pop();
			}
			else
			{
				ans = "NO";
				break;
			}
		}
		if (!s.empty()) ans = "NO";
		cout << ans << '\n';
	}
}