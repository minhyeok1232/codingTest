#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;


    for (int i = 0; i < s.length(); i++)
    {
        // '('로 시작하고 ')'로 닫아줌
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            // 웬만하면 ')'이 들어오면 pop을 해줘야하지만..
            // 만약에.. ()) 이런식으로 들어오면 pop할 수가 없음
            
            // 비어있으면?
            if (st.empty())
            {
                st.push(')');
            }
            else
            {
                st.pop();
            }
        }
    }

    // answer이 true가 되어야하는 조건 : stack이 비어있어야한다.
    // for루프를 다 돈 이후임.
    if (st.empty()) answer = true;
    else answer = false;

    return answer;
}

int main()
{
    string str;
    int result = solution(str);
    cout << result << endl;
    return 0;
}