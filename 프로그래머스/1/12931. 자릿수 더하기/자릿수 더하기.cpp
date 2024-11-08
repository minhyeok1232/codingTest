#include <iostream>


using namespace std;
int solution(int n)
{
    int answer = 0;
    while (n != 0)
    {   // 987 이면.. k 는 7이됨..
        int k;
        k = n % 10;
        answer += k;
        n = n / 10;
    }

    return answer;
}
