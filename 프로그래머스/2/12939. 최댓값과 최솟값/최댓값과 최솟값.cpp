#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = ""; // 정답
    vector<int> v;      // 숫자를 저장할 벡터
    string tmp;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')    // 비어있지않으면 -> 문자열을 계속 추가해야겠지?
        {
            tmp += s[i];    // 만약, 12 34 56 일시, tmp는 1이되었다가 12로 갱신이 됨
        }
        else
        {                   // 근데 비어있다? 그러면 12를 v벡터에 옮겨야지
            v.push_back(stoi(tmp));
            tmp.clear();    // 임시문자열을 초기화 작업
        }
    }
    // 근데 마지막문자열에가도 해당숫자를 v벡터에 옮겨야하기 때문에
    v.push_back(stoi(tmp)); // 한번 더 진행

    // algorithm의 sort배열을 하기 위함으로 v벡터는 int형으로.
    sort(v.begin(), v.end());

    // v벡터는 int형
    // answer벡터는 string형
    answer = answer + to_string(v.front()) + " " + to_string(v.back());

    return answer;
}
