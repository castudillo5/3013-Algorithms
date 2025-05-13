#include <iostream>
using namespace std;

class Heap {
    int *heap;
    int size;
    
    void bubble_up(int i) {
        while (i > 1 && heap[i] < heap[i / 2]) { // Min heap property
            swap(i, i / 2);
            i /= 2;
        }
    }
    
    void bubble_down(int i) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(i, smallest);
            bubble_down(smallest);
        }
    }
    
    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    
public:
    Heap() {
        heap = new int[100];
        size = 1; // heap[0] is unused
    }
    
    void push(int x) {
        heap[size] = x;
        bubble_up(size);
        size++;
    }
    
    int pop() {
        if (size <= 1) {
            throw out_of_range("Heap is empty");
        }
        int minValue = heap[1];
        heap[1] = heap[size - 1];
        size--;
        bubble_down(1);
        return minValue;
    }
    
    void print() {
        for (int i = 1; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    ~Heap() {
        delete[] heap;
    }
};

int main() {
    Heap heap;
    
    for (int i = 0; i < 10; i++) {
        heap.push(rand() % 100 + 1);
    }
    
    heap.push(13);
    heap.push(11);
    heap.push(7);
    heap.push(3);
    heap.print();
    
    cout << "Removing top element: " << heap.pop() << endl;
    heap.print();
    
    return 0;
}
