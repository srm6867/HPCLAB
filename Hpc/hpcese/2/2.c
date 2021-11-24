#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void print(int size, int rank, int n, int* data) {
    printf("Rank %d\n", rank);
    for (int j = 0; j < size * n; j++)
        printf("%d ", data[j]);
    printf("\n");
}

int main(int argc, char** argv) {
   

    MPI_Init(&argc, &argv);
    const int n = 2;
    int rank, size;
    //int* a, * b;
     MPI_Comm_size(MPI_COMM_WORLD, &size);
     MPI_Comm_rank(MPI_COMM_WORLD, &rank);

   int* a = (int*)malloc(n * size * sizeof(int));
   int* b = (int*)malloc(n * size * sizeof(int));
    for (int i = 0; i < n * size; i++)
        a[i] = 4;
    for (int i = 0; i < n; i++)
        a[rank * n + i] = rank;

    if (rank == 0) printf("Before:\n");
    print(size, rank, n, a);

    
    MPI_Allgather(&(a[rank * n]), n, MPI_INT, b, n, MPI_INT, MPI_COMM_WORLD);

    if (rank == 0) printf("After:\n");
    print(size, rank, n, b);

    free(a);
    free(b);
    MPI_Finalize();
    return 0;
}
