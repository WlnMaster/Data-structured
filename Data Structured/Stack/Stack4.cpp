#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool Matched(string data,int& count){
    vector<char> stack;
    bool bk = false;
    for (int i = 0; i < data.size(); i++)
    {   
        if(data[i] == '<' && data[i+1] == '<' ){
            if(data[i+2] != '>')return false;
            stack.push_back('L');
            bk = true;
            i++;
        }
        else if(data[i] == '>' && data[i+1] == '>' ){
            if(stack.empty() && stack.back() != 'L')return false; 
            stack.pop_back();
            count++;
            i++;
        }
        if(data[i] == '(' || data[i] == '[' || data[i] == '{' || data[i] == '<'  ){
            
            stack.push_back(data[i]);
            bk = true;
        }else if(data[i] == ')' || data[i] == ']' || data[i] == '}' || data[i] == '>'){
            if(stack.empty())return false; 
            stack.pop_back();
            count++;
        }
        // if(data[i] == '<' && data[i+1] == '<' ){
        //     if(data[i+2] != '>')return false;
        //     stack.push_back('L');
        //     bk = true;
        //     i++;
        // }
        // else if(data[i] == '>' && data[i+1] == '>' ){
        //     if(stack.empty() || stack.front() != 'L')return false; 
        //     stack.pop_back();
        //     count++;
        //     i++;
        // }
        // if(data[i] == '(' || data[i] == '[' || data[i] == '{' || data[i] == '<' || data[i+1] == '<' ){
        //     if(data[i+1] == '<' ){
        //         stack.push_back('L');
        //         i++;
        //     }
        //     stack.push_back(data[i]);
        //     bk = true;
        // }else if(data[i] == ')' || data[i] == ']' || data[i] == '}' || data[i] == '>'|| data[i+1] == '>'){
        //     if(data[i+1] == '>' ){
        //         if(stack.empty() || stack.front() != 'L')return false; 
        //         stack.pop_back();
        //         count++;
        //         i++;
        //     }
        //     if(stack.empty())return false; 
        //     stack.pop_back();
        //     count++;
        // }

    }   
    return bk && stack.empty();
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