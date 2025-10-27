#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MaxHeap{
    vector<int> heap;
    void HeapUp(int idx){
        while (idx > 0)
        {
            int parant = (idx-1)/2;
            if(heap[parant] < heap[idx]){
                swap(heap[parant],heap[idx]);
                idx = parant;
            }else{
                break;
            }
        }
        
    }
    void HeapDown(int idx){
        int n = heap.size();
        while(true){
            int left = (idx * 2 ) + 1;
            int right = (idx * 2 ) + 2;
            int L = idx;

            if(L < n && heap[left] > heap[L]){
                L = left;
            }
            if(L < n && heap[right] > heap[L]){
                L = right;
            }
            if(L != idx){
                swap(heap[idx],heap[L]);
                idx = L;
            }else{
                break;
            }
        }
        
    }
public:
    void add(int val){
        heap.push_back(val);
        HeapUp(heap.size() - 1 );
    }
    void remove(){
        if(heap.empty())return;
        cout<<heap[0]<<endl;
        heap[0] = heap.back();
        heap.pop_back();
        if(!heap.empty()){
            HeapDown(0);
        }
    }
    void print(){
        for (int i = 0; i < heap.size() ; i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
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
