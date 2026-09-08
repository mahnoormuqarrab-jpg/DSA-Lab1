#include <iostream>
#include <vector>
#include <cstdlib>
#include "strassen.cpp"
using namespace std;

void printMatrix(Matrix M) {
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[i].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

bool matricesEqual(Matrix A, Matrix B) {
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            if (A[i][j] != B[i][j]) return false;
    return true;
}

int main() {
    // Test 1: 2x2 matrix multiplication
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    Matrix result2 = strassenMultiply(A2, B2);
    Matrix expected2 = standardMultiply(A2, B2);
    cout << "Test 1 (2x2): " << (matricesEqual(result2, expected2) ? "PASS" : "FAIL") << endl;
    printMatrix(result2);
    cout << endl;

    // Test 2: 4x4 matrix multiplication
    Matrix A4 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix B4 = {{16,15,14,13},{12,11,10,9},{8,7,6,5},{4,3,2,1}};
    Matrix result4 = strassenMultiply(A4, B4);
    Matrix expected4 = standardMultiply(A4, B4);
    cout << "Test 2 (4x4): " << (matricesEqual(result4, expected4) ? "PASS" : "FAIL") << endl;
    printMatrix(result4);
    cout << endl;

    // Test 3: random values compared with naive multiplication
    Matrix A3(4, vector<int>(4));
    Matrix B3(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A3[i][j] = rand() % 10;
            B3[i][j] = rand() % 10;
        }
    }
    Matrix resultRand = strassenMultiply(A3, B3);
    Matrix expectedRand = standardMultiply(A3, B3);
    cout << "Test 3 (random 4x4 vs naive): " << (matricesEqual(resultRand, expectedRand) ? "PASS" : "FAIL") << endl;

    return 0;
}
