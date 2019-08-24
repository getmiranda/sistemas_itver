//#include "mpi.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(int argc, char* arcv[]) {
//
//	int proceso_actual;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//
//	if (proceso_actual % 2 == 0)
//	{
//		printf("Proceso %d: par", proceso_actual);
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

//#include "mpi.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(int argc, char* arcv[]) {
//
//	int proceso_actual, size;
//	int mensaje = 1;
//	MPI_Status status;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	//Par
//	if (proceso_actual % 2 == 0)
//	{
//		MPI_Send(&mensaje, 1, MPI_INT, proceso_actual + 1, 0, MPI_COMM_WORLD);
//		printf("Proceso %d -> Proceso %d", proceso_actual, proceso_actual + 1);
//	}
//	//Impar
//	if (proceso_actual % 2 == 1)
//	{
//		MPI_Recv(&mensaje, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
//		printf("Proceso %d <- Proceso %d", proceso_actual, status.MPI_SOURCE);
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

//#include "mpi.h"
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(int argc, char* arcv[]) {
//
//	int proceso_actual, size, destino;
//	int mensaje = 1;
//	MPI_Status status;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//	//Par
//	if (proceso_actual % 2 == 0)
//	{
//		for (size_t i = 1; i < size; i+=2)
//		{
//			MPI_Send(&mensaje, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
//			printf("Proceso %d -> Proceso %d\n", proceso_actual, i);
//		}
//	}
//	//Impar
//	if (proceso_actual % 2 == 1)
//	{
//		for (size_t i = 0; i < size/2; i++)
//		{
//			MPI_Recv(&mensaje, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
//			printf("Proceso %d <- Proceso %d\n", proceso_actual, status.MPI_SOURCE);
//		}
//		
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

// Los multiplo de tres van a enviar un mensaje al siguiente numero no multiplo de tres
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "mpi.h"
//#include "package.h"
//
//
//int main(int argc, char* []) {
//
//	int size, rank;
//	int origen_p, destino_p;
//	int tag = TOKEN;
//	struct pack paquete = {1, 0, "xxxxxx"};
//
//	MPI_Status status;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	destino_p = (rank + 1) % size;
//	origen_p = (rank + size - 1) % size;
//
//	//Proceso que inicia el anillo 
//	if (rank == MASTER)
//	{
//		printf("%d", tag);
//		//Si el tag es token(no soy el destino)
//		if (tag == TOKEN)
//		{
//			//¿Soy el origen?
//			if (rank == paquete.origen)
//			{
//				tag = DATA;
//				sprintf_s(paquete.contenido, "Origen: %d Destino: %d Contenido del paquete: %s ", paquete.origen, paquete.destino, "Hola");
//
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d inicia el anillo\n", rank);
//				printf("Proceso %d -> Proceso %d ENVIA\n", rank, destino_p);
//			}
//			//Si no lo soy solo transmito
//			else
//			{
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d inicia el anillo\n", rank);
//				printf("Proceso %d -> Proceso %d\n", rank, destino_p);
//			}
//		}
//		//Si el tag es data
//		else
//		{
//			//¿Soy el destino?
//			if (rank == 0)
//			{
//				printf("Paquete: Origen: %d\n\t Destino: %d\n\t Dato: %s\n", paquete.origen, paquete.destino, paquete.contenido);
//				tag = TOKEN;
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d NO\n", rank, destino_p);
//			}
//			//Si no lo soy
//			else
//			{
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d NO SOY DESTINO\n", rank, destino_p);
//			}
//
//		}
//		
//		MPI_Recv(&paquete, 1, MPI_INT, origen_p, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
//		tag = status.MPI_TAG;
//		printf("Proceso %d <- Proceso %d\n", rank, origen_p);
//
//		//Si el tag es data
//		if(tag == DATA)
//		{
//			//¿Soy el destino?
//			if (rank == paquete.destino)
//			{
//				printf("Paquete: Origen: %d\n\t Destino: %d\n\t Dato: %s\n", paquete.origen, paquete.destino, paquete.contenido);
//				tag = TOKEN;
//				
//			}
//
//		}
//
//	}
//	else
//	{
//		MPI_Recv(&paquete, 1, MPI_INT, origen_p, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
//		tag = status.MPI_TAG;
//		printf("Proceso %d <- Proceso %d TAG: %d\n", rank, origen_p, tag);
//
//		//Si el tag es token
//		if (tag == TOKEN)
//		{
//			//¿Soy el origen?
//			if (rank == paquete.origen)
//			{
//				tag = DATA;
//				sprintf_s(paquete.contenido, "Origen: %d Destino: %d Contenido del paquete: %s ", paquete.origen, paquete.destino, "Hola");
//
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d ENVIA\n", rank, destino_p);
//			}
//			//Si no lo soy solo transmito
//			else
//			{
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d\n", rank, destino_p);
//			}
//		}
//		//Si el tag es data
//		else
//		{
//			//¿Soy el destino?
//			if (rank == paquete.destino)
//			{
//				printf("Paquete: Origen: %d\n\t Destino: %d\n\t Dato: %s\n", paquete.origen, paquete.destino, paquete.contenido);
//				tag = TOKEN;
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d\n", rank, destino_p);
//			}
//			//Si no lo soy
//			else
//			{
//				tag = DATA;
//				MPI_Send(&paquete, 1, MPI_INT, destino_p, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d\n", rank, destino_p, tag);
//			}
//
//		}
//
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos, tag = 0;
//	int destino = 0;
//	char valor[50];
//	struct pack paquete = { 
//		1,			//Origen 
//		3,			//Destino
//		"Hola!"};	//Contenido
//
//	MPI_Status status;
//
//	if (paquete.origen == 0)
//	{
//		tag = DATA;
//	}
//	else
//	{
//		tag = TOKEN;
//	}
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	if (proceso_actual == MASTER) {
//
//		//Hace el recorrido de los procesos
//		for (destino = 1; destino < total_procesos; destino++) {
//
//			//Si es TOKEN, el paquete simula ir vacio.
//			if (tag == TOKEN)
//			{
//				tag = TOKEN;
//				MPI_Send(&paquete, 1, MPI_INT, destino, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d VACIO\n", proceso_actual, destino, tag);
//			}
//			//Si es DATA, el paquete simula ir ocupado.
//			else // (tag == DATA)
//			{
//				tag = DATA;
//				MPI_Send(&paquete, 1, MPI_INT, destino, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d OCUPADO\n", proceso_actual, destino, tag);
//			}
//
//			//Cuando el MASTER recibe
//			MPI_Recv(&paquete, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
//			tag = status.MPI_TAG;
//			if (tag == TOKEN)
//			{
//				printf("Proceso %d <- Proceso %d TAG: %d VACIO\n", proceso_actual, status.MPI_SOURCE, tag);
//			}
//			else
//			{
//				printf("Proceso %d <- Proceso %d TAG: %d OCUPADO\n", proceso_actual, status.MPI_SOURCE, tag);
//			}
//			
//		}
//	}
//	//Si no soy el master
//	else {
//		MPI_Recv(&paquete, 1, MPI_INT, MASTER, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
//		tag = status.MPI_TAG;
//		printf("Proceso %d <- Proceso %d TAG: %d NO MASTER\n", proceso_actual, MASTER, tag);
//
//		//Si es TOKEN, el paquete simula ir vacio.
//		if (tag == TOKEN)
//		{
//			//Si soy el origen, pongo mi contenido en el paquete y cambio el tag a DATA, simulando estar ocupado.
//			if (proceso_actual == paquete.origen)
//			{
//				sprintf_s(valor, "Hola desde el proceso %d\n ", proceso_actual);
//				strcpy_s(paquete.contenido, valor);
//				tag = DATA;
//
//				MPI_Send(&paquete, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d ENVIA A MASTER CON CONTENIDO\n", proceso_actual, MASTER, tag);
//			}
//			//Si no lo soy solo transmito
//			else
//			{
//				tag = TOKEN;
//				MPI_Send(&paquete, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d VACIO\n", proceso_actual, MASTER, tag);
//			}
//		}
//
//		//Si es DATA, el paquete simula ir ocupado.
//		else
//		{
//			//Si soy el destino, imprime el paquete y cambie el tag a TOKEN, simulando estar vacio de nuevo
//			if (proceso_actual == paquete.destino)
//			{
//				printf("Paquete: Origen: %d\n\t Destino: %d\n\t Contenido: %s\n", paquete.origen, paquete.destino, paquete.contenido);
//				tag = TOKEN;
//				MPI_Send(&paquete, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d VACIO\n", proceso_actual, MASTER, tag);
//			}
//			//Si no soy el destino, solo transmito
//			else
//			{
//				tag = DATA;
//				MPI_Send(&paquete, 1, MPI_INT, MASTER, tag, MPI_COMM_WORLD);
//				printf("Proceso %d -> Proceso %d TAG: %d OCUPADO\n", proceso_actual, MASTER, tag);
//			}
//		}
//	}
//
//	MPI_Finalize();
//	return 0;
//}


////Broadcast
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int destino = 0;
//	char msj[50] = "Hola";
//	MPI_Status status;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	if (proceso_actual == MASTER) {
//		sprintf_s(msj, "Hola desde %d", MASTER);
//	}
//
//	MPI_Bcast(msj, 50, MPI_CHAR, MASTER, MPI_COMM_WORLD);
//	printf("Proceso %d Mensaje: %s\n", proceso_actual, msj);
//
//
//	MPI_Finalize();
//	return 0;
//}

////Scatter
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int sendBuf[8];
//	int longitud = sizeof(sendBuf) / 4;
//	int recvBuf[2];
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//	if (proceso_actual == MASTER) {
//		
//		for (int i = 0; i < longitud; i++)
//		{
//			sendBuf[i] = 10 * i;
//		}
//	}
//	//Envio 2 enteros
//	MPI_Scatter(sendBuf, 2, MPI_INT, recvBuf, 2, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso %d Mensaje: %d %d \n", proceso_actual, recvBuf[0], recvBuf[1]);
//
//	MPI_Finalize();
//	return 0;
//}

////Scatter
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int sendBuf[4];
//	int longitud = sizeof(sendBuf) / 4;
//	int recvBuf;
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < longitud; i++)
//		{
//			sendBuf[i] = 10 * i;
//		}
//	}
//	MPI_Scatter(sendBuf, 1, MPI_INT, &recvBuf, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso %d Mensaje: %d\n", proceso_actual, recvBuf);
//
//	recvBuf *= 2;
//
//	MPI_Gather(&recvBuf, 1, MPI_INT, sendBuf, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	MPI_Finalize();
//	return 0;
//}

////Scatter
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include<time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int sendBuf[4];
//	int sendBufRes[4];
//	int recvBuf;
//	srand(time(NULL));
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER, lleno la matriz con valore aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < sizeof(sendBuf) / 4; i++)
//		{
//			sendBuf[i] = rand() % 11;
//			printf("sendBuf[%d] -> %d\n", i, sendBuf[i]);
//		}
//	}
//
//	MPI_Scatter(sendBuf, 1, MPI_INT, &recvBuf, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Dato recibido: %d\n", proceso_actual, recvBuf);
//
//	recvBuf = factorial(recvBuf);
//
//	MPI_Gather(&recvBuf, 1, MPI_INT, sendBufRes, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Dato enviado: %d\n", proceso_actual, recvBuf);
//
//	//Soy MASTER, lleno la matriz con valore aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < sizeof(sendBufRes) / 4; i++)
//		{
//			printf("sendBufRes[%d] -> %d\n", i, sendBufRes[i]);
//		}
//	}
//
//	MPI_Finalize();
//	return 0;
//}

