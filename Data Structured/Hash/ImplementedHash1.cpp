#include <iostream>
#include <string>
using namespace std;

const int Max_size = 17;

class Node{
    public:
    int key;
    string value;
    Node* next;
    Node(int k,string v){
        key = k;
        value = v;
        next = NULL;
    }
    
};
class HashTable{
    private:
    Node* table[Max_size];
    int Hash(int key){
        return key % Max_size;
    }
    public:
    HashTable(){
        for (int  i = 0; i < Max_size; i++)
        {
            table[i] = NULL;
        }
        
    }
    void add(int key ,string value){
        int idx = Hash(key);
        Node* newNode = new Node(key,value);
        if(table[idx] == NULL){
            table[idx] = newNode;
        }else{
            Node* curr = table[idx];
            while(curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }
    void print(){ 
        for(int i = 0;i< Max_size;i++){
            if(table[i] == NULL){
                puts("(-1,-)");
            }else{
                Node* curr = table[i];
                while (curr != NULL)
                    {
                        cout << "(" << curr->key << "," << curr->value << ")";
                        curr = curr->next;
                    }
                cout << endl;
            
            }
            
        }
    }
    void search(int key){
        int idx = Hash(key);
        Node* curr = table[idx];
        while(curr != NULL){
            if(curr->key == key){
                cout << curr->key << " " << curr->value << endl;
            }
            curr = curr->next;
        }
    }
};
int main(){
    HashTable H;
    H.add(232,"FU");
    H.add(2041,"GU");
    H.add(3010,"JU");
    H.search(3010);
    H.print();
}