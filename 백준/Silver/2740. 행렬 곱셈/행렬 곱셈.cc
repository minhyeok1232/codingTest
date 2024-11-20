#include <iostream>
using namespace std;

int arr_a[101][101];
int arr_b[101][101];
int arr_result[101][101];
int main()
{
    int N, M, K;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr_a[i][j];

    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> arr_b[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                arr_result[i][j] += arr_a[i][k] * arr_b[k][j];
            }
            cout << arr_result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
