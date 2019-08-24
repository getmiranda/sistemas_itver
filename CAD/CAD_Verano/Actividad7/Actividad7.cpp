/*	Actividad 7: Modifique el programa de la actividad 6, para que los trabajadores 
	regresen el resultado del factorial al nodo maestro y éste los imprima. 
	Autor: José Manuel Miranda Villagrán
	*/


#include <stdio.h>
#include "mpi.h"
#include <string.h>
#include <stdlib.h>

int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	return fact;
}

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	int number_random, max_factorial = 10, fact;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	//Si soy un proceso 0, soy el proceso master
	if (nombre_proceso == 0)
	{
		printf("Master. Proceso: %d, Total: %d\n\n", nombre_proceso, total_procesos);
		for (destino = 1; destino < total_procesos; destino++)
		{
			//Genero mensaje aleatorio.
			number_random = rand() % max_factorial + 1;
			//Send
			MPI_Send(&number_random, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		}


	}
	//Si soy proceso esclavo calculo factorial del numero que me envió e master.
	else
	{
		origen = 0;
		MPI_Recv(&number_random, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf("Esclavo. Proceso: %d Total: %d. Numero recibido: %d\n", nombre_proceso, total_procesos, number_random);
		fact = factorial(number_random);
		//printf("Factorial local de %d es: %d\n", number_random, fact);
		destino = 0;
		MPI_Send(&fact, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}

	if (nombre_proceso == 0)
	{
		for (origen = 1; origen < total_procesos; origen++)
		{
			MPI_Recv(&fact, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
			printf("Master %d ha recibido el valor %d del proceso %d.\n", nombre_proceso, fact, origen);
		}
		
	}
	MPI_Finalize();
	return 0;
}