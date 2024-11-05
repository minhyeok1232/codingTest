#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
	// 입력
	int N, M;
	int left, right;
	int count = 0;
	vector<int> arr;

	cin >> N >> M;

	// 큐에 저장
	deque<int> dq;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}

	//      1 2 3 4 5 6 7 8 9 10
	// 배열 0 1 2 3 4 5 6 7 8  9
	while (M--)
	{
		int num;
		cin >> num;

		for (int i = 0; i < dq.size(); i++)
		{
			if (dq[i] == num)
			{
				left = i;
				right = dq.size() - i;
				break;
			}
		}

		if (left <= right)
		{
			while (dq.front() != num)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			// 결국 같아지면..
			dq.pop_front();
		}
		else
		{
			count++;

			while (dq.back() != num)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
			// 결국 같아지면..
			dq.pop_back();
		}
	}

	cout << count;
	return 0;

}