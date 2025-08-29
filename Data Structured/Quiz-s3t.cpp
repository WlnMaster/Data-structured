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
void insertAt(int post, Node** head_ref, int new_key); 
void remove(Node** head_ref, int key); 
void readNnumbers(Node** head_ref); 
void readNnumbers(Node** head_ref); 
void processCommand(char cmd, Node** head_ref); 
 
int main() { 
 Node* head = NULL; 
 readNnumbers(&head); 
  
 char command; 
 cin >> command; 
 while (command != 'q'){ 
  processCommand(command, &head); 
  cin >> command; 
 }  
 return 0; 
} 
 
void readNnumbers(Node** head_ref) 
{ 
int n, key; 
 cin >> n; 
 for (int i=0; i<n; i++){ 
  cin >> key; 
  insert(head_ref, key); 
 } 
} 
 
void insert(Node** head_ref, int new_key) 
{ 
    /* allocate node */ 
    Node* new_node = new Node(); 
    
    /* put in the key */ 
    new_node->key = new_key; 
    
    /* link the old list of the new node */ 
    new_node->next = (*head_ref); 
    
    /* move the head to point to the new node */ 
    (*head_ref) = new_node; 
} 
 
void printList(Node* head) 
{ 
 if (head == NULL) cout << "empty\n"; 
  
     while (head) { 
         if (head->next == NULL) 
              cout << "[" << head->key << "] " << endl; 
         else 
              cout << "[" << head->key << "] "; 
         head = head->next; 
     } 
} 
 
void processCommand(char cmd, Node** head_ref){ 
 if (cmd == 'i'){ 
  // *** Your code here! 
   
 } 
 else if (cmd == 'd'){ 
  // *** Your code here! 
 } 
} 
void insertAt(int post, Node** head_ref, int new_key) 
{ 
// *** Your code here! 
} 
void remove(Node** head_ref, int key) 
{ 
// *** Your code here! 
} 
