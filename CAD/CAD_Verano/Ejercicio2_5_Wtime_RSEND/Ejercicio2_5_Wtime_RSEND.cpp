#include <stdio.h>
#include "mpi.h"

int main(int argc, char* arcv[]) {
	int nombre_proceso, total_procesos, flag = 0, origen, destino;
	//double inicio, termina;
	int valor;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	if (nombre_proceso != 0)
	{
		valor = 1;
		destino = 0;

		MPI_Rsend(&valor, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		printf("Esclavo. Proceso: %d enviando valor %d a master.", nombre_proceso, valor);
	}
	else
	{
		for (int origen = 1; origen < total_procesos; origen++)
		{
			//Inicia el intervalo
			double inicio = MPI_Wtime();
			MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			//Finaliza el intervalo
			double termina = MPI_Wtime();
			printf("Master. Proceso: %d ha recibido el valor %d del proceso %d. Tiempo de proceso: %f\n",
				nombre_proceso, valor, status.MPI_SOURCE, (termina - inicio));
		}

	}

	MPI_Finalize();
	return 0;
}