#include <iostream>
#include <deque>
using namespace std;
int main() {
    int N;
    cin >> N;
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        dq.push_back(i + 1);
    }
    // 1 2 3 4 5 6
    // 처음에는 front에있는 원소를 빼고
    // 그다음에 남은 back에다가 dq.push_back(dq.front()) 작업을 해줘야함.
    while (dq.size() > 1) {
        dq.pop_front();                 // size : 5
        dq.push_back(dq.front());     // size : 6
        dq.pop_front();                 // size : 5
        // 이 3가지 동작이 한번의 동작이다.

    }
    // 남은 원소를 출력해야함.
    cout << dq.front();
    return 0;
}