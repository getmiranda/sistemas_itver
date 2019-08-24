//Ejercicio 6: Recorrido en orden incrementando un valor

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

	if (nombre_proceso == 0)
	{
		printf("Introdice el número de vueltas: ");
		//scanf_s("%d", &n_vueltas);
		n_vueltas = 3;
		printf("Proceso origen: %d Proceso destino: %d Valor envio: %d\n", nombre_proceso, destino, n_vueltas);
		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}

	do
	{
		MPI_Recv(&n_vueltas, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf("Proceso destino: %d Proceso origen: %d Valor envio: %d\n", nombre_proceso, origen, n_vueltas);

		if (nombre_proceso == 0)
		{
			--n_vueltas;
		}
		printf("Proceso %d enviando valor %d al proceso %d\n", nombre_proceso, n_vueltas, destino);
		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);

	} while (n_vueltas > 0);

	if (nombre_proceso == 0)
	{
		MPI_Recv(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD, &status);
		printf("El proceso %d ha recibido el valor %d del proceso %d\n", nombre_proceso, n_vueltas, origen);
	}
	printf("El proceso %d ha finalizado", nombre_proceso);
	MPI_Finalize();
	return 0;
}