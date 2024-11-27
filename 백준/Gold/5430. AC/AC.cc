#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; 
    cin >> T;

    while (T--) {
        string str, str_input;
        int num;
        deque<int> dq;

        cin >> str;      // RDD
        cin >> num;      // 4
        cin >> str_input; // [1,2,3,4]

        // 배열 처리: '['와 ']'를 제외한 숫자들 처리
        string current = "";
        bool Queue_Error = false;
        for (int j = 1; j < str_input.length(); j++) {
            if (str_input[j] == ',' || str_input[j] == ']') {
                if (!current.empty()) {
                    dq.push_back(stoi(current));  // 숫자를 덱에 추가
                    current = "";  // current 초기화
                }
            } else {
                current += str_input[j];  // 숫자 쌓기
            }
        }

        bool is_reversed = false;  // 뒤집기 상태

        // 명령어 처리
        for (char command : str) {
            if (command == 'R') {
                is_reversed = !is_reversed;  
            } else if (command == 'D') {
                if (dq.empty()) {  // 덱이 비어있으면 에러
                    Queue_Error = true;
                    break;
                }
                if (is_reversed) {
                    dq.pop_back();  // 뒤집혔으면 뒤에서부터 제거
                } else {
                    dq.pop_front();  // 그렇지 않으면 앞에서부터 제거
                }
            }
        }

        // 결과 출력
        if (Queue_Error) {
            cout << "error" << endl;
        } else {
            // 덱을 출력할 때는 뒤집힌 상태를 고려하여 출력
            string output = "[";
            if (is_reversed) {
                // 뒤집힌 상태에서 출력
                while (!dq.empty()) {
                    output += to_string(dq.back());
                    dq.pop_back();
                    if (!dq.empty()) output += ",";
                }
            } else {
                // 정상 상태에서 출력
                while (!dq.empty()) {
                    output += to_string(dq.front());
                    dq.pop_front();
                    if (!dq.empty()) output += ",";
                }
            }
            output += "]";
            cout << output << endl;
        }
    }

    return 0;
}