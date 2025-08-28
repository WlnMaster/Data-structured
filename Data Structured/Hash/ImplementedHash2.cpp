#include<iostream>
#include<string>
const int Max = 17;
using namespace std;
class Node{
    public:
    int key;
    string data;
    Node* next;
    Node(int k,string v){
        key = k;
        data = v;
        next = NULL;
    } 
};
class Hashtable{
    private:
    Node* table[Max];
    int hash(int key){
        return key % Max;
    }
    public:
    Hashtable(){
        for(int i = 0 ;i < Max;i++){
            table[i] = NULL;
        }
    }
    bool Dup(int key){
        int idx = hash(key);
        Node* curr = table[idx];
        if(curr->key == key&&curr->next==NULL) return false;
        while (curr != NULL)
        {
            if(curr->key == key){
                return true;     
            }
            curr = curr->next;       
        }        
        return false;
    }
        
    void print(){
        for(int i = 0 ;i < Max;i++){
            Node* curr = table[i];
            if(curr == NULL){
                cout << "(-1,-)";
                cout<<endl;
            }else{
                while(curr != NULL){
                    cout<< "("<<curr->key<<","<<curr->data<<")";
                    curr = curr->next;
                }
                cout<<endl;
            }
            
            
        }
        
    }
    void add(int key,string data){
        if (Dup(key)) return;
        int idx = hash(key);
        Node* newNode = new Node(key,data);
        if(table[idx] == NULL){           
            table[idx] = newNode;
        }else{
            Node* curr = table[idx];
            while(curr->next !=NULL){    
                curr = curr->next;   
                
            }
            curr->next = newNode;
        }
    }
    void sreach(int key){
        int idx = hash(key);
        Node* curr = table[idx];
        if(curr->key == key&&curr->next==NULL){
            cout<< "("<<curr->key<<","<<curr->key<<")";
        }else{
            while (curr != NULL)
            {
                if(curr->key == key){
                    cout<< "("<<curr->key<<","<<curr->data<<")"<<endl;
                    return;
                }
                curr = curr->next;
            }        
            
        }
        
    }

};
int main(){
    Hashtable h;
    int key ;
    string cmd,data;
    while(1){
        cin>>cmd;
        
        
        if(cmd == "a"){
            cin>>key;
            cin>>data;
            h.add(key,data);
        }
        else if(cmd == "s"){
            cin>>key;
            h.sreach(key);    
        }
        else if(cmd == "p"){
            h.print();
        }
        else if(cmd == "e"){
            break;
        }
    }

};