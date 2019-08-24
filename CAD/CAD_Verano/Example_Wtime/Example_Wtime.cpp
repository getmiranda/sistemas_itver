#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv) {
	int size, rank, valor1, valor2;
	MPI_Status status;
	double inicio, fin;

	// Initialize the MPI environment
	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		for (int i = 1; i < size; i++) {
			MPI_Recv(&valor1, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);

			printf("Proceso %d envio %d\n",status.MPI_SOURCE,valor1);

		}
	}
	if (rank != 0)
	{
		valor1 = 10 + rank;
		inicio = MPI_Wtime();
		MPI_Rsend(&valor1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		fin = MPI_Wtime();
		printf("Tiempo del proceso %d es %f\n", rank, fin - inicio);
	}
	MPI_Finalize();
	return 0;
}