////Scatterv; sin el gatter
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include<time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int sendBuf[ELEMENTS][ELEMENTS];
//	int sendBufRes[ELEMENTS];
//	int recvBuf[6];
//	int sendCounts[ELEMENTS];
//	int displs[ELEMENTS];
//	int recvCount = 6;
//	int total_elementos = ELEMENTS * ELEMENTS;
//	srand(time(NULL));
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER, lleno la matriz con valore aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < sizeof(sendBuf) / 16; i++)
//		{
//			for (int j = 0; j < sizeof(sendBuf) / 16; j++)
//			{
//				sendBuf[i][j] = 1 + rand() % 10;
//				printf("sendBuf[%d][%d] -> %d\n", i, j, sendBuf[i][j]);
//			}
//
//			//int n = 1 + rand() % (total_elementos - total_procesos);
//			/*sendCounts[i] = n;*/
//			//total_elementos -= n;
//			
//		}
//		//Lleno lo que le toca a cada proceso
//		sendCounts[0] = 2;
//		sendCounts[1] = 4;
//		sendCounts[2] = 6;
//		sendCounts[3] = 4;
//
//		displs[0] = 0;
//		displs[1] = 2;
//		displs[2] = 6;
//		displs[3] = 12;
//	}
//
//	MPI_Scatterv(sendBuf, sendCounts, displs, MPI_INT, recvBuf, recvCount, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d, %d, %d,}\n", proceso_actual, recvBuf[0], recvBuf[1], recvBuf[2], recvBuf[3], recvBuf[4], recvBuf[5]);
//
//	for (int i = 0; i < sendCounts[proceso_actual]; i++)
//	{
//		recvBuf[i] = factorial(recvBuf[i]);
//	}
//
//	MPI_Gather(recvBuf, 1, MPI_INT, sendBufRes, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d, %d, %d,}\n", proceso_actual, recvBuf[0], recvBuf[1], recvBuf[2], recvBuf[3], recvBuf[4], recvBuf[5]);
//
//
//	MPI_Finalize();
//	return 0;
//}

