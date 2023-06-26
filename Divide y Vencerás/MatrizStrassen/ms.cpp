#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix sumOrest(const Matrix& A, const Matrix& B, bool op) 
{
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
            if(op)
                C[i][j] = A[i][j] + B[i][j];
        } 
            
    return C;
}

Matrix multiply(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C(n, vector<int>(n));
    if (n == 1) 
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    Matrix A11(n/2, vector<int>(n/2));
    Matrix A12(n/2, vector<int>(n/2));
    Matrix A21(n/2, vector<int>(n/2));
    Matrix A22(n/2, vector<int>(n/2));

    Matrix B11(n/2, vector<int>(n/2));
    Matrix B12(n/2, vector<int>(n/2));
    Matrix B21(n/2, vector<int>(n/2));
    Matrix B22(n/2, vector<int>(n/2));

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n/2];
            A21[i][j] = A[i + n/2][j];
            A22[i][j] = A[i + n/2][j + n/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n/2];
            B21[i][j] = B[i + n/2][j];
            B22[i][j] = B[i + n/2][j + n/2];
        }
    }

    Matrix P1 = multiply(A11, sumOrest(B12, B22,0));
    Matrix P2 = multiply(sumOrest(A11, A12,1), B22);
    Matrix P3 = multiply(sumOrest(A21, A22,1), B11);
    Matrix P4 = multiply(A22, sumOrest(B21, B11,0));
    Matrix P5 = multiply(sumOrest(A11, A22,1), sumOrest(B11, B22,1));
    Matrix P6 = multiply(sumOrest(A12, A22,0), sumOrest(B21, B22,1));
    Matrix P7 = multiply(sumOrest(A11, A21,0), sumOrest(B11, B12,1));

    Matrix C11 = sumOrest(sumOrest(sumOrest(P5, P4,1), P2,0), P6,1);
    Matrix C12 = sumOrest(P1, P2,1);
    Matrix C21 = sumOrest(P3, P4,1);
    Matrix C22 = sumOrest(sumOrest(sumOrest(P5, P1,1), P3,0), P7,0);

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n/2] = C12[i][j];
            C[i + n/2][j] = C21[i][j];
            C[i + n/2][j + n/2] = C22[i][j];
        }
    }

    return C;
}

void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {
        {4, 5},
        {7, 8}
    };

    Matrix B = {
        {1, 9},
        {4, 2}
    };

    Matrix C = multiply(A, B);

    cout << "Matriz A:" << endl;
    printMatrix(A);
    cout << "Matriz B:" << endl;
    printMatrix(B);
    cout << "Producto de matrices:" << endl;
    printMatrix(C);
}
