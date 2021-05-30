// ** 檔名 example_basic.cpp **
// 都會阿嬤 OpenMPI 教學
// 都會阿嬤 https://weikaiwei.com

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int process_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

    //Hello, world
    printf("Hello, world from rank %d/%d\n", process_rank, world_size);

    // Finalize the MPI environment
    MPI_Finalize();
}