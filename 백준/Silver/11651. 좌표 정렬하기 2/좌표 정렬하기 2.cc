#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool Compare(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second)
        return A.first < B.first;
    return A.second < B.second;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<pair<int ,int>> result;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        result.push_back({x, y});
    }

    sort(result.begin(), result.end(), Compare);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second << '\n';
    }
    return 0;
}