////Scatterv y gatterv
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include<time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int matrix[ELEMENTS][ELEMENTS];
//	int sendBufRes[ELEMENTS][ELEMENTS];
//	int recvBuf[6] = { 0,0,0,0,0,0 };
//	int recvBufRes[6] = { 0,0,0,0,0,0 };
//	int sendCounts[ELEMENTS] = {0,0,0,0};
//	int displs[ELEMENTS];
//	int recvCount = 6, sendCount = 6;
//	int total_elementos = ELEMENTS * ELEMENTS;
//	srand(time(NULL));
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Lleno lo que le toca a cada proceso
//	sendCounts[0] = 2;
//	sendCounts[1] = 4;
//	sendCounts[2] = 6;
//	sendCounts[3] = 4;
//
//	displs[0] = 0;
//	displs[1] = 2;
//	displs[2] = 6;
//	displs[3] = 12;
//
//	//Soy MASTER, lleno la matriz con valores aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < ELEMENTS; i++)
//		{
//			for (int j = 0; j < ELEMENTS; j++)
//			{
//				matrix[i][j] = 1 + rand() % 10;
//				printf("sendBuf[%d][%d] -> %d\n", i, j, matrix[i][j]);
//			}
//
//			//int n = 1 + rand() % (total_elementos - total_procesos);
//			/*sendCounts[i] = n;*/
//			//total_elementos -= n;
//
//		}
//		//Lleno lo que le toca a cada proceso
//		sendCounts[0] = 2;
//		sendCounts[1] = 4;
//		sendCounts[2] = 6;
//		sendCounts[3] = 4;
//
//		displs[0] = 0;
//		displs[1] = 2;
//		displs[2] = 6;
//		displs[3] = 12;
//	}
//
//	MPI_Scatterv(&matrix, sendCounts, displs, MPI_INT, recvBuf, recvCount, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d, %d, %d,}\n", proceso_actual, recvBuf[0], recvBuf[1], recvBuf[2], recvBuf[3], recvBuf[4], recvBuf[5]);
//
//	for (int i = 0; i < sendCounts[proceso_actual]; i++)
//	{
//		//Vector
//		recvBufRes[i] = factorial(recvBuf[i]);
//		printf("%d\n", sendCounts[i]);
//	}
//
//	//MPI_Gatherv(recvBufRes, sendCounts[proceso_actual], MPI_INT, &sendBufRes, sendCounts, displs, MPI_INT, MASTER, MPI_COMM_WORLD);
//	//printf("Proceso: %d Arreglo resultad -> {%d, %d, %d, %d, %d, %d,}\n", proceso_actual, recvBufRes[0], recvBufRes[1], recvBufRes[2], recvBufRes[3], recvBufRes[4], recvBufRes[5]);
//
//	//for (int i = 0; i < ELEMENTS; i++)
//	//{
//	//	for (int j = 0; j < ELEMENTS; j++)
//	//	{
//	//		printf("sendBufRes[%d][%d] -> %d\n", i, j, sendBufRes[i][j]);
//	//	}
//	//}
//
//	MPI_Finalize();
//	return 0;
//}


////Reduce
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include<time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int recvBuf[10] = {0,0,0,0,0,0,0,0,0,0};
//	int data[ELEMENTS][ELEMENTS];
//	int suma[ELEMENTS];
//	int sendCounts[ELEMENTS];
//	int displs[ELEMENTS];
//	srand(time(NULL));
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER, lleno la matriz con valore aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < ELEMENTS; i++)
//		{
//			for (int j = 0; j < ELEMENTS; j++)
//			{
//				data[i][j] = 1 + rand() % 10;
//				printf("sendBuf[%d][%d] -> %d\n", i, j, data[i][j]);
//			}
//
//		}
//		//Lleno lo que le toca a cada proceso
//		sendCounts[0] = 4;
//		sendCounts[1] = 4;
//		sendCounts[2] = 4;
//		sendCounts[3] = 4;
//
//		displs[0] = 0;
//		displs[1] = 4;
//		displs[2] = 8;
//		displs[3] = 12;
//
//		
//	}
//	fflush(stdout);
//	MPI_Scatterv(&data, sendCounts, displs, MPI_INT, recvBuf, 4, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d}\n", proceso_actual, recvBuf[0], recvBuf[1], recvBuf[2], recvBuf[3]);
//
//	//for (int i = 0; i < sendCounts[total_procesos]; i++)
//	//{
//	//	//Vector
//	//	recvBuf[i] = factorial(recvBuf[i]);
//	//	printf("Proceso: %d Dato: %d", proceso_actual, recvBuf[i]);
//	//}
//
//	MPI_Reduce(recvBuf, suma, ELEMENTS, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
//
//	if (proceso_actual == MASTER)
//	{
//		printf("Suma -> {%d, %d, %d, %d}", suma[0], suma[1], suma[2], suma[3]);
//	}
//
//	MPI_Finalize();
//	return 0;
//}

////Scann
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include<time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//	int recvBuf[10] = { 0,0,0,0,0,0,0,0,0,0 };
//	int data[ELEMENTS][ELEMENTS];
//	int suma[ELEMENTS];
//	int sendCounts[ELEMENTS];
//	int displs[ELEMENTS];
//	srand(time(NULL));
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER, lleno la matriz con valore aleatorios
//	if (proceso_actual == MASTER) {
//
//		for (int i = 0; i < ELEMENTS; i++)
//		{
//			for (int j = 0; j < ELEMENTS; j++)
//			{
//				data[i][j] = 1 + rand() % 10;
//				printf("sendBuf[%d][%d] -> %d\n", i, j, data[i][j]);
//			}
//
//		}
//		//Lleno lo que le toca a cada proceso
//		sendCounts[0] = 4;
//		sendCounts[1] = 4;
//		sendCounts[2] = 4;
//		sendCounts[3] = 4;
//
//		displs[0] = 0;
//		displs[1] = 4;
//		displs[2] = 8;
//		displs[3] = 12;
//
//
//	}
//	fflush(stdout);
//	MPI_Scatterv(&data, sendCounts, displs, MPI_INT, recvBuf, 4, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d}\n", proceso_actual, recvBuf[0], recvBuf[1], recvBuf[2], recvBuf[3]);
//
//
//	MPI_Reduce(recvBuf, suma, ELEMENTS, MPI_INT, MPI_SUM, MASTER, MPI_COMM_WORLD);
//
//	MPI_Scan(recvBuf, suma, ELEMENTS, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
//
//	printf("SumaScan en %d -> {%d, %d, %d, %d}", proceso_actual, suma[0], suma[1], suma[2], suma[3]);
//
//
//	MPI_Finalize();
//	return 0;
//}

////Multiplicacion de matrices, el numero de columnas de A debe ser igual al num de filas de B
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//
//	int matrix[ELEMENTS][ELEMENTS];
//	int vector[ELEMENTS];
//	int vector_res[ELEMENTS];
//
//	int inicios_vector[ELEMENTS];
//	int procesos_asig[ELEMENTS];
//	int procesos_asig_recv[ELEMENTS];
//	srand(time(NULL));
//	//Lleno vector con valores aleatorios
//	llenarVector(vector, ELEMENTS);
//
//
//
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER
//	if (proceso_actual == MASTER) {
//
//		//Si N es multiplo de P
//		if (true)
//		{
//			//Lleno la matriz con valores aleatorios
//			//llenarMatrix((int**)matrix, ELEMENTS);
//			for (int i = 0; i < ELEMENTS; i++)
//			{
//				for (int j = 0; j < ELEMENTS; j++)
//				{
//					matrix[i][j] = 1 + rand() % 10;
//					printf("matrix[%d][%d] -> %d\n", i, j, matrix[i][j]);
//				}
//
//			}
//
//			//Distribuye la matrix entre los P procesos
//			for (int i = 1; i < ELEMENTS; i++)
//			{
//				procesos_asig[i] = ELEMENTS;
//				inicios_vector[0] = 0;
//				inicios_vector[i] += ELEMENTS;
//			}
//
//		}
//
//	}
//	//fflush(stdout);
//	MPI_Scatter(&matrix, ELEMENTS, MPI_INT, procesos_asig_recv, ELEMENTS, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso: %d Arreglo recibido -> {%d, %d, %d, %d}\n", 
//		proceso_actual, procesos_asig_recv[0], procesos_asig_recv[1], procesos_asig_recv[2], procesos_asig_recv[3]);
//	
//	int r = mulMatrix(procesos_asig_recv, vector, ELEMENTS);
//	printf("%d\n", r);
//
//	MPI_Gather(&r, 1, MPI_INT, vector_res, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	if (proceso_actual == MASTER)
//	{
//		printf("Vector resultante -> {%d, %d, %d, %d}", 
//			vector_res[0], vector_res[1], vector_res[2], vector_res[3]);
//	}
//
//
//
//	MPI_Finalize();
//	return 0;
//}

