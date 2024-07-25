#include <bits/stdc++.h>
using namespace std;

// Min Heap
class Heap {
    public:
        int arr[100]; // 0-indexed
        int size;

        Heap() {
            // arr[0] = 45;
            // arr[1] = 18;
            // arr[2] = 10;
            // arr[3] = 93;
            size = 0; 
        }

        void print() {
            for(int i = 0;i < size;i++) {
                cout << arr[i] << " " ;
            }
            cout << endl;
        }

        void BottomUpHeapify(int i) {
            while(i >= 0) {
                int parent = (i-1)/2;
                if(arr[parent] > arr[i]) {
                    swap(arr[parent],arr[i]);
                    i = parent;
                }
                else {
                    return;
                }
            }
        }   

        void TopDownHeapify(int i) {
            int c;
            while(2*i+2 < size) {
                if(arr[2*i+1] < arr[2*i+2]) c = 2*i+1;
                else c = 2*i+2;

                if(arr[i] > arr[c]) {
                    swap(arr[i],arr[c]);
                    i = c;
                }
                else {
                    i = size;
                }
            }
            c = 2*i+1;
            if(c < size && arr[i] > arr[c]) {
                swap(arr[i],arr[c]);
            }
        }

        void TopDownMinHeapify(int arr[],int n,int i) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if(left < n && arr[left] < arr[i]) smallest = left;
            if(right < n && arr[right] < arr[smallest]) smallest = right;

            if(smallest != i) {
                swap(arr[i],arr[smallest]);
                TopDownMinHeapify(arr,n,smallest);
            }
        }
        
        void insert(int val) {
            int index = size;
            arr[index] = val;
            size = size + 1;
            BottomUpHeapify(index);
            print();
        }

        void deletefromheap() {
            if(size == 0) return;
            arr[0] = arr[size-1];
            size = size - 1;
            // TopDownHeapify(0);
            TopDownMinHeapify(arr,size,0);
            print();
        }

        void increaseKey(int i,int x) {
            arr[i] = x;
            TopDownHeapify(i);
            print();
        }

        void decreaseKey(int i,int x) {
            arr[i] = x;
            BottomUpHeapify(i);
            print();
        }

        void BuildHeap() {
            for(int i = 0;i < size;i++) {
                BottomUpHeapify(i);
            }
            print();
        }

        void HeapSort() {
            int temp = size;
            for(int i = 0;i < temp;i++) {   
                cout << arr[0] << endl;
                deletefromheap();
            }
        }

};


int main() {
    Heap h;
    h.insert(10);
    h.insert(20);
    // h.increaseKey(1,30);
    // h.decreaseKey(1,8);
    h.deletefromheap();
    h.insert(5);
    h.deletefromheap();
    // h.insert(100);
    // h.insert(7);
    // h.deletefromheap();
    // h.deletefromheap();
    // h.deletefromheap();
    // h.deletefromheap();
    // h.BuildHeap();
    // h.insert(7);
    // h.deletefromheap();
    // h.deletefromheap();
    // h.deletefromheap();
    // h.deletefromheap();
    h.HeapSort();
}