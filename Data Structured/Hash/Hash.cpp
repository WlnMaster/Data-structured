#include <iostream>
#include <string>
using namespace std;

const int Max = 17;

class Node {
public:
    int key;
    string data;
    Node* next;
    Node() {
        key = -1;
        data = "-";
        next = NULL;
    }
    Node(int k, string d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class hashtable {
private:
    Node* table[Max];
    int hash(int key) {
        return key % Max;
    }
public:
    hashtable() {
        for (int i = 0; i < Max; i++) {
            table[i] = new Node();
        }
    }

    bool Dup(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        while (curr != NULL) {
            if (curr->key == key) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void add(int key, string data) {
        if (Dup(key)) return; // ถ้าซ้ำไม่ทำอะไร
        Node* newNode = new Node(key, data);
        int idx = hash(key);
        if (table[idx]->key == -1) {
            table[idx] = newNode;
        } else {
            Node* curr = table[idx];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void search(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        while (curr != NULL) {
            if (curr->key == key) {
                cout << curr->data << "\n";
                return;
            }
            curr = curr->next;
        }
        cout << "-\n";
    }

    void print() {
        for (int i = 0; i < Max; i++) {
            Node* curr = table[i];
            if (curr->key == -1) {
                cout << "(-1,-)\n";
            } else {
                while (curr != NULL) {
                    cout << "(" << curr->key << "," << curr->data << ")";
                    if (curr->next != NULL) cout << " ";
                    curr = curr->next;
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    hashtable h;
    int key;
    string cmd, data;
    while (1) {
        cin >> cmd;
        if (cmd == "a") {
            cin >> key >> data;
            h.add(key, data);
        } else if (cmd == "s") {
            cin >> key;
            h.search(key);
        } else if (cmd == "p") {
            h.print();
        } else if (cmd == "e") {
            break;
        }
    }
    return 0;
}