////Multiplicacion de matrices, el numero de columnas de A debe ser igual al num de filas de B con broadcast
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//	int proceso_actual, total_procesos;
//
//	int matrix[ELEMENTS][ELEMENTS];
//	int vector[ELEMENTS];
//	int vector_res[ELEMENTS];
//
//	int inicios_vector[ELEMENTS];
//	int procesos_asig[ELEMENTS];
//	int procesos_asig_recv[ELEMENTS];
//
//	srand(time(NULL));
//	
//	MPI_Init(NULL, NULL);
//
//	MPI_Comm_rank(MPI_COMM_WORLD, &proceso_actual);
//	MPI_Comm_size(MPI_COMM_WORLD, &total_procesos);
//
//	//Soy MASTER
//	if (proceso_actual == MASTER) {
//
//		//Lleno la matriz con valores aleatorios
//		llenarMatrix(matrix, ELEMENTS);
//
//		//Lleno vector con valores aleatorios
//		llenarVector(vector, ELEMENTS);
//
//		//Distribuye la matrix entre los P procesos
//		for (int i = 1; i < ELEMENTS; i++)
//		{
//			procesos_asig[i] = ELEMENTS;
//			inicios_vector[0] = 0;
//			inicios_vector[i] += ELEMENTS;
//		}
//	}
//
//	MPI_Scatter(&matrix, ELEMENTS, MPI_INT, procesos_asig_recv, ELEMENTS, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("\nProceso %d Parte matriz -> {%d, %d, %d, %d}\n",
//		proceso_actual, procesos_asig_recv[0], procesos_asig_recv[1], procesos_asig_recv[2], procesos_asig_recv[3]);
//
//	MPI_Bcast(vector, ELEMENTS, MPI_INT, MASTER, MPI_COMM_WORLD);
//	printf("Proceso %d vector -> {%d, %d, %d, %d}\n", proceso_actual, vector[0], vector[1], vector[2], vector[3]);
//
//	int r = mulMatrix(procesos_asig_recv, vector, ELEMENTS);
//	printf("%d\n", r);
//
//	MPI_Gather(&r, 1, MPI_INT, vector_res, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	if (proceso_actual == MASTER)
//	{
//		printf("\nProceso %d Vector resultante -> {%d, %d, %d, %d}\n", proceso_actual,
//			vector_res[0], vector_res[1], vector_res[2], vector_res[3]);
//	}
//
//	MPI_Finalize();
//	return 0;
//}


//#include <math.h> 
//#include "mpi.h"   // Biblioteca de MPI
//#include <cstdlib> // Incluido para el uso de atoi
//#include <iostream>
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	int n, // Numero de iteraciones
//		rank, // Identificador de proceso
//		size; // Numero de procesos
//	double PI25DT = 3.141592653589793238462643;
//	double mypi, // Valor local de PI
//		pi,   // Valor globarl de PI
//		h,   // Aproximacion del area para el calculo de PI
//		sum;  // Acumulador para la suma del area de PI
//	bool valor_por_parametros = true; // Comprueba si hay valores por parametros
//
//
//	MPI_Init(&argc, &argv); // Inicializamos los procesos
//	MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el numero total de procesos
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el valor de nuestro identificador
//
//	// Solo el proceso 0 va a conocer el numero de iteraciones que vamos a
//	// ejecutar para la aproximacion de PI
//	if (rank == 0) {
//		cout << "introduce la precision del calculo (n > 0): ";
//		cin >> n;
//	}
//
//	// El proceso 0 reparte al resto de procesos el numero de iteraciones
//	// que calcularemos para la aproximacion de PI
//	MPI_Bcast(&n, // Puntero al dato que vamos a enviar
//		1,  // Numero de datos a los que apunta el puntero
//		MPI_INT, // Tipo del dato a enviar
//		0, // Identificacion del proceso que envia el dato
//		MPI_COMM_WORLD);
//	if (n <= 0) {
//		MPI_Finalize();
//		exit(0);
//	}
//	else {
//		// Calculo de PI
//		h = 1.0 / (double)n;
//		sum = 0.0;
//		for (int i = rank + 1; i <= n; i += size) {
//			double x = h * ((double)i - 0.5);
//			sum += (4.0 / (1.0 + x * x));
//		}
//		mypi = h * sum;
//
//		// Todos los procesos ahora comparten su valor local de PI,
//		// lo hacen reduciendo su valor local a un proceso
//		// seleccionada a traves de una operacion aritmetica.
//		MPI_Reduce(&mypi, // Valor local de PI
//			&pi,  // Dato sobre el que vamos a reducir el resto
//			1,	  // Numero de datos que vamos a reducir
//			MPI_DOUBLE,  // Tipo de dato que vamos a reducir
//			MPI_SUM,  // Operacion que aplicaremos
//			0, // proceso que va a recibir el dato reducido
//			MPI_COMM_WORLD);
//
//		// Solo el proceso 0 imprime el mensaje, ya que es la unica que
//		// conoce el valor de PI aproximado.
//		if (rank == 0)
//			cout << "El valor aproximado de PI es: " << pi
//			<< ", con un error de " << fabs(pi - PI25DT)
//			<< endl;
//	}
//
//	// Terminamos la ejecucion de los procesos, despues de esto solo existira
//	// el proceso 0
//	// ¡Ojo! Esto no significa que los demas procesos no ejecuten el resto
//	// de codigo despues de "Finalize", es conveniente asegurarnos con una
//	// condicion si vamos a ejecutar mas codigo (Por ejemplo, con "if(rank==0)".
//	MPI_Finalize();
//	return 0;
//}



////Calculo de PI con integral definida
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	double PI = 3.141592653589793238462643;
//	double local_pi, pi, w,	h;
//
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	w = 1.0 / (double)size;
//	h = 0.0;
//
//	double x = ((double)rank + 1) * w - (w / 2);
//	h = (4.0 / (1.0 + x * x));
//
//	local_pi = w * h;
//
//	MPI_Reduce(&local_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
//
//	if (rank == MASTER)
//		printf("El valor aproximado de PI es: %f con un error de %f", pi, (pi - PI));
//
//
//	MPI_Finalize();
//	return 0;
//
//}

////Area bajo la curva de n^2 
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	double area_local, area, w, h;
//	double k = 1; //Intervalo
//	int n = 10; //Iteraciones
//
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	w = k / (double)n;
//	h = 0.0;
//
//	//Es intercalado
//	for (int i = rank + k; i <= n; i += size) {
//		double x = w * ((double)i - 0.5);
//		h += x * x;
//		printf("Proceso %d %f\n", rank, x);
//	}
//
//	printf("\n\n");
//
//	area_local = w * h;
//	//printf("%f\n", area_local);
//
//	MPI_Reduce(&area_local, &area, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
//
//	if (rank == MASTER)
//		printf("El area bajo la curva es: %f\n", area);
//
//
//	MPI_Finalize();
//	return 0;
//
//}


