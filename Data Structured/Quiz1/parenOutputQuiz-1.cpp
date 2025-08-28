#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOpening(char c) {
    return (c == '(' || c == '[' || c == '{' || c == '<');
}

bool isClosing(char c) {
    return (c == ')' || c == ']' || c == '}' || c == '>');
}

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int main() {
    string input;
    getline(cin, input);

    stack<char> st;
    int matchedCount = 0;
    bool error = false;

    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];

        // ข้าม "<<" และ ">>" (ถือว่าเป็น operator)
        if (c == '<' && i + 1 < input.size() && input[i + 1] == '<') {
            i++;
            continue;
        }
        if (c == '>' && i + 1 < input.size() && input[i + 1] == '>') {
            i++;
            continue;
        }

        if (isOpening(c)) {
            st.push(c);
        } else if (isClosing(c)) {
            if (st.empty() || !isMatch(st.top(), c)) {
                error = true;
                break;
            } else {
                st.pop();
                matchedCount++;
            }
        }
    }

    if (!error && st.empty()) {
        cout << "matched" << endl;
    } else {
        cout << "Not matched" << endl;
        cout << matchedCount << " matched" << endl;
    }

    return 0;
}
