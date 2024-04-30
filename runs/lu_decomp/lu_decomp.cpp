#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <ctime>

void LU_decomposition(double **A, double **L, double **U, int size) {
    int i, j, k;
    #pragma omp parallel for private(j, k)
    for (i = 0; i < size; i++) {
        // Upper Triangle
        for (k = i; k < size; k++) {
            double sum = 0.0;
            for (j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }
        // Lower Triangle
        for (k = i; k < size; k++) {
            if (i == k) {
                L[i][i] = 1.0;  // Diagonal elements as 1
            } else {
                double sum = 0.0;
                for (j = 0; j < i; j++) {
                    sum += L[k][j] * U[j][i];
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <matrix_size>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);

    // Allocate memory for matrices A, L, and U
    double **A, **L, **U;
    A = (double **)malloc(size * sizeof(double *));
    L = (double **)malloc(size * sizeof(double *));
    U = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        A[i] = (double *)malloc(size * sizeof(double));
        L[i] = (double *)malloc(size * sizeof(double));
        U[i] = (double *)malloc(size * sizeof(double));
    }

    // Generate random matrix A
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Perform LU decomposition
    LU_decomposition(A, L, U, size);

    // Print the result
    printf("\nLower Triangular Matrix (L):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", L[i][j]);
        }
        printf("\n");
    }

    printf("\nUpper Triangular Matrix (U):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", U[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(A[i]);
        free(L[i]);
        free(U[i]);
    }
    free(A);
    free(L);
    free(U);

    return 0;
}
