#include <iostream>
using namespace std;

class QueueForInterleave {
private:
    int arr[100];
    int front, rear;
    
public:
    QueueForInterleave() {
        front = 0;
        rear = -1;
    }
    
    void enqueue(int x) {
        arr[++rear] = x;
    }
    
    int dequeue() {
        return arr[front++];
    }
    
    bool isEmpty() {
        return front > rear;
    }
    
    int size() {
        return rear - front + 1;
    }
};

void interleaveQueue() {
    QueueForInterleave q;
    // Sample input: 4 7 11 20 5 9
    int input[] = {4, 7, 11, 20, 5, 9};
    int n = 6;
    
    cout << "Original Queue: ";
    for (int i = 0; i < n; i++) {
        q.enqueue(input[i]);
        cout << input[i] << " ";
    }
    cout << endl;
    
    QueueForInterleave firstHalf;
    int qSize = q.size();
    
    // Extract first half
    for (int i = 0; i < qSize/2; i++) {
        firstHalf.enqueue(q.dequeue());
    }
    
    // Interleave
    cout << "Interleaved Queue: ";
    while (!firstHalf.isEmpty()) {
        cout << firstHalf.dequeue() << " ";
        cout << q.dequeue() << " ";
    }
    cout << endl;
}

int main() {
    interleaveQueue();
    return 0;
}
