#include <iostream>
#include <vector>
#include <cstdlib>
#include <omp.h>

using namespace std;

void matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
            for (int k = 0; k < p; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <tamanho_da_matriz>" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Tamanho da matriz

    if (n <= 0) {
        cerr << "O tamanho da matriz deve ser maior que zero." << endl;
        return 1;
    }

    vector<vector<int>> A(n, vector<int>(n, 1));
    vector<vector<int>> B(n, vector<int>(n, 2));
    vector<vector<int>> result(n, vector<int>(n, 0));

    matrix_multiply(A, B, result);

    return 0;
}

