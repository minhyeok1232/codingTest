#include <iostream>
using namespace std;
int main()
{
	// Step1) 입력
	long long N;
	int dice[6];
	cin >> N;
	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
	}

	// Step2) 계산
	// 1. ABC / ABD / ACE / ADE / BDF / BCF / DEF / CEF
	//	  ->중에 제일 작은 값
	int _3sidesMinimum = 201;
	_3sidesMinimum = min(dice[0] + dice[1] + dice[2],
		min(dice[0] + dice[1] + dice[3], min(dice[0] + dice[2] + dice[4], min(dice[0] + dice[3] + dice[4], min(dice[1] + dice[3] + dice[5],
			min(dice[1] + dice[2] + dice[5], min(dice[3] + dice[4] + dice[5], dice[2] + dice[4] + dice[5])))))));

	// _3sidesMinimum 은 무조건 4를 곱해줘야함

	// 2. AB / AC / AD / AE / BC / BD / BF / CE / CF / DE / DF / EF 
	//    -> 중에 제일 작은 값
	int _2sidesMinimum = 101;
	int a = min(dice[0] + dice[1], min(dice[0] + dice[2], min(dice[0] + dice[3], dice[0] + dice[4])));
	int b = min(dice[1] + dice[2], min(dice[1] + dice[3], min(dice[1] + dice[5], dice[2] + dice[4])));
	int c = min(dice[2] + dice[5], min(dice[3] + dice[4], min(dice[3] + dice[5], dice[4] + dice[5])));
	_2sidesMinimum = min(a, min(b, c));

	// 3. A / B / C / D / E / F
	//	   -> 중에 제일 작은 값
	int _1sidesMinimum = 51;
	_1sidesMinimum = min(dice[0], min(dice[1], min(dice[2], min(dice[3], min(dice[4], dice[5])))));

	// Step3) 결과
	long long result = 0;
	if (N > 1)
	{
		result = (_3sidesMinimum * 4) + (_2sidesMinimum * 4) + (_1sidesMinimum * (N - 2) * (N - 2) * 5) + (_2sidesMinimum * (N - 2) * 8) + (_1sidesMinimum * (N - 2) * 4);
	}
	else if (N <= 1)
	{
		int _1sidesMaximum = 51;
		_1sidesMaximum = max(dice[0], max(dice[1], max(dice[2], max(dice[3], max(dice[4], dice[5])))));
		result = dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5] - _1sidesMaximum;
	}
	cout << result << endl;
}