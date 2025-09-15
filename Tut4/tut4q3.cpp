#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int start, end, currSize, maxSize;
    
public:
    Queue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    
    void push(int element) {
        if (currSize == maxSize) return;
        if (end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = element;
        currSize++;
    }
    
    int pop() {
        if (start == -1) return -1;
        int element = arr[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return element;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    int size() {
        return currSize;
    }
    
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(10);
    // Sample input: 4 7 11 20 5 9
    int input[] = {4, 7, 11, 20, 5, 9};
    int n = 6;
    
    cout << "Original Queue: ";
    for (int i = 0; i < n; i++) {
        q.push(input[i]);
        cout << input[i] << " ";
    }
    cout << endl;
    
    Queue firstHalf(10);
    int qSize = q.size();
    
    // Extract first half
    for (int i = 0; i < qSize/2; i++) {
        firstHalf.push(q.pop());
    }
    
    // Interleave
    cout << "Interleaved Queue: ";
    while (!firstHalf.isEmpty()) {
        cout << firstHalf.pop() << " ";
        cout << q.pop() << " ";
    }
    cout << endl;
    
    return 0;
}
