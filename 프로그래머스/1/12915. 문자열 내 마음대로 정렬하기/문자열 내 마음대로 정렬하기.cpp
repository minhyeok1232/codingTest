#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;

bool Compare(string A, string B)
{
    if (A[N] == B[N]) return A < B;
    else return A[N] < B[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(), strings.end(), Compare);

    for (auto& a : strings)
        answer.push_back(a);
    return answer;
}