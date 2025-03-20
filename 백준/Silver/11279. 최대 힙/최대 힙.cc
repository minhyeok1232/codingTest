#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(num);
        }
    }
}