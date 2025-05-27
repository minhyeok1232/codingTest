#include <iostream>
#include <queue>
using namespace std;
int N, K;
void make_queue(queue<int> &vq) {
    for (int i = 0; i < K - 1; i++) {
        int front = vq.front();
        vq.pop();
        vq.push(front);
    }

    if (vq.size() > 1)
        cout << vq.front() << ", ";
    else
        cout << vq.front();
    vq.pop();

    while (!vq.empty()) {
        make_queue(vq);
    }
}

int main() {
    cin >> N >> K;
    queue<int> q;

    // Queue에 등록
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    cout << '<';
    make_queue(q);
    cout << '>';
}

