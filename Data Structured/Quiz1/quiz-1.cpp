#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isPair(char open,char closed){
    return (open == '(' && closed == ')')||
    (open == '{' && closed == '}')||
    (open == '[' && closed == ']')||
    (open == '<' && closed == '>');
}
bool Matched(string data,int& count){
    
    stack<char>stack;
    for(int i = 0;i < data.size();i++){
        if(data[i] == '('||data[i] == '{'||data[i] == '['||data[i] == '<'){
            stack.push(data[i]);
        }else if(data[i] == ')'||data[i] == '}'||data[i] == ']'||data[i] == '>'){
            if(stack.empty()) return false;
            if(!isPair(stack.top(),data[i])) return false;
            if(i + 1 < data.size()&&data[i] == '>'&&data[i+1]=='>'){
                i++;
                stack.pop();
                count--;
            }
            stack.pop();
            count++;
        }
    }

    return stack.empty();
}
int main(){
    string data;
    
    while(true){
        int count = 0;
        getline(cin,data);
        if(Matched(data,count)){
            cout<<count<<" matched"<<endl;
        }else{
            cout<<"Not matched"<<endl;
            cout<<count<<" matched"<<endl;
        }
    }
    return 0;
}