//Actividad 1: Implemente un algoritmo paralelo que permita que todos los procesos pares impriman un saludo.

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	//Procesos pares
	if ( (nombre_proceso % 2) == 0 ){
		printf("Proceso %d de un total de %d\n", nombre_proceso, total_procesos);
	}

	MPI_Finalize();
	return 0;
}