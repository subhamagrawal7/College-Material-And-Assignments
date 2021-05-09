#include <bits/stdc++.h>

using namespace std;
int ** matrix_allocate(int n) {
        int ** mat = new int * [n];
        int i, j;
        for (i = 0; i < n; ++i) {
                mat[i] = new int[n];
        }
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        mat[i][j] = 0;
                }
        }
        return mat;
}
void matrix_free(int ** m, int n) {
        int i;
        for (i = 0; i < n; i++) {
                free(m[i]);
        }
        free(m);
}
int ** matrix_add(int ** a, int ** b, int n) {
        int i, j;
        int ** c = matrix_allocate(n);
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        c[i][j] = a[i][j] + b[i][j];
                }
        }
        return c;
}
int ** matrix_sub(int ** a, int ** b, int n) {
        int i, j;
        int ** c = matrix_allocate(n);
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        c[i][j] = a[i][j] - b[i][j];
                }
        }
        return c;
}
int ** mul_strassen(int ** a, int ** b, int n) {
        int i, j;
        int ** c = matrix_allocate(n);
        if (n == 1) {
                c[0][0] = a[0][0] * b[0][0];
        } else {
                int ** a11 = matrix_allocate(n / 2);
                int ** a12 = matrix_allocate(n / 2);
                int ** a21 = matrix_allocate(n / 2);
                int ** a22 = matrix_allocate(n / 2);
                int ** b11 = matrix_allocate(n / 2);
                int ** b12 = matrix_allocate(n / 2);
                int ** b21 = matrix_allocate(n / 2);
                int ** b22 = matrix_allocate(n / 2);
                for (i = 0; i < n / 2; i++) {
                        for (j = 0; j < n / 2; j++) {
                                a11[i][j] = a[i][j];
                                a12[i][j] = a[i][j + n / 2];
                                a21[i][j] = a[i + n / 2][j];
                                a22[i][j] = a[i + n / 2][j + n / 2];
                                b11[i][j] = b[i][j];
                                b12[i][j] = b[i][j + n / 2];
                                b21[i][j] = b[i + n / 2][j];
                                b22[i][j] = b[i + n / 2][j + n / 2];
                        }
                }
                int ** P1 = mul_strassen(a11, matrix_sub(b12, b22, n / 2), n / 2);
                int ** P2 = mul_strassen(matrix_add(a11, a12, n / 2), b22, n / 2);
                int ** P3 = mul_strassen(matrix_add(a21, a22, n / 2), b11, n / 2);
                int ** P4 = mul_strassen(a22, matrix_sub(b21, b11, n / 2), n / 2);
                int ** P5 = mul_strassen(matrix_add(a11, a22, n / 2), matrix_add(b11, b22, n / 2), n / 2);
                int ** P6 = mul_strassen(matrix_sub(a12, a22, n / 2), matrix_add(b21, b22, n / 2), n / 2);
                int ** P7 = mul_strassen(matrix_sub(a11, a21, n / 2), matrix_add(b11, b12, n / 2), n / 2);
                int ** c11 = matrix_sub(matrix_add(matrix_add(P5, P4, n / 2), P6, n / 2), P2, n / 2);
                int ** c12 = matrix_add(P1, P2, n / 2);
                int ** c21 = matrix_add(P3, P4, n / 2);
                int ** c22 = matrix_sub(matrix_sub(matrix_add(P5, P1, n / 2), P3, n / 2), P7, n / 2);

                for (i = 0; i < n / 2; i++) {
                        for (j = 0; j < n / 2; j++) {
                                c[i][j] = c11[i][j];
                                c[i][j + n / 2] = c12[i][j];
                                c[i + n / 2][j] = c21[i][j];
                                c[i + n / 2][j + n / 2] = c22[i][j];
                        }
                }
                matrix_free(c11, n / 2);
                matrix_free(c12, n / 2);
                matrix_free(c21, n / 2);
                matrix_free(c22, n / 2);
        }
        return c;
}
int main() {
        int i, j;
        int r1, c1, r2, c2;
        cout << "Enter row and column of matrix A : \n";
        cin >> r1 >> c1;
        cout << "Enter row and column of matrix B : \n";
        cin >> r2 >> c2;
        if (c1 != r2) {
                cout << "error!";
                return 0;
        }
        int n = max(r1, max(c1, max(r2, c2)));
        if (ceil(log(n)) != floor(log(n))) {
                n = pow(2, ceil(log2(n)));
        }
        int ** a = matrix_allocate(n);
        int ** b = matrix_allocate(n);
        cout << "\nEnter elements of first matrix: ";
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                        cin >> a[i][j];
                }
        }
        printf("Enter elements of second matrix: ");
        for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                        cin >> b[i][j];
                }
        }
        int ** c = mul_strassen(a, b, n);
        cout << "Product:\n";
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                        cout << c[i][j] << "\t";
                }
                cout << "\n";
        }
        return 0;
}
