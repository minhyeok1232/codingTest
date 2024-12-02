#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int N;
    vector <long> v;
    cin >> N;
    map<long, int> m;
    for (int i = 0; i < N; i++) {
        long k;
        cin >> k;   // map의 first
        m[k]++;
    }

    long max_count = 0;
    for (auto & a : m) {
        if ( a.second > max_count ) {
            max_count = a.second;
        }
    }
    for (auto & a : m) {
        if (a.second == max_count) {
            v.push_back(a.first);
        }
    }

    long min_num = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < min_num) {
            min_num = v[i];
        }
    }

    cout << min_num << endl;
    return 0;
}