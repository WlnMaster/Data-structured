#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int key;
    Node* next;
};

void insert(Node** head_ref, int new_key);
void printList(Node* head);
void insertAt(int pos, Node** head_ref, int new_key);
void remove(Node** head_ref, int key);
void readNnumbers(Node** head_ref);
void processCommand(char cmd, Node** head_ref);

int main() {
    Node* head = NULL;
    readNnumbers(&head);

    char command;
    cin >> command;
    while (command != 'q') {
        processCommand(command, &head);
        cin >> command;
    }
    return 0;
}

void readNnumbers(Node** head_ref) {
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(head_ref, key);
    }
}

void insert(Node** head_ref, int new_key) {
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* head) {
    if (head == NULL) {
        cout << "empty\n";
        return;
    }
    while (head) {
        if (head->next == NULL)
            cout << "[" << head->key << "] " << endl;
        else
            cout << "[" << head->key << "] ";
        head = head->next;
    }
}

void processCommand(char cmd, Node** head_ref) {
    if (cmd == 'i') {
        int pos, k;
        cin >> pos >> k;
        insertAt(pos, head_ref, k);
        printList(*head_ref);
    }
    else if (cmd == 'd') {
        int k;
        cin >> k;
        remove(head_ref, k);
        printList(*head_ref);
    }
}

void insertAt(int pos, Node** head_ref, int new_key) {
    Node* new_node = new Node();
    new_node->key = new_key;
    new_node->next = NULL;

    if (pos <= 1 || *head_ref == NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    Node* temp = *head_ref;
    int count = 1;

    // เดินหาตำแหน่งก่อนหน้าที่จะใส่
    while (temp->next != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void remove(Node** head_ref, int key) {
    if (*head_ref == NULL) {
        cout << "empty" << endl;
        return;
    }

    Node* temp = *head_ref;
    Node* prev = NULL;

    // ถ้าตัวแรกคือ key
    if (temp != NULL && temp->key == key) {
        *head_ref = temp->next;
        delete temp;
        cout << key << " deleted" << endl;
        return;
    }

    // หา key
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << key << " not existed" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << key << " deleted" << endl;
}
