//Actividad 3: Implemente un algoritmo que permita que cada proceso par envíe un saludo punto a punto a su consecutivo impar.

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	//mensaje de longitud 100
	char mensaje[100];
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	//Si soy un proceso par envio un mensaje a los impares
	if ((nombre_proceso % 2) == 0)
	{
		printf("Send. Proceso %d de un total de %d\n", nombre_proceso, total_procesos);
		sprintf_s(mensaje, "Saludos desde el proceso %d!\n", nombre_proceso);

		destino = nombre_proceso + 1;

		MPI_Send(mensaje, strlen(mensaje) + 1, MPI_CHAR, destino, flag, MPI_COMM_WORLD);
		
	}
	//Pero si soy proceso impar recibo mensaje
	else
	{
		printf("Recv. Proceso %d, Total de procesos = %d \n", nombre_proceso, total_procesos);
		origen = nombre_proceso - 1;
		
		MPI_Recv(mensaje, 100, MPI_CHAR, origen, flag, MPI_COMM_WORLD, &status);
		printf("%s\n", mensaje);
		

	}
	MPI_Finalize();
	return 0;
}