#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int> wallet, vector<int> bill) {
	// 지값
	int wallet_max, wallet_min;

	// 지폐
	int bill_max, bill_min;

	// 입력
	int answer = 0;

	
	// 지값
	{
		if (wallet[0] < wallet[1])
		{
			wallet_min = wallet[0];
			wallet_max = wallet[1];
		}
		else
		{
			wallet_min = wallet[1];
			wallet_max = wallet[0];
		}
	}
	// 지폐
	{
		if (bill[0] < bill[1])
		{
			bill_min = bill[0];
			bill_max = bill[1];
		}
		else
		{
			bill_min = bill[1];
			bill_max = bill[0];
		}
	}
	
	// 안되는 조건
	while (bill_min > wallet_min || bill_max > wallet_max)
	{
		answer++;
		bill_max = (int)(bill_max / 2);

		if (bill_min > bill_max)
		{
			int temp;
			temp = bill_min;
			bill_min = bill_max;
			bill_max = temp;
		}
	}

	// 출력
	return answer;
}
