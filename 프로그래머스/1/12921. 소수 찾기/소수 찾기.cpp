#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> v(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            for (int j = 2; j * i <= n; j++)
            {
                v[i * j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    int k;
    cin >> k;
    int result = solution(k);
    cout << result;
}