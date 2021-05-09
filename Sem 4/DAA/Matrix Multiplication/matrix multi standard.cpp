#include <bits/stdc++.h>

using namespace std;
int ** matrix_allocate(int n) {
        int ** mat = new int * [n];
        for (int i = 0; i < n; ++i) {
                mat[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        mat[i][j] = 0;
                }
        }
        return mat;
}
int main() {
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
        int ** c = matrix_allocate(n);
        cout << "\nEnter elements of first matrix: ";
        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                        cin >> a[i][j];
                }
        }
        cout << "Enter elements of second matrix: ";
        for (int i = 0; i < r2; i++) {
                for (int j = 0; j < c2; j++) {
                        cin >> b[i][j];
                }
        }
        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                        c[i][j] = 0;
                        for (int k = 0; k < c1; k++) {
                                c[i][j] += a[i][k] * b[k][j];
                        }
                }
        }
        cout << "Product:\n";
        for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c2; j++) {
                        cout << c[i][j] << "\t";
                }
                cout << "\n";
        }
        return 0;
}
