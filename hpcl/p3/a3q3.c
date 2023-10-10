#include <stdio.h>
#include <omp.h>

int main() {
    int n = 0;
    printf("Enter Vector size: ");
    scanf("%d", &n);
    float vector[n];
    double scalar;
    printf("Enter scalar value: ");
    scanf("%lf", &scalar);

    // Serial Code
    double start_time_serial = omp_get_wtime();

    for (int i = 0; i < n; i++) {
        vector[i] = i + 100.987453323212;
    }

    for (int i = 0; i < n; i++) {
        vector[i] += scalar;
    }

    double end_time_serial = omp_get_wtime();

    printf("Serial Method Time: %f seconds\n", (end_time_serial - start_time_serial));

    // Parallel Code
    double start_time_parallel = omp_get_wtime();

    #pragma omp parallel for schedule(static, 4) num_threads(8) private(scalar)
    for (int i = 0; i < n; i++) {
        vector[i] = i + 100.987453323212;
    }

    #pragma omp parallel for schedule(dynamic, 4) num_threads(8) private(scalar)
    for (int i = 0; i < n; i++) {
        vector[i] += scalar;
    }

    double end_time_parallel = omp_get_wtime();

    printf("Parallel Method Time: %f seconds\n", (end_time_parallel - start_time_parallel));

    return 0;
}
