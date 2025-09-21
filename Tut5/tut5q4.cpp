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
        cout << "->NULL" << endl;
    }
    
    // Method 1: Iterative Approach (Easiest and Most Efficient)
    void reverseIterative() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            // Store next node
            next = current->next;
            
            // Reverse current node's pointer
            current->next = prev;
            
            // Move pointers one position ahead
            prev = current;
            current = next;
        }
        
        // Update head to point to the new first node
        head = prev;
    }
    
    // Method 2: Recursive Approach
    Node* reverseRecursiveHelper(Node* node) {
        // Base case: if node is NULL or last node
        if (node == nullptr || node->next == nullptr) {
            return node;
        }
        
        // Recursively reverse the rest of the list
        Node* newHead = reverseRecursiveHelper(node->next);
        
        // Reverse the current connection
        node->next->next = node;
        node->next = nullptr;
        
        return newHead;
    }
    
    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }
};

int main() {
    // Test Iterative Approach
    LinkedList list1;
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    
    cout << "Original List: ";
    list1.display();
    
    list1.reverseIterative();
    cout << "Reversed List (Iterative): ";
    list1.display();
    
    // Test Recursive Approach
    LinkedList list2;
    list2.insert(1);
    list2.insert(2);
    list2.insert(3);
    list2.insert(4);
    
    cout << "\nOriginal List: ";
    list2.display();
    
    list2.reverseRecursive();
    cout << "Reversed List (Recursive): ";
    list2.display();
    
    return 0;
}
