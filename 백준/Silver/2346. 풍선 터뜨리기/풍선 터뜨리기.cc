#include <iostream>
#include <deque>

using namespace std;
int main()
{
    int N;
    cin >> N;
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        dq.push_back(make_pair(num, (i + 1)));
    }

    while (!dq.empty()) {
        int k = dq.front().first;
        cout << dq.front().second << " ";


        dq.pop_front();

        if (k > 0) {
            for (int i = 0; i < k - 1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            k = -k;
            for (int i = 0; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

    }

}