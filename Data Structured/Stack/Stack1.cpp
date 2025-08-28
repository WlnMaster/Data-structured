#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
        
    }
};
class stack{
    private:
    Node* top ;
    public:
    stack(){
        top = NULL;
    }
    bool isEmpty(){       
        return top == NULL;
    
    }
    void push(int data){
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << data << endl;
        
    }
    int peek(){
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }           
        return top->data;
    }
    void print(){
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }           
            Node* curr = top;
            while (curr != NULL)
            {   
                cout<<curr->data<<endl;
                curr = curr->next;
            }
            
        }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }           
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped: " << poppedValue << endl;
    }
};
int main() {
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.print();

    cout << "Top of stack: " << s.peek() << endl;

    s.pop();
    s.print();

    s.pop();
    s.pop();
    s.pop(); // pop เกินจำนวน

    return 0;
}