#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int count0 = 0; // "0 구간"의 개수
    int count1 = 0; // "1 구간"의 개수

    // 첫 문자 기준으로 초기화
    if (s[0] == '0') 
        count0++;
    else 
        count1++;

    // 구간 세기
    for (int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) { // 구간이 바뀔 때
            if (s[i] == '0')
                count0++;
            else
                count1++;
        }
    }

    // 더 적은 구간을 뒤집음
    cout << min(count0, count1) << '\n';

    return 0;
}