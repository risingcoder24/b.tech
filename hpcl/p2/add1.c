#include <stdio.h>
#include <omp.h>

int main() {
    const int size = 10;
    float scalar = 5.0;
    float vector[size];
    
    // Initialize the vector
    for (int i = 0; i < size; i++) {
        vector[i] = i + 1;
    }
    
    printf("Original vector:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", vector[i]);
    }
    printf("\n");

    int num_threads = 4;  // You can adjust this value
    printf("Using %d threads.\n", num_threads);

    // Specify the number of threads explicitly
    #pragma omp parallel for num_threads(num_threads) shared(vector, scalar)
    for (int i = 0; i < size; i++) {
        int thread_num = omp_get_thread_num();
        vector[i] += scalar;
        printf("Thread %d updated element %d\n", thread_num, i);
    }

    printf("Vector after addition:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", vector[i]);
    }
    printf("\n");

    return 0;
}
