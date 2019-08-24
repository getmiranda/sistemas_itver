/*	Actividad 2.2: 
	Autor: José Manuel Miranda Villagrán
	*/

#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {

	int total_procesos, proceso_actual, destino, flag = 0;
	int valor1, valor2;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	//Si soy un proceso 0, soy el proceso master
	if (proceso_actual == 0)
	{
		valor1 = 1;
		valor2 = 2;
		destino = 2;

		MPI_Send(&valor1, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		MPI_Send(&valor2, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}

	if (proceso_actual == 2)
	{
		MPI_Recv(&valor1, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Proceso %d ha recibido el valor %d del proceso %d.\n", proceso_actual, valor1, status.MPI_SOURCE);

		MPI_Recv(&valor2, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Proceso %d ha recibido el valor %d del proceso %d.\n", proceso_actual, valor2, status.MPI_SOURCE);
	}
	MPI_Finalize();
	return 0;
}