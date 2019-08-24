/*	Actividad 2. : Recepcion se realiza sin orden con SEND.
	Autor: José Manuel Miranda Villagrán
	*/

#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {

	int total_procesos, proceso_actual, destino, flag = 0;
	int valor;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	//Todos los que no son el proceseo 0 (master) enviar un mensaje al master.
	if (proceso_actual != 0)
	{
		valor = 1;
		destino = 0;

		MPI_Send(&valor, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		printf("Esclavo. Proceso: %d enviando valor %d a master.", proceso_actual, valor);
	}
	else
	{
		for (int origen = 1; origen < total_procesos; origen++)
		{
			MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			printf("Master. Proceso: %d ha recibido el valor %d del proceso %d.\n", proceso_actual, valor, status.MPI_SOURCE);
		}

	}

	MPI_Finalize();
	return 0;
}