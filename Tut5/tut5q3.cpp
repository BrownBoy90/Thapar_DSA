#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Method 1: Two-pass approach (count nodes first)
    int findMiddleMethod1() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        
        // Count total nodes
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        // Find middle node
        int middleIndex = count / 2;
        temp = head;
        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    // Method 2: Tortoise and Hare Algorithm (One-pass, more efficient)
    int findMiddleMethod2() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        
        Node* slow = head;  // Moves one step at a time
        Node* fast = head;  // Moves two steps at a time
        
        // When fast reaches end, slow will be at middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
};

int main() {
    LinkedList list;
    
    // Create example list: 1->2->3->4->5
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    
    cout << "Linked List: ";
    list.display();
    
    cout << "\nMiddle element (Method 1 - Two Pass): " << list.findMiddleMethod1() << endl;
    cout << "Middle element (Method 2 - Tortoise & Hare): " << list.findMiddleMethod2() << endl;
    
    return 0;
}
