#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPair(char open ,char closed){
    return (open == '('&& closed == ')')||
           (open == '{'&& closed == '}')||
           (open == '['&& closed == ']')||
           (open == '<'&& closed == '>');
}

bool Matched(string data,int& count){
    stack<char> st;
    for(int i = 0; i < data.size(); i++){
        if(data[i] == '(' || data[i] == '{' || data[i] == '[' || data[i] == '<'){
            st.push(data[i]);
        }
        else if(data[i] == ')' || data[i] == '}' || data[i] == ']' || data[i] == '>'){
            if(st.empty()) return false;  // ป้องกัน top() ตอนว่าง
            if(!isPair(st.top(), data[i])) return false;

            // เช็คกรณี >>
            if(data[i] == '>' && i + 1 < data.size() && data[i+1] == '>'){
                i++; // ข้ามอีกตัว
            }
            st.pop();
            count++;
        }
    }
    return st.empty();
}

int main(){
    string s;
    while(true){
        int count = 0;
        getline(cin , s);
        if(Matched(s,count)){
            cout<<"Matched"<<endl;
            cout<<count<<" pair(s)"<<endl;
        }else{
            cout<<"Not Matched"<<endl;
            cout<<count<<" pair(s)"<<endl;
        }
    }
    return 0;
}
