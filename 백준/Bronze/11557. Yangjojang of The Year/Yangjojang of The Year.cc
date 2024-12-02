#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        map<int, string> m;
        for (int j = 0; j < N; j++) {
            string university;
            int num;
            cin >> university;
            cin >> num;
            m.insert(pair<int, string>(num, university));
        }
        int max_num = 0;
        string max_university;
        for (auto& a : m) {
            if (a.first > max_num) {
                max_num = a.first;
            }
        }
        max_university = m[max_num];
        cout << max_university << endl;
    }
    return 0;
}