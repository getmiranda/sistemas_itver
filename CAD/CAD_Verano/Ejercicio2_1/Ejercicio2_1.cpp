#include "mpi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, flag = 0, destino, origen;
	int valor_envio, valor_recibo;
	MPI_Status status;

	MPI_Init(NULL,NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	if (nombre_proceso == 0)
	{
		destino = 2;
		valor_envio = 1;
		MPI_Send(&valor_envio, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}
	if (nombre_proceso == 2)
	{
		origen = 0;
		MPI_Recv(&valor_recibo, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf_s("Proceso %d ha recibido del proceso %d el valor %d", nombre_proceso, status.MPI_SOURCE, valor_recibo);
	}

	MPI_Finalize();

	return 0;
}
