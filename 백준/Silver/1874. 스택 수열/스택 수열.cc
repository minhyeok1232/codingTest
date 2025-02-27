#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;

    int cnt = 1;

    stack<int> s;
    vector<char> v;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        while ( cnt <= num ) {
            s.push(cnt);
            v.push_back('+');
            cnt++;
        }

        if (s.top() == num)
        {
            s.pop();
            v.push_back('-');
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}