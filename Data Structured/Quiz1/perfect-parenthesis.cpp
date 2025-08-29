#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isPair(char open ,char closed){
    return (open == '(' && closed == ')')||
    (open == '[' && closed == ']')||
    (open == '{' && closed == '}')||
    (open == '<' && closed == '>');
}
bool Matched(string data,int& count){
    stack<char>stack;
    for (int  i = 0; i < data.size(); i++)
    {   
        if(i + 1  < data.size() && data[i] == '<' && data[i + 1]=='<'){
            i++;
        }else if(i + 1  < data.size() && data[i] == '>' && data[i + 1]=='>'){
            i++;
        }
        else if(data[i] == '('||data[i] == '{'||data[i] == '['||data[i] == '<'){
            stack.push(data[i]);
        }else if(data[i] == ')'||data[i] == '}'||data[i] == ']'||data[i] == '>'){
            if(stack.empty()) return false;            
            if(!isPair(stack.top(),data[i]))return false;
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
            cout<<count<<" "<<"matched"<<endl;
        }else{
            puts("Not matched");
            cout<<count<<" "<<"matched"<<endl;
        }
    }
    return 0;
}
// (((20+5)+61 
// (20+[30 – 40<int> + 50]- a[40]{}) 
// >20(30{40[20]})< 
// <<a+<int>b+c[40-{50+60(20)}]-<int>+b>> 
// a+b-<<c+d<< -f ({d[30]})>> 
