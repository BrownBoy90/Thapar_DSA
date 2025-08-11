#include <iostream>
using namespace std;

int arr[10] = {2,3,2,2,6,7,2,6,8,7};

int removeElement(int elementNumber, int &size) {
    for(int i = elementNumber; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    return 1;
}

int main() {
    int size = 10;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                removeElement(j, size);
                j--; 
            }
        }
    }

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
