#include <iostream>
#include <string>
using namespace std;
class Queue{
    public:
    int Array[5];
    int size =5;
    int head = 1;
    int tail = 0;
    int count = 0;
    // tail = (tail +1  % size;
    
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == size;
    }
    void enqueue(int data){
        if(!isFull()){
            tail++;
            Array[tail%size] = data;
            count++;
        }else{
            puts("Full\n");
        }  
    }
    int dequeue(){
        if(!isEmpty()){
            int temp = Array[head];
            head++;
            // head = (head + 1)%size;
            return temp;
        }else{
            puts("Empty\n");
        }  
    }
    void print(){
        
        for(int i = head;i <= tail;i++){
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int data;
    string cmd;
    while(true){
        cin>>cmd;
        if(cmd == "q"){
            cin>>data;
            q.enqueue(data);
        }else if(cmd == "d"){
            q.dequeue();
        }else if(cmd == "p"){
            q.print();
        }
    }

    return 0;

}