////Topologia Cartesiana
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	int dim_size[2] = { 3, 4 };
//	int periods[2] = { 0, 0 };
//	int coords[2];
//	int res[3][4];
//
//	MPI_Comm NEW_COMM;
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	MPI_Cart_create(MPI_COMM_WORLD, 2, dim_size, periods, 1, &NEW_COMM);
//	MPI_Cart_coords(NEW_COMM, rank, 2, coords);
//
//	printf("\nProceso: %d Cordenadas: (%d,%d)\n", rank, coords[0], coords[1]);
//
//	int matriz[3][4] = {
//		{10,20,30,40},
//		{50,60,70,80},
//		{90,100,110,120}
//	};
//
//	int rm = matriz[coords[0]][coords[1]] * 2;
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("[%d]\t", matriz[i][j]);
//		}
//		printf("\n");
//	}
//
//	MPI_Gather(&rm, 1, MPI_INT, &res, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	if (rank == MASTER)
//	{
//		printf("\nMatriz resultado: \n");
//		for (int i = 0; i < 3; i++)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				printf("[%d]\t", res[i][j]);
//			}
//			printf("\n");
//		}
//	}
//
//	MPI_Finalize();
//	return 0;
//
//}

////Suma de Matrices (n procesos = filas*columnas)
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	int n_dimens = DIMENS;
//	int dimens[DIMENS] = { FILA, COLUMNA };
//	int periods[DIMENS] = { 0, 0 };
//	int coords[DIMENS];
//	int resMatriz[FILA][COLUMNA];
//
//	MPI_Comm NEW_COMM;
//
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	MPI_Cart_create(MPI_COMM_WORLD, n_dimens, dimens, periods, 1, &NEW_COMM);
//	MPI_Cart_coords(NEW_COMM, rank, DIMENS, coords);
//
//	printf("\nProceso: %d Cordenadas: (%d,%d)\n", rank, coords[0], coords[1]);
//	int a[FILA][COLUMNA];
//	int b[FILA][COLUMNA];
//	int resIJ;
//
//	//Llenar matriz a
//	for (int i = 0; i < FILA; i++)
//	{
//		for (int j = 0; j < COLUMNA; j++)
//		{
//			a[i][j] = 1 + rand() % 10;
//			printf("[%d]\t", a[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	//Llenar matriz b
//	for (int i = 0; i < FILA; i++)
//	{
//		for (int j = 0; j < COLUMNA; j++)
//		{
//			b[i][j] = 1 + rand() % 10;
//			printf("[%d]\t", b[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	//Sumar a + b -> res
//	resIJ = a[coords[0]][coords[1]] + b[coords[0]][coords[1]];
//
//	MPI_Gather(&resIJ, 1, MPI_INT, &resMatriz, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
//
//	if (rank == MASTER)
//	{
//		printMatrixInt(resMatriz, FILA);
//	}
//
//	MPI_Finalize();
//	return 0;
//
//}

