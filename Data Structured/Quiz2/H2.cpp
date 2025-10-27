#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MaxHeap{
    vector <int> Heap;
    void HeapUp(int idx){
        while(idx > 0){
            int parant = (idx - 1)/2;
            if(Heap[parant] > Heap[idx]){
                swap(Heap[parant],Heap[idx]);
                idx = parant;
            }else{
                break;
            }
        }
    }
    void HeapDown(int idx){
        while(true){
            int left = (2 * idx) +1; 
            int right = (2 * idx) +2; 
            int L = idx;

            if(left < Heap.size() && Heap[left] < Heap[L]){
                L = left;
            }
            if(right < Heap.size() && Heap[right] < Heap[L]){
                L = right;
            }
            if(L != idx){
                swap(Heap[idx],Heap[L]);
                idx = L;
            }else{
                break;
            }
        }    
    }
public:
    void add(int val){
        Heap.push_back(val);
        HeapUp(Heap.size() - 1);
    }
    void remove(){
        if(Heap.empty()) return;
        cout<<Heap[0]<<endl;
        Heap[0] = Heap.back();
        Heap.pop_back();
        if(!Heap.empty()){
            HeapDown(0);
        }
    }
    void print(){
        for (int i = 0;i < Heap.size();i++){
            cout<<Heap[i]<<" ";
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
