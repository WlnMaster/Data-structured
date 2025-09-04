#include <iostream>
#include <queue>
#include <string>


using namespace std;

const int MAX = 100; // ขนาดสูงสุดของ BST
int bst[MAX];        // เก็บค่าใน BST
bool used[MAX];      // เช็คว่าตำแหน่งนี้มีค่าอยู่ไหม

void insertBST(int val, int i = 0) {
    if (i >= MAX) return;
    if (!used[i]) { // ถ้ายังว่าง
        bst[i] = val;
        used[i] = true;
    }
    else {
        if (val < bst[i]) insertBST(val, 2*i+1);
        else if (val > bst[i]) insertBST(val, 2*i+2);
        
    }
}

int findMinIndex(int i) {
    while (used[2*i+1]) i = 2*i+1;
    return i;
}

int removeBST(int val, int i = 0) {
    if (i >= MAX || !used[i]) return -1;
    if (val < bst[i]) removeBST(val, 2*i+1);
    else if (val > bst[i]) removeBST(val, 2*i+2);
    else {
        // case 1: no child
        if (!used[2*i+1] && !used[2*i+2]) {
            used[i] = false;
        }
        // case 2: one child
        else if (!used[2*i+1]) {
            int right = 2*i+2;
            bst[i] = bst[right];
            used[i] = used[right];
            removeBST(bst[right], right);
        }
        else if (!used[2*i+2]) {
            int left = 2*i+1;
            bst[i] = bst[left];
            used[i] = used[left];
            removeBST(bst[left], left);
        }
        // case 3: two children
        else {
            int minIdx = findMinIndex(2*i+2);
            bst[i] = bst[minIdx];
            removeBST(bst[minIdx], minIdx);
        }
    }
    return 0;
}

void inorder(int i = 0) {
    if (i >= MAX || !used[i]) return;
    inorder(2*i+1);
    cout << bst[i] << ",";
    inorder(2*i+2);
}

void preorder(int i = 0) {
    if (i >= MAX || !used[i]) return;
    cout << bst[i] << ",";
    preorder(2*i+1);
    preorder(2*i+2);
}

void postorder(int i = 0) {
    if (i >= MAX || !used[i]) return;
    postorder(2*i+1);
    postorder(2*i+2);
    cout << bst[i] << ",";
}

void bfs() {
    queue<int> q;
    if (!used[0]) return;
    q.push(0);
    while (!q.empty()) {
        int size = q.size();
        for (int k = 0; k < size; k++) {
            int idx = q.front(); q.pop();
            cout << bst[idx] << ",";
            if (used[2*idx+1]) q.push(2*idx+1);
            if (used[2*idx+2]) q.push(2*idx+2);
        }
        cout << "|";
    }
    cout << endl;
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