////Ordenamiento de Matrices (n procesos = filas*columnas)
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
////struct matriz paquete = {true, 0};
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//
//	//Topologia cartesiana
//	int n_dimens = DIMENS; // Numero de dimensiones de la matriz
//	int dimens[DIMENS] = { FILA, COLUMNA }; // Longitud de cada dimensión
//	int periods[DIMENS] = { 0, 0 }; //No ciclico en ninguna dimension
//	MPI_Comm COMM = MPI_COMM_WORLD;
//	MPI_Comm NEW_COMM; //Nuevo comunicador con la nueva topologia
//
//	//Cart Shift
//	int rank_source;
//	int rank_dest;
//
//	int coords[DIMENS];
//	int matriz[FILA][COLUMNA];
//	int elemento = 0, elementoSend = 0, elementoRecv = 0;
//	int resMatriz[FILA][COLUMNA];
//	MPI_Request request;
//	MPI_Status status;
//	bool cambio = false;
//	//llenarMatrix(matriz, FILA);
//	
//	
//	//PARALELISMO
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(COMM, &size);
//	MPI_Comm_rank(COMM, &rank);
//
//	printf("------------------------------------------------PROCESO: %d\n", rank);
//
//	if (rank == MASTER) {
//		
//		//Lleno la matriz con valores
//		matriz[0][0] = 4; 
//		matriz[0][1] = 0;
//		matriz[0][2] = 3;
//		matriz[1][0] = 3;
//		matriz[1][1] = 2;
//		matriz[1][2] = 7;
//		matriz[2][0] = 2;
//		matriz[2][1] = 3;
//		matriz[2][2] = 1;
//		printf("Matriz inicial:\n");
//		printMatrixInt(matriz, FILA);
//		
//	}
//	MPI_Bcast(&matriz, FILA * COLUMNA, MPI_INT, MASTER, COMM);
//	
//	MPI_Cart_create(COMM, n_dimens, dimens, periods, 1, &NEW_COMM);
//	MPI_Cart_coords(NEW_COMM, rank, DIMENS, coords);
//
//	MPI_Cart_shift(NEW_COMM, HORIZONTAL, 1, &rank_source, &rank_dest);
//	
//	//Elemento correspondiente de la matriz en un proceso
//	elemento = matriz[coords[0]][coords[1]];
//
//	printf("Cordenadas: (%d,%d)\nElemento: %d\nSource: %d\nDest: %d\n", 
//					coords[0], coords[1], elemento, rank_source, rank_dest);
//
//	bool paridad = true;//1 par, 0 impar
//
//	for (int i = 0; i <= COLUMNA - 1; i++)
//	{
//		printf("\nIteracion %d\n", i);
//		if (paridad)
//		{
//			printf("Paridad: par\n");
//			//Soy columna par
//			if (coords[1] % 2 == 0)
//			{
//				//Si tengo vecino a la derecha
//				if (rank_dest != MPI_PROC_NULL)
//				{
//					//Si el vecino es mayor, reemplazo
//					if (matriz[coords[0]][coords[1] + 1] > elemento)
//					{
//						elementoSend = elemento;
//						elemento = matriz[coords[0]][coords[1] + 1];
//						cambio = 1;
//
//						printf("CHANGE\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else
//					{
//						cambio = 0;
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//					
//					MPI_Send(&elementoSend, 1, MPI_INT, rank_dest, cambio, COMM);
//					printf("P%d -> P%d\n", rank, rank_dest);
//				}
//			}
//			//Soy columna impar
//			if (coords[1] % 2 == 1)
//			{
//
//				MPI_Recv(&elementoSend, 1, MPI_INT, rank_source, MPI_ANY_TAG, COMM, &status);
//				printf("\nP%d <- P%d Change: %d\n", rank, rank_source, status.MPI_TAG);
//
//				if (status.MPI_TAG == true)
//				{
//					elemento = elementoSend;
//
//					cambio = false;
//					printf("CHANGE:\n");
//					printMatrixInt(matriz, FILA);
//				}
//				else {
//					printf("NO CHANGE:\n");
//					printMatrixInt(matriz, FILA);
//				}
//
//			}
//			paridad = false;
//			MPI_Allgather(&elemento, 1, MPI_INT, matriz, 1, MPI_INT, COMM);
//		}
//
//		else
//		{
//			printf("Paridad: impar\n");
//			//Soy columna impar
//			if (coords[1] % 2 == 1)
//			{
//				//Si tengo vecino a la derecha
//				if (rank_dest != MPI_PROC_NULL)
//				{
//					//Si el vecino es mayor, reemplazo
//					if (matriz[coords[0]][coords[1] + 1] > elemento)
//					{
//						elementoSend = elemento;
//						elemento = matriz[coords[0]][coords[1] + 1];
//						cambio = true;
//						printf("CHANGE\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else
//					{
//						cambio = false;
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//					MPI_Send(&elementoSend, 1, MPI_INT, rank_dest, cambio, COMM);
//					printf("P%d -> P%d\n", rank, rank_dest);
//				}
//			}
//			//Soy columna par
//			if (coords[1] % 2 == 0)
//			{
//				//Si tengo origen (columna a la izquierda)
//				if (rank_source != MPI_PROC_NULL)
//				{
//					MPI_Recv(&elementoSend, 1, MPI_INT, rank_source, MPI_ANY_TAG, COMM, &status);
//					printf("\nP%d <- P%d Change: %d\n", rank, rank_source, status.MPI_TAG);
//
//					if (status.MPI_TAG == true)
//					{
//						elemento = elementoSend;
//						cambio = false;
//						printf("CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else {
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//				}
//
//			}
//			paridad = true;
//			MPI_Allgather(&elemento, 1, MPI_INT, matriz, 1, MPI_INT, COMM);
//		}
//		
//	}
//
//	//Vertical
//	paridad = true;
//	MPI_Allgather(&elemento, 1, MPI_INT, matriz, 1, MPI_INT, COMM);
//	MPI_Cart_shift(NEW_COMM, VERTICAL, 1, &rank_source, &rank_dest);
//
//	printf("\nCordenadas: (%d,%d)\nElemento: %d\nSource: %d\nDest: %d\n",
//		coords[0], coords[1], elemento, rank_source, rank_dest);
//
//	for (int i = 0; i <= FILA - 1; i++)
//	{
//		printf("\nIteracion %d\n", i);
//		if (paridad)
//		{
//			printf("Paridad: par\n");
//			//Soy columna par
//			if (coords[0] % 2 == 0)
//			{
//				//Si tengo vecino a la derecha
//				if (rank_dest != MPI_PROC_NULL)
//				{
//					//Si el vecino es mayor, reemplazo
//					if (matriz[coords[0] + 1][coords[1]] > elemento)
//					{
//						elementoSend = elemento;
//						elemento = matriz[coords[0] + 1][coords[1]];
//						cambio = 1;
//
//						printf("CHANGE\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else
//					{
//						cambio = 0;
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//
//					MPI_Send(&elementoSend, 1, MPI_INT, rank_dest, cambio, COMM);
//					printf("P%d -> P%d\n", rank, rank_dest);
//				}
//			}
//			//Soy columna impar
//			if (coords[0] % 2 == 1)
//			{
//
//				MPI_Recv(&elementoSend, 1, MPI_INT, rank_source, MPI_ANY_TAG, COMM, &status);
//				printf("\nP%d <- P%d Change: %d\n", rank, rank_source, status.MPI_TAG);
//
//				if (status.MPI_TAG == true)
//				{
//					elemento = elementoSend;
//
//					cambio = false;
//					printf("CHANGE:\n");
//					printMatrixInt(matriz, FILA);
//				}
//				else {
//					printf("NO CHANGE:\n");
//					printMatrixInt(matriz, FILA);
//				}
//
//			}
//			paridad = false;
//			MPI_Allgather(&elemento, 1, MPI_INT, matriz, 1, MPI_INT, COMM);
//		}
//
//		else
//		{
//			printf("Paridad: impar\n");
//			//Soy columna impar
//			if (coords[0] % 2 == 1)
//			{
//				//Si tengo vecino a la derecha
//				if (rank_dest != MPI_PROC_NULL)
//				{
//					//Si el vecino es mayor, reemplazo
//					if (matriz[coords[0] + 1][coords[1]] > elemento)
//					{
//						elementoSend = elemento;
//						elemento = matriz[coords[0] + 1][coords[1]];
//						cambio = true;
//						printf("CHANGE\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else
//					{
//						cambio = false;
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//					MPI_Send(&elementoSend, 1, MPI_INT, rank_dest, cambio, COMM);
//					printf("P%d -> P%d\n", rank, rank_dest);
//				}
//			}
//			//Soy columna par
//			if (coords[0] % 2 == 0)
//			{
//				//Si tengo origen (columna a la izquierda)
//				if (rank_source != MPI_PROC_NULL)
//				{
//					MPI_Recv(&elementoSend, 1, MPI_INT, rank_source, MPI_ANY_TAG, COMM, &status);
//					printf("\nP%d <- P%d Change: %d\n", rank, rank_source, status.MPI_TAG);
//
//					if (status.MPI_TAG == true)
//					{
//						elemento = elementoSend;
//						cambio = false;
//						printf("CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//					else {
//						printf("NO CHANGE:\n");
//						printMatrixInt(matriz, FILA);
//					}
//				}
//
//			}
//			paridad = true;
//			MPI_Allgather(&elemento, 1, MPI_INT, matriz, 1, MPI_INT, COMM);
//		}
//
//	}
//
//
//	//Recolecto los datos 
//	MPI_Gather(&elemento, 1, MPI_INT, &resMatriz, 1, MPI_INT, MASTER, COMM);
//
//	if (rank == MASTER) {
//		printf("\nRESULTADOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO:\n");
//		printMatrixInt(resMatriz, FILA);
//		//printMatrixInt(matriz, FILA);
//	}
//	
//
//	MPI_Finalize();
//	return 0;
//
//}

////Area bajo la curva
//#include <stdio.h>
//#include <math.h> 
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//double tiempo_inicial, tiempo_final;
//
////Funcion a integrar
//double f(double x)
//{
//	double y;
//	y = 1.0 / (sin(x) + 2.0) + 1.0 / (sin(x) * cos(x) + 2.0);
//	return y;
//}
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	double a, //Limite a
//		b, //Limite b
//		w, 
//		a_local, 
//		b_local;
//	double n, //Numero de trapecios
//		n_local;
//	double resul, resul_local; // Resultado de la integral
//	MPI_Comm COMM = MPI_COMM_WORLD;
//
//	//PARALELISMO
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(COMM, &size);
//	MPI_Comm_rank(COMM, &rank);
//
//	//Distribucion
//	if (rank == MASTER)
//	{
//		a = 0;
//		b = 100;
//		n = 1024;
//		printf("Limite a: %1.1f\nLimite b: %1.1f\nNum trapecios: %1.1f", (double)a, (double)b, (double)n);
//		tiempo_inicial = MPI_Wtime();
//	}
//
//	MPI_Bcast(&a, 1, MPI_DOUBLE, MASTER, COMM);
//	MPI_Bcast(&b, 1, MPI_DOUBLE, MASTER, COMM);
//	MPI_Bcast(&n, 1, MPI_LONG_LONG, MASTER, COMM);
//
//	w = (b - a) / n;//Divicion de a hasta b entre n
//	n_local = (rank + 1) * n / size - rank * n / size;
//	a_local = a + (rank)* n / size * w;
//	b_local = a + (rank + 1) * n / size * w;
//
//	// Calculo de la integral local
//	double x;
//	long long i; // n_local es un long de 8 bytes
//	resul_local = (f(a_local) + f(b_local)) / 2.0;
//	x = a_local;
//
//	for (i = 1; i < n_local; i++)
//	{
//		x = x + w;
//		resul_local = resul_local + f(x);
//	}
//	resul_local = resul_local * w;
//
//
//	// Suma de resultados
//	MPI_Reduce(&resul_local, &resul, 1, MPI_DOUBLE, MPI_SUM, MASTER, COMM);
//	tiempo_final = MPI_Wtime();
//
//	// Impresion de resultados
//	if (rank == MASTER)
//	{
//		printf("\nIntegral de f(x) -> %1.12f", resul);
//		printf("\nTime of ejecution P%d -> %1.2fms \n\n", rank, (tiempo_final - tiempo_inicial) * 1000);
//	}
//
//	MPI_Finalize();
//	return 0;
//
//}

