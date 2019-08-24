/*	Actividad 2.3:
	Autor: José Manuel Miranda Villagrán
	*/

#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <string>

int main(int argc, char* argv[]) {

	int total_procesos, proceso_actual, destino, flag = 0;
	int scan;
	MPI_Status status;
	time_t segundos1, segundos2;
	char mensaje[1000] = "abcdefghijklmnñopqrstuvwxyz";
	//char c;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);

	//Si soy un proceso 0, soy el proceso master
	if (proceso_actual == 0)
	{
		destino = 2;
		segundos1 = time(NULL);
		//scanf_s("%d", scan);
		printf("Timer antes de enviar mensaje desde el proceso 0: %g\n", segundos1);
		MPI_Ssend(mensaje, strlen(mensaje), MPI_CHAR, destino, flag, MPI_COMM_WORLD);
		segundos2 = time(NULL);
		printf("Timer despues de enviar mensaje desde el proceso 0: %g\n", segundos2);
	}

	if (proceso_actual == 2)
	{
		MPI_Recv(mensaje, strlen(mensaje), MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Proceso %d ha recibido el valor %s del proceso %d.\n", proceso_actual, mensaje, status.MPI_SOURCE);
	}

	MPI_Finalize();
	return 0;
}