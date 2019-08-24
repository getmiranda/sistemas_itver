//Ejercicio 4: Mensaje punto a punto

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

	//Si no soy el proceso 0, enviaré un mesaje al proceso 0
	if (nombre_proceso != 0) 
	{ 
		printf("Proceso %d de un total de %d\n", nombre_proceso, total_procesos); 
		sprintf_s(mensaje, "Saludos desde el proceso %d!", nombre_proceso); 
		destino = 0; 
		
		//Send(mensaje, longitud, tipo, destino, flag, comunicador);
		MPI_Send(mensaje, strlen(mensaje) + 1, MPI_CHAR, destino, flag, MPI_COMM_WORLD); 
	}
	//Pero si soy el 0, entonces recibo los mensajes.
	else
	{
		printf("Proceso 0, Total de procesos = %d \n", total_procesos); 
		for (origen = 1; origen < total_procesos; origen++) {
			MPI_Recv(mensaje, 100, MPI_CHAR, origen, flag, MPI_COMM_WORLD, &status);
			printf("%s\n", mensaje); 
		}

	}
	MPI_Finalize();
	return 0;
}