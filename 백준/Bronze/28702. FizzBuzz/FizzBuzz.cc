#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    // 이 문제는 힌트가 있다.
    // 3의 배수    -> Fizz
    // 5의 배수    -> Buzz
    // 3, 5의 배수 -> FizzBuzz

    // 문제에서, "연속된 3개의 문자열이 들어간다" 라고 하였기 때문에,
    // 정수가 무조건 하나가 나오게 된다.

    vector<string> s(3);

    int num = -1;

    for (int i = 0; i < s.size(); i++) {
        cin >> s[i];
    }
    // 위에 말했다 시피, 정수가 무조건 하나가 나오기 때문에,
    // 3개의 문자열을 보면서 정수로 변환이 가능한 문자열을 확인한다.
    for (int i = 0; i < s.size(); i++) {
        bool flag = true;
        for (int j = 0; j < s[i].length(); j++) {
            if (!isdigit(s[i][j])) {
                flag = false;
                break;
            }
            flag = true;
        }

        if (flag) {
            num = stoi(s[i]) + 3 - i;
        }
    }

    if (num % 3 == 0 && num % 5 == 0) cout << "FizzBuzz" << '\n';
    else if (num % 3 == 0) cout << "Fizz" << '\n';
    else if (num % 5 == 0) cout << "Buzz" << '\n';
    else cout << num << '\n';
}