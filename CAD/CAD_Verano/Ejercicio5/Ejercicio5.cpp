//Ejercicio 5: Anillo síncrono

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	int n_vueltas;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	destino = (nombre_proceso + 1) % total_procesos;
	origen = (nombre_proceso + total_procesos - 1) % total_procesos;

	//preguntamos las vueltas
	if (nombre_proceso == 0) {

		n_vueltas = 1;
		printf("Proceso %d enviando valor %d al proceso	% d\n", nombre_proceso, n_vueltas, destino);
		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}
	do {
		MPI_Recv(&n_vueltas, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);

		printf("Proceso %d ha recibido el valor %d del proceso % d\n", nombre_proceso, n_vueltas, origen);
			if (nombre_proceso == 0) {
				--n_vueltas;
			}
		printf("Proceso %d enviando valor %d al proceso %d\n",nombre_proceso, n_vueltas, destino);

		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);

	} while (n_vueltas > 0);

	if (nombre_proceso == 0) {
		MPI_Recv(&n_vueltas, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf("Proceso %d ha recibido el valor %d del proceso % d\n", nombre_proceso, n_vueltas, origen);
	}
	printf("Proceso %d ha finalizado!!", nombre_proceso);

	MPI_Finalize();
	return 0;
}