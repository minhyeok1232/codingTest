#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    vector<int> v;

    cin >> N;

    // 1. 몇 번 할지?
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        vector<long long> v = {1, 1, 1, 2, 2};

        // 2. 입력된 num 값 만큼
        for (int j = 5; j < num; j++) {
            v.push_back(v[j - 5] + v[j - 1]);
        }

        cout << v[num - 1] << '\n';

        // 벡터 초기화
        v.clear();
    }
}