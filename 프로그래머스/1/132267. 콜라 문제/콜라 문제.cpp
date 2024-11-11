#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;

    while ( n >= a )
    {
        // n 은 a로 나뉘어지면서 점점 작아지게됨
        // 그에대한 answer의 결과값은 점점 증가가 되어야한다.
        
        int cola = (n / a) * b;
        answer += cola;
        n = (n % a) + cola;
    } 


    return answer;
}
