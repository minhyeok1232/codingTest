#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check(string s1, string s2) {
    int len = s1.length();
    int visited1[27] = {0, };
    int visited2[27] = {0, };
    bool isVisited = false;

    // abca
    // xbyx

    for (int i = 0; i < len; i++) {
        int idx1 = s1[i] - 'a' + 1;
        int idx2 = s2[i] - 'a' + 1;
        if (!visited1[idx1] && !visited2[idx2])
        {
            visited1[idx1] = idx2;
            visited2[idx2] = idx1;
        }
        else if(visited1[idx1] != idx2)
        {
            isVisited = true;
        }
    }
    return isVisited;
}
int main() {
    int N;
    cin >> N;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    int cnt = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (check(v[i], v[j]) == false) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
}