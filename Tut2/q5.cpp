#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// (a) Diagonal Matrix
class DiagonalMatrix {
private:
    vector<int> diagonal;
    int n;

public:
    DiagonalMatrix(const vector<int>& diag) : diagonal(diag), n(diag.size()) {}

    int getElement(int i, int j) {
        if (i == j && i < n)
            return diagonal[i];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (b) Tri-diagonal Matrix
class TridiagonalMatrix {
private:
    vector<int> lower, main, upper;
    int n;

public:
    TridiagonalMatrix(const vector<int>& l, const vector<int>& m, const vector<int>& u)
        : lower(l), main(m), upper(u), n(m.size()) {}

    int getElement(int i, int j) {
        if (i == j)
            return main[i];
        else if (i == j + 1 && j < n - 1)
            return lower[j];
        else if (i == j - 1 && i < n - 1)
            return upper[i];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (c) Lower Triangular Matrix
class LowerTriangularMatrix {
private:
    vector<int> elements;
    int n;

public:
    LowerTriangularMatrix(const vector<int>& elems) : elements(elems) {
        n = (-1 + sqrt(1 + 8 * elems.size())) / 2;
    }

    int getElement(int i, int j) {
        if (i >= j) {
            int index = i * (i + 1) / 2 + j;
            return elements[index];
        }
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (d) Upper Triangular Matrix
class UpperTriangularMatrix {
private:
    vector<int> elements;
    int n;

public:
    UpperTriangularMatrix(const vector<int>& elems) : elements(elems) {
        n = (-1 + sqrt(1 + 8 * elems.size())) / 2;
    }

    int getElement(int i, int j) {
        if (i <= j) {
            int index = i * n - i * (i - 1) / 2 + (j - i);
            return elements[index];
        }
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (e) Symmetric Matrix
class SymmetricMatrix {
private:
    vector<int> elements;
    int n;

public:
    SymmetricMatrix(const vector<int>& elems) : elements(elems) {
        n = (-1 + sqrt(1 + 8 * elems.size())) / 2;
    }

    int getElement(int i, int j) {
        if (i <= j) {
            int index = i * n - i * (i - 1) / 2 + (j - i);
            return elements[index];
        } else {
            int index = j * n - j * (j - 1) / 2 + (i - j);
            return elements[index];
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage:
    DiagonalMatrix d({1, 2, 3});
    cout << "Diagonal Matrix:" << endl;
    d.display();

    TridiagonalMatrix t({4, 5}, {1, 2, 3}, {6, 7});
    cout << "\nTridiagonal Matrix:" << endl;
    t.display();

    LowerTriangularMatrix l({1, 2, 3, 4, 5, 6});
    cout << "\nLower Triangular Matrix:" << endl;
    l.display();

    UpperTriangularMatrix u({1, 2, 3, 4, 5, 6});
    cout << "\nUpper Triangular Matrix:" << endl;
    u.display();

    SymmetricMatrix s({1, 2, 3, 4, 5, 6});
    cout << "\nSymmetric Matrix:" << endl;
    s.display();

    return 0;
}