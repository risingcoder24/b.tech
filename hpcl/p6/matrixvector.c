#include <stdio.h>
#include <time.h>
#define n 500
int main()
{
    clock_t start = clock();
    int vector[n], result[n], matrix[n][n];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            matrix[i][j]=100000.9;

    for (int i = 0; i < n; i++)
        vector[i]=100000.9;
        
    for (int i = 0; i < n; i++) 
    {
        result[i] = 0;
        for (int j = 0; j < n; j++)
            result[i] += matrix[i][j] * vector[j];
    }
    clock_t end=clock();
    double t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nSize of matrix: %d      ",n);
    printf("Time taken: %f\n\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}