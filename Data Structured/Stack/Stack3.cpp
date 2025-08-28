#include<iostream>
#include<string>
#include<vector>
#define Max 5
using namespace std;
class Stack{
    public:
        int data[Max];
        int top;
        Stack(){
            top = 0;
        }
        bool empty(){
            return top == 0;
        }
        bool full(){
            return top == Max;
        }
        void push(int v){
            if(!full()){
                data[top] = v;
                top++;
            }else{
                cout<<"full"<<endl;
                return;
            }
        }
        // 1 2 3 
        //  top
        void pop(){
            if(!empty()){
                top--;
            }else{
                cout<<"empty"<<endl;
                return;
            }
        }
        void peek(){
            if(!empty()){
                cout<<data[top-1];
                cout<<endl;
            }else{
                cout<<"empty"<<endl;
                return;
            }
        }
        void print(){
            for(int i = 0;i <top;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Stack s;
    int d;
    vector<int> a ;
    
    s.push(29);
    s.push(30);
    s.push(31);
    s.print();
    s.pop();
    s.print();
    s.pop();
    
    s.print();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(31);
    s.push(30);
    s.push(29);
    s.print();
    s.peek();
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    for(int i =0;i < a.size();i++){
        cout<< a[i]<<" ";
    }
    cout<< endl;
    a.pop_back();
    for(int i =0;i < a.size();i++){
        cout<< a[i]<<" ";
    }
    cout<< endl;
    cout<<a.back()<<endl;
    return 0;
};