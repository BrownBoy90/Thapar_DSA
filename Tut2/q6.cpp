#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Triplet {
    int row, col, value;
    Triplet(int r, int c, int v) : row(r), col(c), value(v) {}
};

class SparseMatrix {
private:
    vector<Triplet> triplets;
    int rows, cols;

public:
    SparseMatrix(const vector<Triplet>& t) : triplets(t) {
        rows = cols = 0;
        for (const auto& triplet : triplets) {
            rows = max(rows, triplet.row + 1);
            cols = max(cols, triplet.col + 1);
        }
    }
    
    // (a) Transpose
    SparseMatrix transpose() {
        vector<Triplet> transposed;
        for (const auto& t : triplets) {
            transposed.push_back(Triplet(t.col, t.row, t.value));
        }
        return SparseMatrix(transposed);
    }
    
    // (b) Addition
    SparseMatrix add(const SparseMatrix& other) {
        map<pair<int, int>, int> elementMap;
        
        // Add elements from first matrix
        for (const auto& t : triplets) {
            elementMap[{t.row, t.col}] += t.value;
        }
        
        // Add elements from second matrix
        for (const auto& t : other.triplets) {
            elementMap[{t.row, t.col}] += t.value;
        }
        
        vector<Triplet> result;
        for (const auto& pair : elementMap) {
            if (pair.second != 0) {
                result.push_back(Triplet(pair.first.first, pair.first.second, pair.second));
            }
        }
        
        return SparseMatrix(result);
    }
    
    // (c) Multiplication
    SparseMatrix multiply(const SparseMatrix& other) {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions incompatible for multiplication");
        }
        
        map<pair<int, int>, int> resultMap;
        
        for (const auto& t1 : triplets) {
            for (const auto& t2 : other.triplets) {
                if (t1.col == t2.row) {
                    pair<int, int> key = {t1.row, t2.col};
                    resultMap[key] += t1.value * t2.value;
                }
            }
        }
        
        vector<Triplet> result;
        for (const auto& pair : resultMap) {
            if (pair.second != 0) {
                result.push_back(Triplet(pair.first.first, pair.first.second, pair.second));
            }
        }
        
        return SparseMatrix(result);
    }
    
    void display() {
        cout << "Sparse Matrix (row, col, value):" << endl;
        for (const auto& t : triplets) {
            cout << "(" << t.row << ", " << t.col << ", " << t.value << ")" << endl;
        }
    }
};

int main() {
    // Example matrices
    vector<Triplet> t1 = { {0, 0, 1}, {0, 2, 2}, {1, 1, 3} };
    vector<Triplet> t2 = { {0, 0, 4}, {1, 1, 5}, {2, 0, 6} };

    SparseMatrix m1(t1);
    SparseMatrix m2(t2);

    cout << "Matrix 1:" << endl;
    m1.display();

    cout << "\nMatrix 2:" << endl;
    m2.display();

    cout << "\nTranspose of Matrix 1:" << endl;
    m1.transpose().display();

    cout << "\nAddition (Matrix 1 + Matrix 2):" << endl;
    m1.add(m2).display();

    cout << "\nMultiplication (Matrix 1 x Matrix 2):" << endl;
    try {
        m1.multiply(m2).display();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}