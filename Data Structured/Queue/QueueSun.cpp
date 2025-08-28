#include <iostream>
#include <string>
using namespace std;

class Queue{
	public:
		int Array[5];
		int size = 5;
		int head = 2;
		int tail = 1;
		int count =0;
		
		bool full(){
			// can use int count to initial value in this so it would be O(1)
			return count == size;
		}
		
		bool empty(){
			return count == 0;
		}
		
		void enqueue(int data)
		{
			if(!full()){
				tail = (tail+1)%size;
				Array[tail] = data;
				count++;
				cout<<"f:"<<head<<" "<<"r:"<<tail<<endl;
			}
			else{
				cout<<"FULL!!! "<<"f:"<<head<<" "<<"r:"<<tail<<endl;
			}
			
		}
		
		int dequeue()
		{
			if(!empty()){
				int temp = Array[head];
        		count--;
        		head = (head + 1) % size;
        		cout << temp << " f:" << head << " r:" << tail << endl;
			}
			else{
				cout << "Queue Empty f:" << head << " r:" << tail << endl;
			}
			
			
		}
		
		void print()
		{
			int n = 0;
			for(int i = head;i <= tail;i++)
			{
				cout<<Array[i%size]<<" ";
			}
			cout<<endl;
		}		
		void showData()
		{
			cout<<Array[head%size]<< " " << Array[tail%size] << endl;
		}
};

int main() {
    Queue queue;
    
    char command;
    int value;
    
    while (true) {
        cin >> command;
        
        switch (command) {
            case 'e':
                cin >> value;
                queue.enqueue(value);
                break;
                
            case 'd':
                queue.dequeue();
                break;
                
            case 'x':
                exit(0);
                break;
                
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }
    
    return 0;
}