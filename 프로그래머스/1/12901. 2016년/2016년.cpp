// 2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요 ?
// 두 수 a, b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, 
// solution을 완성하세요.요일의 이름은 일요일부터 토요일까지 각각 SUN, MON, TUE, WED, THU, FRI, SAT
// 입니다.예를 들어 a = 5, b = 24라면 5월 24일은 화요일이므로 문자열 "TUE"를 반환하세요.

// 제한 조건
// 2016년은 윤년입니다.
//2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일같은 날짜는 주어지지 않습니다)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    string answer = "";

    while (a != 1)
    {
        if (a == 2 || a == 4 || a == 6 || a == 8 || a == 9 || a == 11 ) b += 31;
        if (a == 3) b += 29;
        if (a == 5 || a == 7 || a == 10 || a == 12) b += 30;
        a--;
    }

    if (b % 7 == 1) answer = "FRI";
    else if (b % 7 == 2) answer = "SAT";
    else if (b % 7 == 3) answer = "SUN";
    else if (b % 7 == 4) answer = "MON";
    else if (b % 7 == 5) answer = "TUE";
    else if (b % 7 == 6) answer = "WED";
    else answer = "THU";

    return answer;
}

int main()
{
    int month, day;
    cin >> month >> day;
    string result = solution(month, day);
    cout << result << endl;
}