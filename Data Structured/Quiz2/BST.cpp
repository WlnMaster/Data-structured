#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int Max = 100;
int bst[Max];
bool used[Max];

void insertBST(int val , int i = 0){
    if(i >=Max)return;
    if(!used[i]){
        bst[i] = val;
        used[i] = true;
    }else{
        if(val < bst[i])insertBST(val,2*i+1);
        else if (val > bst[i])insertBST(val,2*i+2);
    }
}
int Fminidx(int i){
    while (!used[2*i+1]){
        i = 2*i+1;
    }
    return i;
}
int removeBST(int val,int i =0){
    if(i >= Max || !used[i]) return -1;
    if(val < bst[i])removeBST(val,2*i+1);
    else if (val > bst[i])removeBST(val,2*i+2);
    else{
        //case no chuikl
        if(!used[2*i+1]&&!used[2*i+2]){
            used[i] = false;
        }
        else if(!used[2*i+2]){
            int right = 2*i+2;
            bst[i] = bst[right];
            used[i] = bst[right];
            removeBST(bst[right],right);
        }
        else if(!used[2*i+1]){
            int left = 2*i+1;
            bst[i] = bst[left];
            used[i] = bst[left];
            removeBST(bst[left],left);
        }
        else{
            int min = Fminidx(2*i+2);
            bst[i] = bst[min];
            removeBST(bst[min],min);
        }
    }
    return 0;
}

void preorder(int i = 0){
    if(i >= Max || !used[i])return;
    cout<<bst[i]<<" ";
    preorder(2*i+1);
    preorder(2*i+2);
}
void inorder(int i = 0){
    if(i >= Max || !used[i])return;
    inorder(2*i+1);
    cout<<bst[i]<<" ";   
    inorder(2*i+2);
}
void postorder(int i = 0){
    if(i >= Max || !used[i])return;    
    postorder(2*i+1); 
    postorder(2*i+2);
    cout<<bst[i]<<" "; 
}
void bfs(){
    queue<int>q;
    if(!used[0])return;
    q.push(0);
    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            int idx = q.front();q.pop();
            cout<<bst[idx]<<",";
            if(used[2*idx+1])q.push(2*idx+1);
            if(used[2*idx+2])q.push(2*idx+2);
        }
        cout<<"|";
    }
    cout<<endl;
}


int main() {
    string cmd;
    while (true) {
        getline(cin, cmd);
        if (cmd.empty()) continue;

        if (cmd[0] == 'x') break;
        if (cmd[0] == 'a') {
            int val = stoi(cmd.substr(2));
            insertBST(val);
        }
        else if (cmd[0] == 'd') {
            int val = stoi(cmd.substr(2));
            removeBST(val);
        }
        else if (cmd[0] == 'b') {
            bfs();
        }
        else if (cmd[0] == 'i') {
            inorder(); cout << endl;
        }
        else if (cmd[0] == 'p') {
            preorder(); cout << endl;
        }
        else if (cmd[0] == 't') {
            postorder(); cout << endl;
        }
    }
    return 0;
}
