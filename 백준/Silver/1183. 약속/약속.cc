#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// 1. 입력
	int N;
	cin >> N;

	vector<int> T;

	for (int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		T.push_back(A - B);
	}

	sort(T.begin(), T.end());

	if (N % 2 == 1) cout << 1;
	else
	{
		cout << T[N / 2] - T[N / 2 - 1] + 1;
	}

}