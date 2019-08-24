//Ejercicio 3: Número maximo de procesadores en el dispositivo

#include <stdio.h>
#include "mpi.h"

int main(int argc, char* argv[]) {
	MPI_Init(NULL, NULL);

	int total_procesos, proceso_actual;

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	//Arreglo de caracteres de tamaño "Numero maximo de nombre de procesador"
	char nombre_procesador[MPI_MAX_PROCESSOR_NAME];
	int longitud_nombre;

	MPI_Get_processor_name(nombre_procesador, &longitud_nombre);

	printf("Hola mundo desde el procesador: %s con ID %d de un total de procesadores %d", nombre_procesador, proceso_actual, total_procesos);

	MPI_Finalize();
}