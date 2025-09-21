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

class SinglyLinkedList {
private:
    Node* head;
    
public:
    SinglyLinkedList() {
        head = nullptr;
    }
    
    // (a) Insertion at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node " << data << " inserted at the beginning." << endl;
    }
    
    // (b) Insertion at the end
    void insertAtEnd(int data) {
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
        cout << "Node " << data << " inserted at the end." << endl;
    }
    
    // (c) Insertion before/after a specific value
    void insertBefore(int target, int data) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->data == target) {
            insertAtBeginning(data);
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Target node " << target << " not found!" << endl;
        } else {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Node " << data << " inserted before " << target << endl;
        }
    }
    
    void insertAfter(int target, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Target node " << target << " not found!" << endl;
        } else {
            Node* newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Node " << data << " inserted after " << target << endl;
        }
    }
    
    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Node " << temp->data << " deleted from beginning." << endl;
        delete temp;
    }
    
    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Node " << head->data << " deleted from end." << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Node " << temp->next->data << " deleted from end." << endl;
        delete temp->next;
        temp->next = nullptr;
    }
    
    // (f) Deletion of a specific node
    void deleteSpecificNode(int target) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->data == target) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Node " << target << " not found!" << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            cout << "Node " << target << " deleted successfully." << endl;
            delete nodeToDelete;
        }
    }
    
    // (g) Search for a node and display its position
    void searchNode(int target) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            if (temp->data == target) {
                cout << "Node " << target << " found at position " << position << " from head." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Node " << target << " not found in the list!" << endl;
    }
    
    // (h) Display all node values
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        
        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, data, target;
    
    do {
        cout << "\n========== SINGLY LINKED LIST OPERATIONS ==========" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert Before a Node" << endl;
        cout << "4. Insert After a Node" << endl;
        cout << "5. Delete from Beginning" << endl;
        cout << "6. Delete from End" << endl;
        cout << "7. Delete Specific Node" << endl;
        cout << "8. Search Node" << endl;
        cout << "9. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
                
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
                
            case 3:
                cout << "Enter target node: ";
                cin >> target;
                cout << "Enter data to insert before " << target << ": ";
                cin >> data;
                list.insertBefore(target, data);
                break;
                
            case 4:
                cout << "Enter target node: ";
                cin >> target;
                cout << "Enter data to insert after " << target << ": ";
                cin >> data;
                list.insertAfter(target, data);
                break;
                
            case 5:
                list.deleteFromBeginning();
                break;
                
            case 6:
                list.deleteFromEnd();
                break;
                
            case 7:
                cout << "Enter node to delete: ";
                cin >> target;
                list.deleteSpecificNode(target);
                break;
                
            case 8:
                cout << "Enter node to search: ";
                cin >> target;
                list.searchNode(target);
                break;
                
            case 9:
                list.displayList();
                break;
                
            case 0:
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
