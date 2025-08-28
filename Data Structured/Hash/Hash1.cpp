#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

const int TABLE_SIZE = 17;

class HashTable {
    private:
        vector<list<pair<int, string>>> table;

        int hash(int key) {
            return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void add(int key, const string& value) {
        int idx = hash(key);
      
        for (auto& p : table[idx]) {
            if (p.first == key)
                return;
        }
        table[idx].emplace_back(key, value);
    }

    void show() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i].empty()) {
                cout << "(-1,-)\n";
            } else {
                for (auto& p : table[i]) {
                    cout << "(" << p.first << "," << p.second << ") ";
                }
                cout << "\n";
            }
        }
    }

    void search(int key) {
        int idx = hash(key);
        for (auto& p : table[idx]) {
            if (p.first == key) {
                cout << p.second << "\n";
                return;
            }
        }
        cout << "-\n";
    }
};

int main() {
    HashTable ht;
    string cmd;
    int key;
    string value;

    while (cin >> cmd) {
        if (cmd == "a") {
            cin >> key >> value;
            ht.add(key, value);
        } else if (cmd == "p") {
            ht.show();
        } else if (cmd == "s") {
            cin >> key;
            ht.search(key);
        } else if (cmd == "e") {
            break;
        }
    }

    return 0;
}
