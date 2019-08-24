/*	Examen Unidad 2 - Ejercicio 1: Entrenamiento basico de Futbool
	Autor: José Manuel Miranda Villagrán */
/*
#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"

int main(int argc, char* arcv[]) {
	int nombre_proceso, total_procesos, flag = 0, destino, origen;
	int pelota;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	pelota = 1;
	destino = (nombre_proceso + 1) % total_procesos;
	origen = (nombre_proceso + total_procesos - 1) % total_procesos;

	//Soy el entrenador, proceso 0
	if (nombre_proceso == 0)
	{

		//MPI_Recv(&pelota, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		MPI_Send(&pelota, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		printf("Entrenador comienza a tocar hacia jugador %d\n", destino);
	}

	do {
		//Recibo la pelota...
		MPI_Recv(&pelota, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Entrenador ha recibido la pelota del proceso %d\n", status.MPI_SOURCE);

		//Envio la pelota
		MPI_Send(&pelota, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
		printf("Entrenador envia pelota al jugardor %d\n", destino);
		if (nombre_proceso == 0)
		{
			total_procesos--;
		}
		

	} while (total_procesos > 0);

	//Si soy un jugador, envio la pelota al entrenador
	if (nombre_proceso == 0)
	{
		MPI_Recv(&pelota, 1, MPI_INT, MPI_ANY_SOURCE, flag, MPI_COMM_WORLD, &status);
		printf("Entrenador envia pelota al jugardor %d\n", destino);
	}

	MPI_Finalize();
	return 0;
}
//Ejercicio 5: Anillo síncrono

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen, destino, flag = 0;
	int n_vueltas;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);

	destino = (nombre_proceso + 1) % total_procesos;
	origen = (nombre_proceso + total_procesos - 1) % total_procesos;

	//preguntamos las vueltas
	if (nombre_proceso == 0) {

		n_vueltas = 1;
		printf("Proceso %d enviando pelota al proceso %d\n", nombre_proceso, destino);
		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
	}
	do {
		MPI_Recv(&n_vueltas, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);

		printf("Proceso %d ha recibido pelota del proceso %d\n", nombre_proceso, origen);
		if (nombre_proceso == 0)
		{
			n_vueltas--;
		}

		printf("Proceso %d enviando pelota al proceso %d\n", nombre_proceso, destino);

		MPI_Send(&n_vueltas, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);

	} while (n_vueltas > 0);

	if (nombre_proceso == 0) {
		MPI_Recv(&n_vueltas, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
		printf("Proceso %d ha recibido pelota del proceso % d\n", nombre_proceso, origen);
	}
	printf("Proceso %d ha finalizado!!\n", nombre_proceso);

	MPI_Finalize();
	return 0;
}*/
//#include <stdio.h>
//#include "mpi.h"
//
//int main(int argc, char* arcv[]) {
//	int nombre_proceso, total_procesos, flag = 0, origen, destino;
//	//double inicio, termina;
//	int valor = 0;
//	MPI_Status status;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	if (nombre_proceso == 0)
//	{
//		for (destino = 1; destino < total_procesos; destino++)
//		{
//			MPI_Send(&valor, 1, MPI_INT, destino, flag, MPI_COMM_WORLD);
//			printf("Proceso %d ha enviado pelota al proceso %d\n", nombre_proceso, destino);
//		}
//	}
//
//	if (nombre_proceso != 0)
//	{
//		for (int i = 1; i < total_procesos; i++)
//		{
//			MPI_Recv(&valor, 1, MPI_INT, 0, flag, MPI_COMM_WORLD, &status);
//			MPI_Send(&valor, 1, MPI_INT, 0, flag, MPI_COMM_WORLD);
//			printf("Proceso: %d enviando pelota a proceso %d.\n", nombre_proceso, 0);
//		}
//		
//	}
//	if(nombre_proceso == 0)
//	{
//		for (origen = 1; origen < total_procesos; origen++)
//		{
//			MPI_Recv(&valor, 1, MPI_INT, origen, flag, MPI_COMM_WORLD, &status);
//			printf("Proceso %d ha recibido pelota del proceso % d\n", nombre_proceso, origen);
//		}
//	}
//
//	//printf("Tempo: %f", tiempo);
//	MPI_Finalize();
//	return 0;
//}

#include <stdio.h>
#include "mpi.h"

int main(int argc, char* arcv[]) {
	int nombre_proceso, total_procesos, flag = 0;
	//double inicio, termina;
	//double tiempo = 0, limite = 5;
	int valor = 0;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);

	if (nombre_proceso == 0) {
		for (int x = 1; x < total_procesos; x++) {
			valor = nombre_proceso;
			MPI_Send(&valor, 1, MPI_INT, x, flag, MPI_COMM_WORLD);
			printf("El entrenador envio el balon al jugador %d\n", x);

			MPI_Recv(&valor, 1, MPI_INT, x, flag, MPI_COMM_WORLD, &status);
			printf("El entrenador recibio el balon al jugador %d\n", x);
		}
	}
	else {
		MPI_Recv(&valor, 1, MPI_INT, 0, flag, MPI_COMM_WORLD, &status);
		printf("El jugador %d , recibio el balon del entrenador y se lo regresa \n", nombre_proceso);
		MPI_Send(&valor, 1, MPI_INT, 0, flag, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}