////Grupos de comunicadores
//#include <stdio.h>
//#include <math.h> 
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//	int rlider, rrojo;
//	int gRojo[4] = { 0, 4, 5, 6 };
//	int gLider[4] = { 0, 1, 2, 3 };
//
//	MPI_Group general;
//	MPI_Group lider;
//	MPI_Group rojo;
//	MPI_Comm COMM_LIDER;
//	MPI_Comm COMM_ROJO;
//	MPI_Comm COMM = MPI_COMM_WORLD;
//
//	//PARALELISMO
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(COMM, &size);
//	MPI_Comm_rank(COMM, &rank);
//
//	MPI_Comm_group(COMM, &general); //grupo del comunicador world
//	MPI_Group_incl(general, 4, gLider, &lider); //Incluimos en el grupo lider los procesos en gRojo del grupo general
//	MPI_Group_incl(general, 4, gRojo, &rojo);
//	MPI_Comm_create(COMM, lider, &COMM_LIDER);
//	MPI_Comm_create(COMM, rojo, &COMM_ROJO);
//
//	if (rank < 4)
//	{
//		MPI_Comm_rank(COMM_LIDER, &rlider);
//		printf("P%d en grupo lider y P%d en grupo general.", rlider, rank);
//	}
//	else if(rank < 7) {
//		MPI_Comm_rank(COMM_ROJO, &rrojo);
//		printf("P%d en grupo rojo y P%d en grupo general.", rrojo, rank);
//	}
//
//	MPI_Finalize();
//	return 0;
//
//}

//Suma de filas de una matriz
#include <stdio.h>
#include "mpi.h"
#include "package.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Functions.h"

//struct matriz paquete = {true, 0};

int main(int argc, char* arcv[]) {

	int rank, size;

	//Cart Shift
	int rank_source;
	int rank_dest;

	//Problema
	int matriz[FILA][COLUMNA];
	int suma_local = 0;
	int vector_suma[FILA];
	int resMatriz[FILA][COLUMNA];
	int vector_local[COLUMNA];

	//MPI Var
	MPI_Comm COMM = MPI_COMM_WORLD; //Communicador universal
	MPI_Comm NEW_COMM; //Nuevo comunicador con la nueva topologia
	MPI_Request request;
	MPI_Status status;

	//PARALELISMO
	MPI_Init(NULL, NULL);
	MPI_Comm_size(COMM, &size);
	MPI_Comm_rank(COMM, &rank);

	//Si no es multiplo de 5
	if (FILA % 5 != 0)
	{
		printf("Ingresa un numero de filas valido (multiplos de 5).");
		MPI_Finalize();
		exit(-1);
	}

	//Si es multiplo de 5
	if (size != 5)
	{
		printf("El numero de procesos debe ser 5.");
		MPI_Finalize();
		exit(-1);
	}

	for (int i = 0; i < FILA; i++)
	{
		vector_suma[i] = 0;
	}
	
	printf("\n\nPROCESO: %d\n", rank);

	if (rank == MASTER) {

		//Lleno la matriz con valores
		llenarMatrix(matriz, FILA);
	}

	//Envia la matriz a todos los procesos
	MPI_Bcast(&matriz, FILA * COLUMNA, MPI_INT, MASTER, COMM);

	for (int i = rank; i < FILA; i+=5)
	{
		for (int j = 0; j < COLUMNA; j++)
		{
			printf("[%d]\t", matriz[i][j]);
			suma_local += matriz[i][j];
		}

		printf("Suma de fila [%d] -> %d\n", i, suma_local);

		vector_suma[i] = suma_local;

		suma_local = 0;
	}

	MPI_Finalize();

	return 0;
}

////Suma de vecinos de un elento de una matriz
//#include <stdio.h>
//#include "mpi.h"
//#include "package.h"
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#include "Functions.h"
//
//int main(int argc, char* arcv[]) {
//
//	int rank, size;
//
//	//Cart Shift
//	int rank_source;
//	int rank_dest;
//
//	//Problema
//	int matriz[FILA][COLUMNA];
//	int suma_local = 0;
//	int vector_suma[FILA];
//	int resMatriz[FILA][COLUMNA];
//	int vector_local[COLUMNA];
//
//	//MPI Var
//	MPI_Comm COMM = MPI_COMM_WORLD; //Communicador universal
//	MPI_Comm NEW_COMM; //Nuevo comunicador con la nueva topologia
//	MPI_Request request;
//	MPI_Status status;
//
//	//PARALELISMO
//	MPI_Init(NULL, NULL);
//	MPI_Comm_size(COMM, &size);
//	MPI_Comm_rank(COMM, &rank);
//
//	//Si no es multiplo de 5
//	if (FILA % 5 != 0)
//	{
//		printf("Ingresa un numero de filas valido (multiplos de 5).");
//		MPI_Finalize();
//		exit(-1);
//	}
//
//	//Si es multiplo de 5
//	if (size != 5)
//	{
//		printf("El numero de procesos debe ser 5.");
//		MPI_Finalize();
//		exit(-1);
//	}
//
//	for (int i = 0; i < FILA; i++)
//	{
//		vector_suma[i] = 0;
//	}
//
//	printf("\n\nPROCESO: %d\n", rank);
//
//	if (rank == MASTER) {
//
//		//Lleno la matriz con valores
//		llenarMatrix(matriz, FILA);
//	}
//
//	//Envia la matriz a todos los procesos
//	MPI_Bcast(&matriz, FILA * COLUMNA, MPI_INT, MASTER, COMM);
//
//	for (int i = rank; i < FILA; i += 5)
//	{
//		for (int j = 0; j < COLUMNA; j++)
//		{
//			printf("[%d]\t", matriz[i][j]);
//			suma_local += matriz[i][j];
//		}
//
//		printf("Suma de fila [%d] -> %d\n", i, suma_local);
//
//		vector_suma[i] = suma_local;
//
//		suma_local = 0;
//	}
//
//	MPI_Finalize();
//
//	return 0;
//}

