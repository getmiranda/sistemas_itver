//Ejercicio 5: Anillo síncrono

#include <stdio.h>
#include "mpi.h"
#include <string.h>

int main(int argc, char* argv[]) {

	int total_procesos, nombre_proceso, origen = 0, destino = 0, flag = 0;
	int ultimo_proceso;
	int pelota = 0;
	MPI_Status status;

	MPI_Init(NULL, NULL);

	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
	MPI_Comm_rank(MPI_COMM_WORLD, &nombre_proceso);
	ultimo_proceso = total_procesos - 1;

	//Si soy el entrenador
	if (nombre_proceso == 0) {

		//Destino
		destino = nombre_proceso + 1;
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Entrenador enviado pelota al jugador %d\n", destino);

		//Origen
		origen = total_procesos - 2;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Entrenador recibe pelota del jugador %d\n", origen);
	}
	//Pase al primer jugador
	else if (nombre_proceso == 1) {

		//Origen
		origen = 0;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Jugador %d recibe pelota del entrenador\n", nombre_proceso);

		//Destino
		destino = (nombre_proceso + 2) % total_procesos;
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Jugador %d enviado pelota al jugador %d\n", nombre_proceso, destino);
		
	}
	//Jugador con el indice mas alto del circulo
	else if (nombre_proceso == (total_procesos - 1)) {

		//Origen
		origen = nombre_proceso - 2;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Jugador %d recibe pelota del jugador %d\n", nombre_proceso, origen);

		//Destino
		destino = (nombre_proceso + 2) % (total_procesos - 1);//se resta el entrenador
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Jugador %d enviado pelota al jugador %d\n", nombre_proceso, destino);
	}
	//Jugador que recibe del jugador con el indice mas alto (2)
	else if (nombre_proceso == 2) {

		origen = (total_procesos - 1) % total_procesos;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Jugador %d recibe pelota del jugador %d\n", nombre_proceso, origen);

		destino = (nombre_proceso + 2) % total_procesos;
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Jugador %d enviado pelota al jugador %d\n", nombre_proceso, destino);
	}

	//El ultimo jugador pasa la pelota al entrenador
	else if (nombre_proceso == (total_procesos - 2)) {

		//Origen
		origen = (nombre_proceso - 2) % total_procesos;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Jugador %d recibe pelota del jugador %d\n", nombre_proceso, origen);

		//Destino
		destino = 0;
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Jugador %d enviado pelota al entrenador.\n", nombre_proceso);

	}
	//Cualquiera de los demas jugadores
	else
	{
		//Origen
		origen = nombre_proceso - 2;
		MPI_Recv(&pelota, 1, MPI_INT, origen, 0, MPI_COMM_WORLD, &status);
		printf("Jugador %d recibe pelota del jugador %d\n", nombre_proceso, origen);

		//Destino
		destino = nombre_proceso + 2;
		MPI_Send(&pelota, 1, MPI_INT, destino, 0, MPI_COMM_WORLD);
		printf("Jugador %d enviado pelota al jugador %d", nombre_proceso, destino);
	}
	
	MPI_Finalize();
	return 0;
}