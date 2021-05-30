// ** 檔名 example_blocking_communication.cpp **
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

    // communication
    int data_send = (process_rank + 1) * 100;
    int data_recv;
    if (process_rank == 0)
    {
        int target_rank = 1;
        //MPI_Send(data, count, datatype, target, tag, communicator)
        MPI_Send(&data_send, 1, MPI_INT, target_rank, 123, MPI_COMM_WORLD);
        // MPI_Recv(data, count, datatype, source, tag, communicator, status)
        MPI_Recv(&data_recv, 1, MPI_INT, target_rank, 123, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
    }
    else if (process_rank == 1)
    {
        int target_rank = 0;
        // MPI_Recv(data, count, datatype, source, tag, communicator, status)
        MPI_Recv(&data_recv, 1, MPI_INT, target_rank, 123, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
        //MPI_Send(data, count, datatype, target, tag, communicator)
        MPI_Send(&data_send, 1, MPI_INT, target_rank, 123, MPI_COMM_WORLD);
    }
    printf("Rank %d : Send %d, Recv %d\n", process_rank, data_send, data_recv);

    // Finalize the MPI environment
    MPI_Finalize();
}