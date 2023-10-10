#include <stdio.h>
#include <time.h>

// Size of the matrices
#define N 4

int main() {
    // Lower triangular matrices
    int A[N][N];
    int B[N][N];

    // Resultant matrix
    int C[N][N];

    clock_t start_time, end_time;

    // Initialize matrices A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = i - j + 1;
        }
    }

    start_time = clock();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    end_time = clock();

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nExecution time = %.6f seconds\n", exec_time);

    return 0;
}
