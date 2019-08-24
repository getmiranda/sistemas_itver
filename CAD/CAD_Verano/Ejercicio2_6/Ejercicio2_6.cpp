#include <stdio.h>
#include "mpi.h"

int main(int argc, char* arcv[]) {
	int nombre_proceso, total_procesos, flag = 0, destino;
	int valor1, valor2;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	valor1 = 10;
	valor2 = 20;

	if (nombre_proceso%2 == 0)
	{
		destino = nombre_proceso + 1;

		MPI_Send(&valor1, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		MPI_Recv(&valor1, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Proceso: %d Envia: %d \n", status.MPI_SOURCE, valor1);
	}
	if (nombre_proceso % 2 == 1)
	{
		destino = nombre_proceso - 1;

		MPI_Recv(&valor2, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Proceso: %d Envia: %d\n", status.MPI_SOURCE, valor2);
		MPI_Send(&valor2, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	} 

	MPI_Finalize();
	return 0;
}