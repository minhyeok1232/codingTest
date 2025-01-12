#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string* s = new string[N];
	string* result = new string[N];
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (s[j] > s[j + 1])
			{
				swap(s[j], s[j + 1]);
			}
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			result[0] = s[0];
		}
		if (i > 0 && s[i] != s[i - 1])
		{
			count++;
			result[count] = s[i];
		}
		arr[count]++;
	}
	int _max = 0;
	int _maxIndex = -1;
	for (int i = 0; i < count + 1; i++)
	{
		if (_max < arr[i])
		{
			_max = arr[i];
			_maxIndex = i;
		}
	}
	
	cout << result[_maxIndex] << endl;
}