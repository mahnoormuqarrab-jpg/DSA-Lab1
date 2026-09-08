#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Standard (naive) matrix multiplication
Matrix standardMultiply(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Helper: add two matrices
Matrix addMatrix(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Helper: subtract two matrices
Matrix subMatrix(Matrix A, Matrix B) {
    int n = A.size();
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen's algorithm (matrix size must be a power of 2)
Matrix strassenMultiply(Matrix A, Matrix B) {
    int n = A.size();

    // Base case: 1x1 matrix
    if (n == 1) {
        Matrix result(1, vector<int>(1));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    int half = n / 2;
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));

    // Split matrices into quadrants
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // 7 recursive multiplications
    Matrix M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenMultiply(addMatrix(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subMatrix(B12, B22));
    Matrix M4 = strassenMultiply(A22, subMatrix(B21, B11));
    Matrix M5 = strassenMultiply(addMatrix(A11, A12), B22);
    Matrix M6 = strassenMultiply(subMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenMultiply(subMatrix(A12, A22), addMatrix(B21, B22));

    // Combine results into quadrants
    Matrix C11 = addMatrix(subMatrix(addMatrix(M1, M4), M5), M7);
    Matrix C12 = addMatrix(M3, M5);
    Matrix C21 = addMatrix(M2, M4);
    Matrix C22 = addMatrix(subMatrix(addMatrix(M1, M3), M2), M6);

    // Combine quadrants into final result
    Matrix result(n, vector<int>(n));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}
