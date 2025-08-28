#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Stack {
public:
    int topIndex = 0;
    char st[SIZE];

    bool empty() {
        return topIndex == 0;
    }

    bool full() {
        return topIndex == SIZE;
    }

    void push(char ch) {
        if (!full()) {
            st[topIndex] = ch;
            topIndex++;
        }
    }

    void pop() {
        if (!empty()) {
            topIndex--;
        }
    }

    char top() {
        return st[topIndex - 1];
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}
bool ans(string inp ,int& match){
    Stack st;
    int len = inp.length();
    for (int i = 0; i < len; i++) {
        if (inp[i] == '(' || inp[i] == '[' || inp[i] == '{' || inp[i] == '<') {
            st.push(inp[i]);
        } else if (inp[i] == ')' || inp[i] == ']' || inp[i] == '}' || inp[i] == '>') {
            if (st.empty() || !isMatchingPair(st.top(), inp[i])) {
                return false;
            } else {
                if (inp[i] == '>') {
                    if (i + 1 < len && inp[i + 1] == '>') {
                        i++;
                        st.pop();
                    }
                }
                st.pop();
                match++;
            }
        }
    }
    return st.empty();
} 

int main() {
    Stack st;
    int match = 0;
    string inp;
    getline(cin, inp);
    
    

    

    if (ans(inp,match) && st.empty()) {
        cout << match << " matched";
    } else {
        cout << "Not matched" << endl << match << " pair";
    }
}