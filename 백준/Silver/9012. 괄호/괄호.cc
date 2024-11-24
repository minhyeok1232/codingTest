#include <iostream>
#include <stack>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        stack<char> st;
        cin >> s;
        string ans = "YES";

        for (int j = 0; j < s.length(); j++) {
           if (s[j] == '(') {
               st.push(s[j]);
           }
            else if (s[j] == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                ans = "NO";
                break;
            }
        }
        if (!st.empty()) ans = "NO";
        cout << ans << endl;
    }
    return 0;
}