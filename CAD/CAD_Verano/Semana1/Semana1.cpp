// Ejercicio 0: Mi programa básico en MPI

#include "pch.h"
#include <iostream>
#include "mpi.h"

int main(int argc, char* argv[])
{
	int this_proc, total_procesos;

	/* MPI_Init señala el inicio de MPI y define lo que conoceremos con el MPI_COMM_WORLD.
	   En los argumentos puede ir null, null */
	MPI_Init(&argc, &argv);
	// Aquí no sucede nada aún.
	MPI_Finalize();
	return 0;
}