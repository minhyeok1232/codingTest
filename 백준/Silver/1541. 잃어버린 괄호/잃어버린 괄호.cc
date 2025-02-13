#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string str;
    string num = "";
    cin >> str;
    bool isMinus = false;
    int result = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == '-' || str[i] == '+' || i == str.length()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += str[i];
        }

        if (str[i] == '-') {
            isMinus = true;
        }
    }

    cout << result << '\n';
}