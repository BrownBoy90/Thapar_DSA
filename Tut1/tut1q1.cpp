#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int currentSize = 0;

void displayMenu() {
    cout << "\n========== ARRAY OPERATIONS MENU ==========" << endl;
    cout << "1. CREATE" << endl;
    cout << "2. DISPLAY" << endl;
    cout << "3. INSERT" << endl;
    cout << "4. DELETE" << endl;
    cout << "5. LINEAR SEARCH" << endl;
    cout << "6. EXIT" << endl;
    cout << "===========================================" << endl;
    cout << "Enter your choice (1-6): ";
}

void createArray() {
    cout << "\nEnter the number of elements (max " << MAX_SIZE << "): ";
    cin >> currentSize;
    
    if (currentSize > MAX_SIZE || currentSize < 0) {
        cout << "Invalid size! Please enter a size between 0 and " << MAX_SIZE << endl;
        currentSize = 0;
        return;
    }
    
    cout << "Enter " << currentSize << " elements: ";
    for (int i = 0; i < currentSize; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully!" << endl;
}

void displayArray() {
    if (currentSize == 0) {
        cout << "\nArray is empty!" << endl;
        return;
    }
    
    cout << "\nArray elements: ";
    for (int i = 0; i < currentSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Array size: " << currentSize << endl;
}

void insertElement() {
    if (currentSize >= MAX_SIZE) {
        cout << "\nArray is full! Cannot insert more elements." << endl;
        return;
    }
    
    int element, position;
    cout << "\nEnter element to insert: ";
    cin >> element;
    cout << "Enter position (0 to " << currentSize << "): ";
    cin >> position;
    
    if (position < 0 || position > currentSize) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // Shift elements to the right
    for (int i = currentSize; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    currentSize++;
    cout << "Element " << element << " inserted at position " << position << " successfully!" << endl;
}

void deleteElement() {
    if (currentSize == 0) {
        cout << "\nArray is empty! Nothing to delete." << endl;
        return;
    }
    
    int position;
    cout << "\nCurrent array size: " << currentSize << endl;
    cout << "Enter position to delete (0 to " << currentSize - 1 << "): ";
    cin >> position;
    
    if (position < 0 || position >= currentSize) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    int deletedElement = arr[position];
    
    // Shift elements to the left
    for (int i = position; i < currentSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    currentSize--;
    cout << "Element " << deletedElement << " deleted from position " << position << " successfully!" << endl;
}

void linearSearch() {
    if (currentSize == 0) {
        cout << "\nArray is empty! Cannot search." << endl;
        return;
    }
    
    int element;
    cout << "\nEnter element to search: ";
    cin >> element;
    
    bool found = false;
    cout << "Element " << element;
    
    for (int i = 0; i < currentSize; i++) {
        if (arr[i] == element) {
            if (!found) {
                cout << " found at position(s): ";
                found = true;
            }
            cout << i << " ";
        }
    }
    
    if (!found) {
        cout << " not found in the array!";
    }
    cout << endl;
}

int main() {
    int choice;
    
    cout << "Welcome to Array Operations Program!" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                createArray();
                break;
                
            case 2:
                displayArray();
                break;
                
            case 3:
                insertElement();
                break;
                
            case 4:
                deleteElement();
                break;
                
            case 5:
                linearSearch();
                break;
                
            case 6:
                cout << "\nThank you for using Array Operations Program!" << endl;
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "\nInvalid choice! Please enter a number between 1-6." << endl;
        }
        
        if (choice != 6) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 6);
    
    return 0;
}
