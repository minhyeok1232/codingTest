#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;                                                 // 정답을 담아줄 배열

    for (int i = 0; i < commands.size(); i++)                           // vector<   T   > commands
    {
        queue<int> q;                                                   // 임시 Queue하나 생성
        int start = commands[i][0] - 1;                                 // commands[i][0]이 2라면, 2번째부터 시작하라는 뜻
        int end   = commands[i][1] - 1;                                 // commands[i][1]이 5라면, 5번째까지 라는 뜻
        int k     = commands[i][2] - 1;                                 // 애초에, 원소는 0번째부터 시작하기에 1씩 빼줌

        for (int j = start; j <= end; j++)                              // 지금 vector<   T   > commands 큰틀하고있음!
        {
            q.push(array[j]);                                           // 새로만든 Queue에 문제에서 주어진 array배열을 추가
        }

        vector<int> tmp;                                                // Sort과정이 필요한데, Queue를 int형 벡터리스트에 추가하기 위해 임시로 생성
        while(!q.empty())                                               // Queue가 빌 때 까지
        {
            tmp.push_back(q.front());                                   // 처음 tmp는 비어있고, Queue의 맨앞원소를 
            q.pop();                                                    // 가져다가 쓰는 느낌 (Queue원소는 하나씩 사라지게 됨)
        }

        sort(tmp.begin(), tmp.end());                                   // 이렇게 만들어진 배열을 Algorithm 라이브러리를 통해 sort로 정렬

        answer.push_back(tmp[k]);                                       // 정리하자면, tmp배열은 int형으로 몇번째부터 몇번째까지 뽑아서 정렬한 상태
    }                                                                   // 여기서 commands[i][2]-1 (k)번째로 작은 수를 뽑기위해 answer배열에다가 추가
        
    return answer;
}

int main()
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

    vector<int> result = solution(array, commands);
    for (auto a : result)
    {
        cout << a << " ";
    }

    return 0;
}