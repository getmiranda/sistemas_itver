/*	Relizar un programa, que envie un mensaje solamente entre dos procesos,
	simulando el juego de Ping Pong. Agregue un control temporal para poder detenerlos.*/
#include <stdio.h>
#include "mpi.h"

int main(int argc, char* arcv[]) {
	int nombre_proceso, total_procesos, flag = 0, origen, destino;
	//double inicio, termina;
	double tiempo=0, limite = 5;
	int valor = 0;
	MPI_Status status;
	MPI_Request request;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	while (tiempo < limite)
	{
		if (nombre_proceso == 0)
		{
			MPI_Irecv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &request);
			valor++;
			destino = 1;
			//tiempo++;
			//double now = MPI_Wtime();
			//tiempo += now;
			printf("Instante de tiempo: %f", MPI_Wtime());
			MPI_Isend(&valor, 1, MPI_INT, destino, flag, MPI_COMM_WORLD, &request);
			printf("Proceso: %d enviando pelota %d a proceso %d.\n", nombre_proceso, valor, destino);
		}
		if (nombre_proceso == 1)
		{
			MPI_Irecv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &request);
			valor++;
			destino = 0;
			//tiempo++;
			//double now = MPI_Wtime();
			//tiempo += now;
			printf("Instante de tiempo: %f", MPI_Wtime());
			MPI_Isend(&valor, 1, MPI_INT, destino, flag, MPI_COMM_WORLD, &request);
			printf("Proceso: %d enviando pelota %d a proceso %d.\n", nombre_proceso, valor, destino);
		}
	}

	printf("Tempo: %f", tiempo);
	MPI_Finalize();
	return 0;
}