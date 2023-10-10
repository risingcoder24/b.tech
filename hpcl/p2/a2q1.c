// #include <stdio.h>
// #include <omp.h>
 
// #define VECTOR_SIZE 10000
 
// int main() {
//     float vector[VECTOR_SIZE];
//     int scalar = 5;
//     for (int i = 0; i < VECTOR_SIZE; i++) {
//         vector[i] = i + 100.987;
//     }
 
//     double start_time_serial = omp_get_wtime();
//     for (int i = 0; i < VECTOR_SIZE; i++) {
//         vector[i] += scalar;
//     }
 
//     double end_time_serial = omp_get_wtime();
//     printf("Serial Method Time: %f seconds\n", (end_time_serial - start_time_serial));
 
//     for (int i = 0; i < VECTOR_SIZE; i++) {
//         vector[i] = i + 100.987;
//     }
 
//     double start_time_parallel = omp_get_wtime();
 
//     #pragma omp parallel for private(scalar) num_threads(1000)
//         for (int i = 0; i < VECTOR_SIZE; i++) {
//                 vector[i] += scalar;
//             }
//     double end_time_parallel = omp_get_wtime();
//     printf("Parallel Method Time: %f seconds\n", (end_time_parallel - start_time_parallel));
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int main() {
    int totalPoints = 10000000;
    int pointsInsideCircle = 0;
    double x, y;
    printf("Enter the number of terms: ");
    scanf("%d", &totalPoints);
    double start_time_parallel = omp_get_wtime();
    #pragma omp parallel for private(x, y) reduction(+:pointsInsideCircle)
    for (int i = 0; i < totalPoints; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            pointsInsideCircle++;
        }
    }
    double pi = 4.0 * pointsInsideCircle / totalPoints;
    double end_time_parallel = omp_get_wtime();
    printf("Parallel Method Time: %f seconds\n", (end_time_parallel - start_time_parallel));
    printf("Estimated value of pi: %f\n", pi);
    return 0;
}
