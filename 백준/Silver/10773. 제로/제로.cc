#include <iostream>
#include <stack>
using namespace std;
int main() {
    int N;
    stack<int> st;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(num != 0) st.push(num);
        else {
            st.pop();
        }
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
    return 0;
}