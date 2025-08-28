#include<iostream>
#include<string>
using namespace std;
class queue{
    public:
    int Array[5];
    int size = 5;
    int front = 2;
    int rear = 1;
    int count = 0; 
    bool isEmpty(){
        return count == 0;
    }
    bool isFull(){
        return count == size;
    }
    void enqueue(int data){
        if(!isFull()){
            rear = (rear +1) % size;
            Array[rear] = data;
            count++;
            cout<<"f:"<<front<<" "<<"r:"<<rear<<endl;
        }else{
            cout<<"Queue Full "<<"f:"<<front<<" "<<"r:"<<rear<<endl;
            return ;
        }
    }
    int dequeue(){
        if(!isEmpty()){
            int temp = Array[front];
            front = (front +1) % size;
            count--;
            cout<<temp<<" "<<"f:"<<front<<" "<<"r:"<<rear<<endl;
            return temp ;
        }else{
            cout<<"Queue Empty "<<"f:"<<front<<" "<<"r:"<<rear<<endl;
            return -1;
        }
    }






};
int main(){
    queue q;
    string cmd;
    int data;
    while(true){
        cin>>cmd;
        if(cmd == "e"){
            cin>>data;
            q.enqueue(data);
        }else if(cmd == "d"){
            q.dequeue();
        }else if(cmd == "x"){
            exit(0);
            break;
        }
    }
    return 0;    
}