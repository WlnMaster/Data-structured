#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // ตรวจสอบว่ามี ID ซ้ำหรือไม่
    bool exists(int id) {
        Node* temp = head;
        while(temp) {
            if(temp->id == id) return true;
            temp = temp->next;
        }
        return false;
    }

    // แสดง linked list
    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->id << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert Before
    void insertBefore(int newID, int targetID) {
        if(exists(newID)) return; // ห้ามซ้ำ
        Node* newNode = new Node(newID);

        if(!head) { // ถ้า list ว่าง
            head = newNode;
            display();
            return;
        }

        if(head->id == targetID) { // insert ก่อน head
            newNode->next = head;
            head = newNode;
            display();
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while(curr) {
            if(curr->id == targetID) {
                newNode->next = curr;
                prev->next = newNode;
                display();
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        // ถ้าไม่พบ targetID ให้เพิ่มท้าย
        prev->next = newNode;
        display();
    }

    // Insert After
    void insertAfter(int newID, int targetID) {
        if(exists(newID)) return; // ห้ามซ้ำ
        Node* newNode = new Node(newID);

        if(!head) { // ถ้า list ว่าง
            head = newNode;
            display();
            return;
        }

        Node* curr = head;
        while(curr) {
            if(curr->id == targetID) {
                newNode->next = curr->next;
                curr->next = newNode;
                display();
                return;
            }
            curr = curr->next;
        }

        // ถ้าไม่พบ targetID ให้เพิ่มท้าย
        curr = head;
        while(curr->next) curr = curr->next;
        curr->next = newNode;
        display();
    }

    // Delete
    void deleteNode(int targetID) {
        if(!head || (head->next == nullptr && head->id == targetID)) return; // list ว่างหรือมี node เดียว

        if(head->id == targetID) { // ลบ head
            Node* temp = head;
            head = head->next;
            delete temp;
            display();
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while(curr) {
            if(curr->id == targetID) {
                prev->next = curr->next;
                delete curr;
                display();
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        // ถ้าไม่พบ targetID ทำอะไรไม่ต้องทำ
    }
};

int main() {
    LinkedList list;
    char command;
    int id, value;

    while(cin >> command) {
        if(command == 'E') break;
        if(command == 'I') {
            cin >> id >> value;
            list.insertBefore(id, value);
        } else if(command == 'A') {
            cin >> id >> value;
            list.insertAfter(id, value);
        } else if(command == 'D') {
            cin >> id;
            list.deleteNode(id);
        }
    }

    return 0;
}
