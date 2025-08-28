#include <iostream>
#include <cstdlib>

using namespace std;

const int SIZE = 5;

class CircularQueue {
private:
    int data[SIZE];
    int front;
    int rear;
    int count; // To keep track of number of elements

public:
    // Constructor - Initialize the queue
    CircularQueue() {
        front = 2;
        rear = 1;
        count = 0;
    }
    
    // Check if queue is fulld
    bool isFull() {
        return count == SIZE;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }
    
    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Full f:" << front << " r:" << rear << endl;
            return;
        }
        
        // Move rear to next position (circular)
        rear = (rear + 1) % SIZE;
        data[rear] = value;
        count++;
        
        cout << "f:" << front << " r:" << rear << endl;
    }
    
    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty f:" << front << " r:" << rear << endl;
            return;
        }
        
        int value = data[front];
        count--;
        front = (front + 1) % SIZE;
        cout << value << " f:" << (front + 1) % SIZE << " r:" << rear << endl;
        
        // Move front to next position (circular)
    }
};

int main() {
    CircularQueue queue;
    
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