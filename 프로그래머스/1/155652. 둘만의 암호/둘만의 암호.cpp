#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index)
{
    string answer = s;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < index; j++)
        {
            s[i]++;

            if (s[i] > 'z')
            {
                s[i] = 'a';
            }

            while (skip.find(s[i]) != string::npos)
            {
                s[i]++;  
                if (s[i] > 'z')  
                {
                    s[i] = 'a';
                }
            }
        }
    }

    answer = s;
    return answer;
}

int main()
{
    string a;
    string b;
    int _num;

    cin >> a;
    cin >> b;
    cin >> _num;

    string result = solution(a, b, _num);
    cout << result << endl;
    return 0;
}