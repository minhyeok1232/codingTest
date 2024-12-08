#include <iostream>
#include <vector>
using namespace std;
int N, M;
int arr[1002][1002] = { 0, };

void MakeGet() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        arr[i][0] = i;
    }
    for (int i = 1; i <= M; i++) {
        arr[N + 1][i] = N + i;
    }
    for (int i = 1; i <= N; i++) {
        arr[N + 1 - i][M + 1] = N + M + i;
    }
    for (int i = 1; i <= M; i++) {
        arr[0][M + 1 - i] = 2 * N + M + i;
    }
}

int Solve(int i, int j, int Direction) {
    if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
        return arr[i][j];
    }
    if (arr[i][j] == 0) {
        if (Direction == 0) return Solve(i, j + 1, 0);
        else if (Direction == 1) return Solve(i-1, j, 1);
        else if (Direction == 2) return Solve(i, j-1, 2);
        else return Solve(i + 1, j, 3);
    }
    else {
        if (Direction == 0) return Solve(i - 1, j, 1);
        else if (Direction == 1) return Solve(i, j+1, 0);
        else if (Direction == 2) return Solve(i+1, j, 3);
        else return Solve(i, j - 1, 2);
    }
}

int main() {
    MakeGet();
    for (int i = 1; i <= N; i++) {
        cout << Solve(i, 1, 0) << " ";
    }
    for (int i = 1; i <= M; i++) {
        cout << Solve(N, i, 1) << " ";
    }
    for (int i = N; i >= 1; i--) {
        cout << Solve(i, M, 2) << " ";
    }
    for (int i = M; i >= 1; i--) {
        cout << Solve(1, i, 3) << " ";
    }
}