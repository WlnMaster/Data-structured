#include <iostream>
#include <string>
using namespace std;
class Queue{
    public:
    int Array[5];
    int size = 5;
    int head = 0;
    int tail = -1;
    int s(){
        int n = 0;
        for (int i = head;i<=tail;i++){
            n++;
        }
        return n;
    }
    void enqueue(int data){
        if(!isFull()){
            tail++;
            Array[tail % size] = data;
        }else{
            cout <<"Full"<<endl;
        }
    }
    int dequeue(){
        if(!isEmpty()){
            int temp = head;
            head++;
            return Array[temp % size] ;
        }else{
            cout <<"isEmpty"<<endl;
        }
    }
    bool isEmpty(){
        return s() == 0;
    }
    bool isFull(){
        return s() == size;
    }
    void print(){
        for(int i = head;i<=tail ;i++ ){
            cout<<Array[i % size]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    int data;
    string input;
    while(true){
        getline(cin,input);
        if(input == "q"){
            cin>>data;
            q.enqueue(data);
        }
        else if(input == "d"){
            q.dequeue();
        }
        else if(input == "p"){
            
            q.print();
        }
    }
    return 0;
}