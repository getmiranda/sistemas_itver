// Ejercicio 1: Hola mundo desde MPI

#include "pch.h"
#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[])
{
	int proceso_actual, total_procesos;

	MPI_Init(&argc, &argv);
	/*Comm: comunicador, en &total_procesos almacena el numero de 
	  procesos del comunicador que se le pasa */
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	printf("Hola mundo! Soy el proceso numero: %d de un total de %d procesos.\n", proceso_actual, total_procesos);

	MPI_Finalize();
	return 0;
}