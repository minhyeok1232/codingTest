#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;

    int cnt = 1;
    pair<int, int> code[50];

    for (int i = 0; i < N; i++) {
        cin >> code[i].first >> code[i].second;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (code[i].first < code[j].first && code[i].second < code[j].second) {
                cnt++;
            }
        }
        cout << cnt << " ";
        cnt = 1;
    }
}