#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool Compare(string a, string b) {
    if (a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main() {
    int N;
    cin >> N;
    map<string, bool> m;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s] = true;
        if (!m[s])
            m.erase(s);
    }

    for (auto& x : m) {
        v.push_back(x.first);
    }

    sort(v.begin(), v.end(), Compare);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}