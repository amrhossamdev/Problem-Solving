#include <bits/stdc++.h>

using namespace std;


int main() {
    /*
     * n -> total number of 2d arrays ( block size )
     * m -> row
     * p -> col
    */
    int n, m, p;
    cout << "Enter block size(n) = " << endl;
    cin >> n;
    cout << "Enter row size (m) = " << endl;
    cin >> m;
    cout << "Enter col size (p) = " << endl;
    cin >> p;
    cout << "Enter 3d matrix" << endl;
    int matrix[n][m][p];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cin >> matrix[i][j][k];
            }
        }
    }
    cout << "Result :" << endl;
    int q = n * m * p; // size of 1d vector
    int v[q];
    //traversing 3d array
    //time complexity o(1) for converting 3d to 1d & o(N) for traversing
    //space complexity o(n)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                int idx = (i * m * p) + (j * p) + k; // takes o(1) to generate 1d vector indexes
                v[idx] = matrix[i][j][k];// assigning takes o(1)
            }
        }
    }
    for (int y = 0; y < q; ++y) { cout << v[y] << " "; }
    return 0;
}