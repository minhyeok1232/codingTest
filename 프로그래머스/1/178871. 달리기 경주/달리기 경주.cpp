#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
    map<string, int> m;
    for (int i = 0; i < players.size(); i++)
        m.insert({ players[i], i });
    for (int i = 0; i < callings.size(); i++)
    {
        // a b c d e 
        // 0 1 2 3 4
        // b b d d

        // b a c d e
        string str = callings[i];     // b
        int right = m[str];           // 1
        int left = right - 1;         // 0 
        // players[1] 에 players[0]이 들어가야함

        string temp = players[left];    // a
        players[left] = players[right]; // b
        players[right] = temp;


        m[str] = left;
        m[temp] = right;
    }
    answer = players;

    return answer;
}
