#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

void DFS(int left, int right) {
	if (left >= right) return; 
	if (left == right - 1) {  
		cout << v[left] << '\n';
		return;
	}

	int tmp = left + 1;
	while (tmp < right) {
		if (v[left] < v[tmp]) break;
		tmp++;
	}
	DFS(left + 1, tmp);	// 왼쪽 서브트리
	DFS(tmp, right);	// 오른쪽 서브트리
	cout << v[left] << '\n'; // 현재 루트 출력
}

int main() {
	while (cin >> N) v.push_back(N);
	DFS(0, v.size());
}