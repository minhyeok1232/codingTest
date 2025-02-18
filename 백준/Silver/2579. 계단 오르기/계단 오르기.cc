#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    int stair[1001];
    int sum[1001];

    // 계단의 수는 동적(Vector)로 처리한다.
    for (int i = 1; i <= N; i++) {
        cin >> stair[i]; // stair 벡터에 값 입력
    }

    // 1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
    // 2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
    // 3. 마지막 도착 계단은 반드시 밟아야 한다.

    // 1번째 계단
    sum[1] = stair[1];

    // 2번째 계단
    sum[2] = stair[1] + stair[2];

    // 3번째 계단 >> 2번조건에 의해, 1번째와 3번째를 거치던지 2번째와 3번째를 거쳐야함
    sum[3] = max(stair[1] + stair[3], stair[2] + stair[3]);


    for (int i = 4; i <= N; i++) {
        int two_lower_stair = sum[i - 2] + stair[i];
        int one_lower_stair = sum[i - 3] + stair[i - 1] + stair[i];
        sum[i] = max(two_lower_stair, one_lower_stair);
    }

    cout << sum[N] << '\n';
    return 0;
}