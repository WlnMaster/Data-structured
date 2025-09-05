#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = remove(node->left, val);
        else if (val > node->data) node->right = remove(node->right, val);
        else {
            // case 1: no child
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // case 2: one child
            else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // case 3: two children
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << ",";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << ",";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << ",";
    }

public:
    BST() { root = nullptr; }

    void add(int val) { root = insert(root, val); }

    void del(int val) { root = remove(root, val); }

    void bfs() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* cur = q.front(); q.pop();
                cout << cur->data << ",";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << "|";
        }
        cout << endl;
    }

    void printInorder() { inorder(root); cout << endl; }
    void printPreorder() { preorder(root); cout << endl; }
    void printPostorder() { postorder(root); cout << endl; }
};

int main() {
    BST tree;
    string cmd;
    while (true) {
        getline(cin, cmd);
        if (cmd.empty()) continue;

        if (cmd[0] == 'x') break;

        if (cmd[0] == 'a') {
            int val = stoi(cmd.substr(2));
            tree.add(val);
        }
        else if (cmd[0] == 'd') {
            int val = stoi(cmd.substr(2));
            tree.del(val);
        }
        else if (cmd[0] == 'b') {
            tree.bfs();
        }
        else if (cmd[0] == 'i') {
            tree.printInorder();
        }
        else if (cmd[0] == 'p') {
            tree.printPreorder();
        }
        else if (cmd[0] == 't') {
            tree.printPostorder();
        }
    }
    return 0;
}