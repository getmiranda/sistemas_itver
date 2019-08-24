//Ejercicio 2: Me identifico con mi ID de proceso.

#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[]) {
	int total_procesos, proceso_actual;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	printf("Hola mundo! Soy el proceso %d, de un total de procesos %d.\n", proceso_actual, total_procesos);

	if (proceso_actual == 0)
	{
		printf("Soy el proceso master. %d", proceso_actual);
	}
	else
	{
		printf("Soy proceso esclavo. %d", proceso_actual);
	}

	MPI_Finalize();
	return 0;
}