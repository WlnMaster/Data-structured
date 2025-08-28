#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }

public:
    void add(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void remove() {
        if (heap.empty()) return;
        cout << heap[0] << endl; // พิมพ์ค่าที่ถูกลบ
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    void print() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i != heap.size() - 1) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    char cmd;
    while (cin >> cmd) {
        if (cmd == 'a') {
            int x; cin >> x;
            h.add(x);
        }
        else if (cmd == 'd') {
            h.remove();
        }
        else if (cmd == 'p') {
            h.print();
        }
        else if (cmd == 'e') {
            break;
        }
    }
    return 0;
}
