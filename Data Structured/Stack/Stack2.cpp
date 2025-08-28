#include<iostream>
#include<string>

using namespace std;

class Node {
    public:
    char data;
    Node* next;
    Node(char d){
        data = d;
        next = NULL;
    }




};
class stack{
    private:
    Node* top;
    public:
    stack(){
        top = NULL;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void push(char data){
        
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    void print(){
        Node* curr = top;
        if(isEmpty()){
            cout<<"empty"<<endl;
        }
        while(curr != NULL){
            cout<<curr->data<<endl;
            curr = curr->next;
        }
        
    }
    void pop(){
        if(isEmpty()){
            cout<<"empty"<<endl;
            return;
        }
        
        Node* temp = top;
        top = top->next;
        delete temp;

    }
    char peek(){
        if(isEmpty()){
            cout<<"empty"<<endl;
            return '\0';
        }
        cout<<top->data<<endl;
    }
    bool Matched(string exp,int& matchCount){
    stack s;
    bool foundBracket = false; // เพิ่มตัวแปรตรวจว่ามีวงเล็บมั้ย

    for(char data : exp){
        if(data == '(' || data == '[' || data == '{'|| data == '<'){
            s.push(data);
            foundBracket = true;
        } else if(data == ')' || data == ']' || data == '}'|| data == '>'){
            foundBracket = true;
            if(s.isEmpty()) return false;
            s.pop();
            matchCount++;
        }
    }
    return foundBracket && s.isEmpty();
    }

};

int main() {
    stack s;
    string exp;
    while(1){
        getline(cin,exp);
        int matchcount = 0;
        if(s.Matched(exp,matchcount)){
            puts("Match");
            cout << "Match (" << matchcount << " pairs)" << endl;
        }else{
            puts("Not match");
        }
        
    }
}
    

