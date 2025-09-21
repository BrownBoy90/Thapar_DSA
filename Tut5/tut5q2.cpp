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
    
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        return count;
    }
    
    void deleteAllOccurrences(int key) {
        // Delete from the beginning
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        // Delete from middle and end
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data == key) {
                Node* nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete;
            } else {
                current = current->next;
            }
        }
    }
};

int main() {
    LinkedList list;
    
    // Create example list: 1->2->1->2->1->3->1
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);
    
    cout << "Original List: ";
    list.display();
    
    int key = 1;
    cout << "\nKey to count and delete: " << key << endl;
    
    int occurrences = list.countOccurrences(key);
    cout << "Number of occurrences of " << key << ": " << occurrences << endl;
    
    list.deleteAllOccurrences(key);
    
    cout << "\nList after deleting all occurrences of " << key << ": ";
    list.display();
    
    return 0;
}
