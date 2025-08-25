#include <iostream>
#include <cmath> // For sqrt

using namespace std;

// (a) Diagonal Matrix
struct DiagonalMatrix {
    int* diagonal; // Changed from vector<int>
    int n;
};

int getDiagonalElement(const DiagonalMatrix& m, int i, int j) {
    if (i == j && i < m.n) {
        return m.diagonal[i];
    }
    return 0;
}

void displayDiagonalMatrix(const DiagonalMatrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << getDiagonalElement(m, i, j) << " ";
        }
        cout << endl;
    }
}

// (b) Tridiagonal Matrix
struct TridiagonalMatrix {
    int* lower; // Changed from vector<int>
    int* main;  // Changed from vector<int>
    int* upper; // Changed from vector<int>
    int n;
};

int getTridiagonalElement(const TridiagonalMatrix& m, int i, int j) {
    if (i == j) {
        return m.main[i];
    } else if (i == j + 1 && j < m.n - 1) {
        return m.lower[j];
    } else if (i == j - 1 && i < m.n - 1) {
        return m.upper[i];
    }
    return 0;
}

void displayTridiagonalMatrix(const TridiagonalMatrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << getTridiagonalElement(m, i, j) << " ";
        }
        cout << endl;
    }
}

// (c) Lower Triangular Matrix
struct LowerTriangularMatrix {
    int* elements; // Changed from vector<int>
    int n;
};

// Modified init function to take a raw array and its size
void initLowerTriangularMatrix(LowerTriangularMatrix& m, int* elems, int size) {
    m.elements = elems;
    // Calculate n (dimension) from the number of elements
    m.n = static_cast<int>((-1 + sqrt(1 + 8.0 * size)) / 2);
}

int getLowerTriangularElement(const LowerTriangularMatrix& m, int i, int j) {
    if (i >= j) {
        // Row-major mapping
        int index = i * (i + 1) / 2 + j;
        return m.elements[index];
    }
    return 0;
}

void displayLowerTriangularMatrix(const LowerTriangularMatrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << getLowerTriangularElement(m, i, j) << " ";
        }
        cout << endl;
    }
}

// (d) Upper Triangular Matrix
struct UpperTriangularMatrix {
    int* elements; // Changed from vector<int>
    int n;
};

// Modified init function
void initUpperTriangularMatrix(UpperTriangularMatrix& m, int* elems, int size) {
    m.elements = elems;
    m.n = static_cast<int>((-1 + sqrt(1 + 8.0 * size)) / 2);
}

int getUpperTriangularElement(const UpperTriangularMatrix& m, int i, int j) {
    if (i <= j) {
        // Row-major mapping
        int index = i * m.n - i * (i - 1) / 2 + (j - i);
        return m.elements[index];
    }
    return 0;
}

void displayUpperTriangularMatrix(const UpperTriangularMatrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << getUpperTriangularElement(m, i, j) << " ";
        }
        cout << endl;
    }
}

// (e) Symmetric Matrix
struct SymmetricMatrix {
    int* elements; // Changed from vector<int>
    int n;
};

// Modified init function
void initSymmetricMatrix(SymmetricMatrix& m, int* elems, int size) {
    m.elements = elems;
    m.n = static_cast<int>((-1 + sqrt(1 + 8.0 * size)) / 2);
}

int getSymmetricElement(const SymmetricMatrix& m, int i, int j) {
    // We only store the upper triangle
    if (i <= j) { 
        int index = i * m.n - i * (i - 1) / 2 + (j - i);
        return m.elements[index];
    } else { // Reflect to get the lower triangle element
        int index = j * m.n - j * (j - 1) / 2 + (i - j);
        return m.elements[index];
    }
}

void displaySymmetricMatrix(const SymmetricMatrix& m) {
    for (int i = 0; i < m.n; i++) {
        for (int j = 0; j < m.n; j++) {
            cout << getSymmetricElement(m, i, j) << " ";
        }
        cout << endl;
    }
}


int main() {
    // (a) Diagonal Matrix
    cout << "Diagonal Matrix:" << endl;
    int diag_elements[] = {1, 2, 3};
    DiagonalMatrix d = {diag_elements, 3};
    displayDiagonalMatrix(d);

    // (b) Tridiagonal Matrix
    cout << "\nTridiagonal Matrix:" << endl;
    int lower_elements[] = {4, 5};
    int main_elements[] = {1, 2, 3};
    int upper_elements[] = {6, 7};
    TridiagonalMatrix t = {lower_elements, main_elements, upper_elements, 3};
    displayTridiagonalMatrix(t);

    // (c) Lower Triangular Matrix
    cout << "\nLower Triangular Matrix:" << endl;
    int lower_tri_elements[] = {1, 2, 3, 4, 5, 6};
    int lower_tri_size = sizeof(lower_tri_elements) / sizeof(lower_tri_elements[0]);
    LowerTriangularMatrix l;
    initLowerTriangularMatrix(l, lower_tri_elements, lower_tri_size);
    displayLowerTriangularMatrix(l);

    // (d) Upper Triangular Matrix
    cout << "\nUpper Triangular Matrix:" << endl;
    int upper_tri_elements[] = {1, 2, 3, 4, 5, 6};
    int upper_tri_size = sizeof(upper_tri_elements) / sizeof(upper_tri_elements[0]);
    UpperTriangularMatrix u;
    initUpperTriangularMatrix(u, upper_tri_elements, upper_tri_size);
    displayUpperTriangularMatrix(u);

    // (e) Symmetric Matrix
    cout << "\nSymmetric Matrix:" << endl;
    int symm_elements[] = {1, 2, 3, 4, 5, 6};
    int symm_size = sizeof(symm_elements) / sizeof(symm_elements[0]);
    SymmetricMatrix s;
    initSymmetricMatrix(s, symm_elements, symm_size);
    displaySymmetricMatrix(s);

    return 0;
}