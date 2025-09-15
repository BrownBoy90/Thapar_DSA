// Write a program to find sum of every row and every column in a two-dimensional array

#include<iostream>
using namespace std;

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int row[3] = {0,0,0};
    int column[3] = {0,0,0};

    // row
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j< 3; j++) {
            row[i] += A[i][j];
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j< 3; j++) {
            column[j] += A[j][i];
        }
    }

    for(int i = 0; i < 3; i++) {
        cout<<row[i]<<endl;
        cout<<column[i]<<endl;
        cout<<endl;
    }
}