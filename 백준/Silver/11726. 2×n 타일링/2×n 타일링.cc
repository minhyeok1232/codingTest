#include <iostream>
using namespace std;
int arr[1001];
int result[1001];
int main() {
    // 1. 입력
    int N;
    cin >> N;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= N; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    cout << arr[N] << '\n';
}