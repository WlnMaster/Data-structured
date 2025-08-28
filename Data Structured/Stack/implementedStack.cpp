#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isPair(char open ,char closed){
    return (open == '('&& closed == ')')||
    (open == '{'&& closed == '}')||
    (open == '['&& closed == ']')||
    (open == '<'&& closed == '>');
}

bool Matched(string data,int& count){
    stack<char>stack;
    for(int i = 0;i < data.size();i++){
        if(data[i] == '(' || data[i] == '{' || data[i] == '[' || data[i] == '<'){
            stack.push(data[i]);
        }else if(data[i] == ')' || data[i] == '}' || data[i] == ']' || data[i] == '>'){
            if(stack.empty())return false;
            if(!isPair(stack.top(),data[i]))return false;
            if(data[i] == '>' && i + 1 < data.size() && data[i+1] == '>'){
                stack.pop();
                i++;
                count--;    
            }
            stack.pop();
            count++;
            
        }
    }
    return stack.empty();
}
int main(){
    string s;
    while(true){
        int count = 0;
        getline(cin , s);
        if(Matched(s,count)){
            cout<<"Matched"<<endl;
            cout<<count<<"Pair"<<endl;
        }else{
            cout<<"Not Matched"<<endl;
            cout<<count<<"Pair"<<endl;
        }
    }
    return 0;
}