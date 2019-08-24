/*  Actividad 6: Programe un algoritmo que determine un proceso maestro que genere un numero aleatorio 
	entre 1 y 10; y lo env�e a sus procesos trabajadores para que calculen el factorial de dicho n�mero 
	y lo impriman localmente. 
	
	Autor: Jos� Manuel Miranda Villagr�n
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
	//printf("Factorial de %d es: %d\n\n", n, fact);
	return fact;
}

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	int number_random, max_factorial = 10;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	//Si soy un proceso 0, soy el proceso master
	if (nombre_proceso == 0)
	{
		printf("Master. Proceso: %d, Total: %d\n\n", nombre_proceso, total_procesos);
		for ( destino = 1; destino < total_procesos; destino++)
		{
			//Genero mensaje aleatorio.
			number_random = rand() % max_factorial + 1;
			MPI_Send(&number_random, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		}

	}
	//Si soy proceso esclavo calculo factorial del numero que me envi� e master.
	else
	{
		origen = 0;
		MPI_Recv(&number_random, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf("Esclavo. Proceso: %d Total: %d. Numero recibido: %d\n", nombre_proceso, total_procesos, number_random);
		printf("Factorial de %d es: %d\n\n", number_random, factorial(number_random));
	}
	MPI_Finalize();
	return 0;
}