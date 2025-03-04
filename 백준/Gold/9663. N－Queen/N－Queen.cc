#include <iostream>
#include <cmath>
using namespace std;
int n;  // 다른 함수에서 적용하기 위해 전역으로 선언
int cnt = 0;
int col[16];

// ------------------------- 순서 ------------------------------
// 1. 0번째 행부터 진행을 한다.
// 2. 각 행에 "Queen"을 배치하는 과정에서, 배치에 문제가 없으면 다음 행으로 넘어간다. (Queen의 재귀함수)
// 3. 그렇게 x가 n까지 가게 되면 모든 행 배치가 끝났단 소리이므로, cnt(카운트)값이 증가한다.
//
// Q) 2차원으로 하지않고 1차원으로 하는 이유가 무엇이냐?
// A) 행은 어차피 탐색하면서 1행씩 증가하기 때문에, 열에 배치하는 부분에만 신경을 써주면 되기 때문이다.
//
// Q) 무슨 알고리즘인가?
// A) 브루트포스 알고리즘이다.
//    >> 브루트포스 알고리즘이란? 해답이 없으면, 무시하고 다음으로 넘어가는 알고리즘이다.

bool check(int k) {
    for (int i = 0; i < k; i++) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k)) return false;
        // 1. col[i] == col[k]
        //   >> 같은 열에 배치
        // 2. abs(col[i] - col[k]) == abs(i - k)
        //   >> 대각선 배치
    }
    return true;
}
void Queen(int x) {
    // Queen(x+1)로 재귀되는 형태로서, n까지 가게 되면
    // Queen을 배치하는 부분에 이상이 없으므로, 하나의 경우의수 (cnt)를 늘려준다.
    if (x == n) cnt++;
    else {
        // x가 n이 될 때 까지 Queen을 배치하는 과정이다.
        for (int i = 0; i < n; i++) {
            col[x] = i; // x값의 증가는 Queen(x + 1)의 재귀로 알아서 증가한다.
                        // 당장의 for문에서 x번째 행에 "몇 번째(i)"열에 배치를 해야 할까? 가 우선이다.
            if (check(x) == true) Queen(x + 1);
        }
    }
}
int main() {
    cin >> n;
    // 0번째부터 순차적으로 탐색을 한다. (브루트포스)
    Queen(0);
    cout << cnt << '\n';
}