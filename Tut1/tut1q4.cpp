// Reverse the elements of an array 
#include<iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int i = 0;
    int total = sizeof(arr)/sizeof(arr[0]);

    for(i = 0; i < total/2; i++) {
       int temp = arr[i];
       arr[i] = arr[total - i - 1];
       arr[total - i - 1] = temp;
    }

    // printing
    for(i = 0; i< total; i++){
        cout<<arr[i]<<" ";
    }
}

// Find the matrix multiplication
#include<iostream>
using namespace std;

int main() {
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matrix2[3][3] = {{10,11,12},{13,14,15},{16,17,18}};
    
    int C[3][3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

// // Find the Transpose of a Matrix
// #include<iostream>
// using namespace std;

// int main() {
//     int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     int i = 0,j = 0;

//     for(i = 0; i<3; i++) {
//         for (j = 0; j<3; j++) {
//             cout<<matrix1[i][j];
//         }
//         cout<<endl;
//     }

//     for(i = 0; i<3; i++) {
//         for (j = i+1; j<3; j++) {
//             int temp = matrix1[i][j];
//             matrix1[i][j] = matrix1[j][i];
//             matrix1[j][i] = temp;
//         }
//     }

//     for(i = 0; i<3; i++) {
//         for (j = 0; j<3; j++) {
//             cout<<matrix1[i][j];
//         }
//         cout<<endl;
//     }

// }

