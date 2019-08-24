/*  Actividad 4: Desarrolle un algoritmo que envíe un mensaje de proceso en proceso en orden incremental 
	respecto a su Rank y que cada proceso lo firme con su número identificador. Imprima solo el último mensaje. */

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	//mensaje de longitud 100
	char mensaje[100], firma[100];
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	//Si soy un proceso 0, soy el inicial.
	if (nombre_proceso == 0)
	{
		printf("Inicio. Proceso: %d, Total: %d\n", nombre_proceso, total_procesos);
		sprintf_s(mensaje, "Saludos desde el proceso %d! Firmas: ", nombre_proceso);

		destino = nombre_proceso + 1;
		MPI_Send(mensaje, strlen(mensaje) + 1, MPI_CHAR, destino, flag, MPI_COMM_WORLD);
	}
	//Ultimo proceso
	else if(nombre_proceso == (total_procesos - 1)) 
	{
		printf("Ultimo. Proceso: %d, Total: %d \n", nombre_proceso, total_procesos);
		origen = nombre_proceso - 1;
		MPI_Recv(mensaje, 100, MPI_CHAR, origen, flag, MPI_COMM_WORLD, &status);
		sprintf_s(firma, "%d", nombre_proceso);
		strcat_s(mensaje, firma);
		printf("%s\n", mensaje);
	}
	//Pero si soy cualquiera entre el inicio y el final solo, recivo, añado mi ID envio al siguiente respecto a mi rank
	else
	{
		printf("Recv-Send. Proceso: %d Total: %d\n", nombre_proceso, total_procesos);
		origen = nombre_proceso - 1;
		MPI_Recv(mensaje, 100, MPI_CHAR, origen, flag, MPI_COMM_WORLD, &status);
		//Firmo

		sprintf_s(firma, "%d", nombre_proceso);
		strcat_s(mensaje, firma);
		destino = nombre_proceso + 1;
		MPI_Send(mensaje, strlen(mensaje) + 1, MPI_CHAR, destino, flag, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}