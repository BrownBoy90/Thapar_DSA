// Write a program to find sum of every row and every column in a two-dimensional array

#include<iostream>
using namespace std;

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int r1=0,r2=0,r3=0,c1=0,c2=0,c3=0;

    for (int i = 0; i<3; i++) {
        r1 += A[0][i];
    }
    cout<<r1<<endl;

    
    for (int i = 0; i<3; i++) {
        r2 += A[1][i];
    }
    cout<<r2<<endl;

    for (int i = 0; i<3; i++) {
        r3 += A[2][i];
    }
    cout<<r3<<endl;

// Columns
    for (int i = 0; i<3; i++) {
        c1 += A[i][0];
    }
    cout<<c1<<endl;

    
    for (int i = 0; i<3; i++) {
        c2 += A[i][1];
    }
    cout<<c2<<endl;

    for (int i = 0; i<3; i++) {
        c3 += A[i][2];
    }
    cout<<c3<<endl;


}