#include <iostream>
#include <string>
using namespace std;

const int Max_size = 17;

class Node {
public:
    int key;
    string Value;
    Node* Next;
    Node(int k, const string& v) {
        key = k;
        Value = v;
        Next = NULL;
    }
};

class HashTable {
private:
    Node* Table[Max_size];

    int Hash(int key) {
        return key % Max_size;
    }

public:
    // ค่า default เป็น (-1, -)
    HashTable() {
        for (int i = 0; i < Max_size; i++) {
            Table[i] = new Node(-1, "-");
        }
    }

    bool Dup(int key) {
        int idx = Hash(key);
        Node* curr = Table[idx];

        // ถ้า node แรกคือ dummy ให้ข้าม
        if (curr->key == -1 && curr->Next == NULL) return false;

        while (curr != NULL) {
            if (curr->key == key) return true;
            curr = curr->Next;
        }
        return false;
    }

    void add(int key, const string& Value) {
        if (Dup(key)) return;
        int idx = Hash(key);
        Node* newNode = new Node(key, Value);

        // ถ้า node แรกเป็น dummy และไม่มีข้อมูลต่อ ให้แทนที่ด้วยข้อมูลใหม่
        if (Table[idx]->key == -1 && Table[idx]->Next == NULL) {
            delete Table[idx];  // ลบ dummy node เดิมก่อน
            Table[idx] = newNode;
        } else {
            Node* curr = Table[idx];
            while (curr->Next != NULL) {
                curr = curr->Next;
            }
            curr->Next = newNode;
        }
    }

    void print() {
        for (int i = 0; i < Max_size; ++i) {
            Node* curr = Table[i];

            // ว่างจริง = dummy node
            if (curr->key == -1 && curr->Next == NULL) {
                cout <<"(" <<curr->key<<","<<curr->Value<<")"<<endl;;
            } else {
                while (curr != NULL) {
                    cout << "(" << curr->key << "," << curr->Value << ") ";
                    curr = curr->Next;
                }
                cout << "\n";
            }
        }
    }

    void search(int key) {
        int idx = Hash(key);
        Node* curr = Table[idx];

        if (curr->key == -1 && curr->Next == NULL) {
            cout << "-\n";
            return;
        }

        while (curr != NULL) {
            if (curr->key == key) {
                cout << curr->key << " " << curr->Value << endl;
                return;
            }
            curr = curr->Next;
        }
        cout << "-\n";
    }
};

int main() {
    HashTable H;
    H.add(232, "FU");
    H.add(2041, "GU");
    H.add(3010, "JU");
    H.search(2041);
    H.print();
}