//Sumar vecinos 
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <mpi.h>
//
//#define M 4
//#define N 4
//
//#define P 2
//
//#define MP M/P
//#define NP N
//
//#define MAXITER   1
//#define PRINTFREQ  200
//
//void printMatrixInt(int m[][N], int n) {
//	printf("\nPrint Matriz.\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("[%d]\t", m[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main(int argc, char** argv)
//{
//	int old[MP + 2][NP + 2],
//		neww[MP + 2][NP + 2],
//		edge[MP + 2][NP + 2];
//
//	int masterbuf[M][N];
//	int base[M][N];
//	int buf[MP][NP];
//
//	int i, j;
//
//	int rank, size, next, prev;
//	MPI_Status status;
//
//	MPI_Init(&argc, &argv);
//
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	if (size != P)
//	{
//		if (rank == 0) printf("ERROR: size = %d, P = %d\n", size, P);
//		MPI_Finalize();
//		exit(-1);
//	}
//
//	next = rank + 1;
//	prev = rank - 1;
//
//	if (next >= size)
//	{
//		next = MPI_PROC_NULL;
//	}
//
//	if (prev < 0)
//	{
//		prev = MPI_PROC_NULL;
//	}
//
//	//Limpia la matriz edge
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			edge[i][j] = 0;
//		}
//	}
//
//	//Limpia la matriz neww
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			neww[i][j] = 0;
//		}
//	}
//
//	if (rank == 0)
//	{
//		printf("Processing %d x %d image on %d processes\n", M, N, P);
//		printf("Number of iterations = %d\n", MAXITER);
//
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				masterbuf[i][j] = 1;
//			}
//		}
//
//		printMatrixInt(masterbuf, M);
//		printf("\n");
//
//	}
//	printf("*****************************PROCESO %d**********************\n", rank);
//	MPI_Scatter(masterbuf, MP * NP, MPI_INT, buf, MP * NP, MPI_INT, 0, MPI_COMM_WORLD);
//
//	printf("IMPRIME BUF\n");
//	printMatrixInt(buf, MP);
//
//	//Anillos de comunicacion
//	MPI_Sendrecv(&buf[MP-1][1], NP-2, MPI_INT, next, 1, &buf[0][1], NP-2, MPI_INT, prev, 1, MPI_COMM_WORLD, &status);
//
//	MPI_Sendrecv(&buf[0][1], NP-2, MPI_INT, prev, 2, &buf[MP - 1][1], NP-2, MPI_INT, next, 2, MPI_COMM_WORLD, &status);
//
//	if (rank == 0)
//	{
//		for (i = 1; i < MP; i++)
//		{
//			for (j = 1; j < NP - 1; j++)
//			{
//				neww[i][j] = masterbuf[i - 1][j] + masterbuf[i + 1][j] + masterbuf[i][j - 1] + masterbuf[i][j]
//					+ masterbuf[i][j + 1] + masterbuf[i - 1][j - 1] + masterbuf[i - 1][j + 1] + masterbuf[i + 1][j - 1] + masterbuf[i + 1][j + 1];
//			}
//		}
//	}
//	
//
//	////Reemplaza los valores de old con neww
//	//for (i = 1; i < MP + 1; i++)
//	//{
//	//	for (j = 1; j < NP + 1; j++)
//	//	{
//	//		old[i][j] = neww[i][j];
//	//	}
//	//}
//	////Imprime para ver resultado de old
//	//printf("OLD_nuevo\n");
//	//for (int i = 0; i < MP + 2; i++)
//	//{
//	//	for (int j = 0; j < NP + 2; j++)
//	//	{
//	//		printf("[%d]\t", old[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//	//printf("FIN_OLD--------\n");
//	//Finaliza el proceso
//
//	MPI_Gather(buf, MP * NP, MPI_INT, masterbuf, MP * NP, MPI_INT, 0, MPI_COMM_WORLD);
//
//	if (rank == 0)
//	{
//		printMatrixInt(masterbuf, M);
//	}
//
//	MPI_Finalize();
//}


////Sumar vecinos con topologia cartesiana
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <mpi.h>
//
//#define M 4
//#define N 4
//#define P M*N
//#define P_BORDE 2*M + 2*N - 4
//#define MASTER 0
//#define HORIZONTAL 1
//#define VERTICAL 0
//
//
//void printMatrixInt(int m[][N], int n) {
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("[%d]\t", m[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main(int argc, char** argv)
//{
//	//Topologia cartesiana
//	int n_dimens = 2; // Numero de dimensiones de la matriz
//	int dimens[2] = { M, N }; // Longitud de cada dimensión
//	int periods[2] = { 0, 0 }; //No ciclico en ninguna dimension
//
//	//MPI Var
//	MPI_Comm COMM = MPI_COMM_WORLD;
//	MPI_Comm NEW_COMM; //Nuevo comunicador con la nueva topologia
//
//	//Cart Shift
//	int rank_source_h;
//	int rank_dest_h;
//	int rank_source_v;
//	int rank_dest_v;
//	int coords[2];
//
//	//Problem
//	int matriz[M][N];
//	int resMatriz[M][N];
//	int elemento = 0;
//	int rank, size;
//	int rank_validos[P - P_BORDE];
//	int suma = 0;
//
//	MPI_Init(&argc, &argv);
//
//	MPI_Comm_size(MPI_COMM_WORLD, &size);
//	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//
//	if (size != P)
//	{
//		if (rank == 0) printf("ERROR: size = %d, P = %d\n", size, P);
//		MPI_Finalize();
//		exit(-1);
//	}
//
//	if (rank == MASTER)
//	{
//		printf("Processing %d x %d matrix on %d processes\n\n", M, N, P);
//
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				matriz[i][j] = 1;
//			}
//		}
//
//		printf("MATRIZ INICIAL:\n");
//		printMatrixInt(matriz, M);
//		printf("\n");
//
//	}
//	
//	MPI_Bcast(&matriz, M*N, MPI_INT, MASTER, COMM);
//
//	MPI_Cart_create(COMM, n_dimens, dimens, periods, 1, &NEW_COMM);
//	MPI_Cart_coords(NEW_COMM, rank, 2, coords);
//	
//	MPI_Cart_shift(NEW_COMM, HORIZONTAL, 1, &rank_source_h, &rank_dest_h);
//	MPI_Cart_shift(NEW_COMM, VERTICAL, 1, &rank_source_v, &rank_dest_v);
//		
//	//Elemento correspondiente de la matriz en un proceso
//	int i = coords[0];
//	int j = coords[1];
//	elemento = matriz[i][j];
//
//	if (rank_source_h != MPI_PROC_NULL && rank_dest_h != MPI_PROC_NULL && 
//		rank_source_v != MPI_PROC_NULL && rank_dest_v != MPI_PROC_NULL)
//	{
//		/*printf("*****************************PROCESO %d**********************\n", rank);
//		printf("Cordenadas: (%d,%d)\nElemento: %d\nSource_h: %d\nDest_h: %d\nSource_v: %d\nDest_v: %d\n",
//			i, j, elemento, rank_source_h, rank_dest_h, rank_source_v, rank_dest_v);*/
//
//		elemento = matriz[i - 1][j - 1] + matriz[1 - 1][j] + matriz[i - 1][j + 1]
//			+ matriz[i][j - 1] + matriz[i][j] + matriz[i][j + 1]
//			+ matriz[i + 1][j - 1] + matriz[i + 1][j] + matriz[i + 1][j + 1];
//
//	}
//
//	//Recolecto los datos 
//	MPI_Gather(&elemento, 1, MPI_INT, &resMatriz, 1, MPI_INT, MASTER, COMM);
//
//	if (rank == 0)
//	{
//		printf("RESULTADO:\n");
//		printMatrixInt(resMatriz, M);
//	}
//
//	MPI_Finalize();
//}