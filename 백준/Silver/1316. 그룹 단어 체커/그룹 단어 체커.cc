#include <iostream>
#include <map>
using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map<char, bool> m;
        bool GroupWord = true;
        for (int j = 0; j < s.length(); j++) {
            if (m[s[j]]) {  // 방문을 한상태인데 연속돼도 ㄱㅊ
                if(j > 0 && s[j] != s[j - 1]) {
                    GroupWord = false;
                    break;
                }
            }
            m[s[j]] = true; // 방문을 했기에
        }

        if (GroupWord) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}