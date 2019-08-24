//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <mpi.h>
//
// //#include "imageio.h"
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
//
//
//void printMatrixInt(float m[][N], int n) {
//	printf("\nPrint Matriz.\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("[%1.2f]\t", m[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main(int argc, char** argv)
//{
//	float old[MP + 2][NP + 2],
//		neww[MP + 2][NP + 2],
//		edge[MP + 2][NP + 2];
//
//	float masterbuf[M][N];
//	float buf[MP][NP];
//
//	int i, j, iter, maxiter;
//	//char* filename;
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
//
//
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				masterbuf[i][j] = 1;
//			}
//		}
//
//
//
//		printMatrixInt(masterbuf, M);
//		printf("\n");
//
//	}
//	printf("*****************************PROCESO %d**********************\n", rank);
//	//MPI_Bcast(masterbuf, MP * NP, MPI_FLOAT, 0, MPI_COMM_WORLD);
//	MPI_Scatter(masterbuf, MP * NP, MPI_FLOAT, buf, MP * NP, MPI_FLOAT, 0, MPI_COMM_WORLD);
//
//	printf("IMPRIME BUF\n");
//	printMatrixInt(buf, MP);
//
//	//Pasa de buf a edge con margenes 0**************************************************
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			edge[i][j] = buf[i - 1][j - 1];
//		}
//	}
//
//	//Imprime para ver resultado de edge
//	printf("EDGE\n");
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			printf("[%1.2f]\t", edge[i][j]);
//		}
//		printf("\n");
//	}
//	printf("FIN_EDGE--------\n");
//
//	//Llena old con valores 255***********************************************************
//	for (i = 0; i < MP + 2; i++)
//	{
//		for (j = 0; j < NP + 2; j++)
//		{
//			old[i][j] = 255.0;
//		}
//	}
//
//	//Imprime para ver resultado de old
//	printf("OLD\n");
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			printf("[%1.2f]\t", old[i][j]);
//		}
//		printf("\n");
//	}
//	printf("FIN_OLD--------\n");
//
//	//Aqui empieza el proceso***************************************************************
//	for (iter = 1; iter <= MAXITER; iter++)
//	{
//
//		MPI_Sendrecv(&old[MP][1], NP, MPI_FLOAT, next, 1, &old[0][1], NP, MPI_FLOAT, prev, 1, MPI_COMM_WORLD, &status);
//
//		MPI_Sendrecv(&old[1][1], NP, MPI_FLOAT, prev, 2, &old[MP + 1][1], NP, MPI_FLOAT, next, 2, MPI_COMM_WORLD, &status);
//
//		for (i = 1; i < MP + 1; i++)
//		{
//			for (j = 1; j < NP + 1; j++)
//			{
//				neww[i][j] = 0.25 * (old[i - 1][j] + old[i + 1][j] + old[i][j - 1] + old[i][j + 1] - edge[i][j]);
//			}
//		}
//
//		//Imprime para ver resultado de new
//		printf("NEW\n");
//		for (int i = 0; i < MP + 2; i++)
//		{
//			for (int j = 0; j < NP + 2; j++)
//			{
//				printf("[%1.4f]\t", neww[i][j]);
//			}
//			printf("\n");
//		}
//		printf("FIN_NEW--------\n");
//
//		//Reemplaza los valores de old con neww
//		for (i = 1; i < MP + 1; i++)
//		{
//			for (j = 1; j < NP + 1; j++)
//			{
//				old[i][j] = neww[i][j];
//			}
//		}
//		//Imprime para ver resultado de old
//		printf("OLD_nuevo\n");
//		for (int i = 0; i < MP + 2; i++)
//		{
//			for (int j = 0; j < NP + 2; j++)
//			{
//				printf("[%1.2f]\t", old[i][j]);
//			}
//			printf("\n");
//		}
//		printf("FIN_OLD--------\n");
//	} //Finaliza el proceso
//
//	if (rank == 0)
//	{
//		printf("\nFinished %d iterations\n", iter - 1);
//	}
//
//	//Pasa de old a buff para recolcetar
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			buf[i - 1][j - 1] = old[i][j];
//		}
//	}
//
//	MPI_Gather(buf, MP * NP, MPI_FLOAT, masterbuf, MP * NP, MPI_FLOAT, 0, MPI_COMM_WORLD);
//
//	if (rank == 0)
//	{
//		printMatrixInt(masterbuf, M);
//
//	}
//
//	MPI_Finalize();
//}
//
//EL QUE ES DE RECONSTRUCCION


//Primera version
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
//#define MASTER 0
//
//#define MAXITER 1
//
//int main(int argc, char** argv)
//{
//	float old[MP + 2][NP + 2],
//		neww[MP + 2][NP + 2],
//		edge[MP + 2][NP + 2];
//
//	float masterbuf[M][N];
//	float buf[MP][NP];
//
//	int i, j, iter, maxiter;
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
//	//Limpia la matriz contenedor (old) con 255
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			old[i][j] = 255.0;
//		}
//	}
//
//	//Limpia la matriz donde se almacena el resultado (neww) con 0
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
//	}
//
//	printf("*****************************PROCESO %d**********************\n", rank);
//	//Aqui se reparte toda la matriz en los n procesos
//	MPI_Scatter(masterbuf, MP * NP, MPI_FLOAT, buf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
//
//	//Imprimimos lo que le toca a cada procceso
//	printf("IMPRIME BUF\n");
//	printMatrixInt(buf, MP);
//
//	//Pasa de buf a old con margenes 255
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			old[i][j] = buf[i - 1][j - 1];
//		}
//	}
//
//	//Imprime para ver resultado de old
//	printf("OLD\n");
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			printf("[%1.4f]\t", old[i][j]);
//		}
//		printf("\n");
//	}
//	printf("FIN_OLD--------\n");
//
//	//Aqui empieza el proceso***************************************************************
//	for (iter = 1; iter <= MAXITER; iter++)
//	{
//		MPI_Sendrecv(&old[MP][1], NP, MPI_FLOAT, next, 1, &old[0][1], NP, MPI_FLOAT, prev, 1, MPI_COMM_WORLD, &status);
//
//		MPI_Sendrecv(&old[1][1], NP, MPI_FLOAT, prev, 2, &old[MP + 1][1], NP, MPI_FLOAT, next, 2, MPI_COMM_WORLD, &status);
//
//		//Suma sus vecinos verticales y horizontales y resta 4 veces el valir de la casilla
//		for (i = 1; i < MP + 1; i++)
//		{
//			for (j = 1; j < NP + 1; j++)
//			{
//				neww[i][j] = old[i - 1][j] + old[i + 1][j] + old[i][j - 1] + old[i][j + 1] - 4.0* old[i][j];
//			}
//		}
//
//		//Imprime para ver resultado de neww
//		printf("NEW\n");
//		for (int i = 0; i < MP + 2; i++)
//		{
//			for (int j = 0; j < NP + 2; j++)
//			{
//				printf("[%1.4f]\t", neww[i][j]);
//			}
//			printf("\n");
//		}
//		printf("FIN_NEW--------\n");
//
//
//		////Reemplaza los valores de old con neww (Por si hay mas iteraciones)
//		//for (i = 0; i < MP; i++)
//		//{
//		//	for (j = 0; j < NP; j++)
//		//	{
//		//		old[i][j] = neww[i][j];
//		//	}
//		//}
//		////Imprime para ver resultado de old
//		//printf("OLD_nuevo\n");
//		//for (int i = 0; i < MP + 2; i++)
//		//{
//		//	for (int j = 0; j < NP + 2; j++)
//		//	{
//		//		printf("[%1.2f]\t", old[i][j]);
//		//	}
//		//	printf("\n");
//		//}
//		//printf("FIN_OLD--------\n");
//	} //Finaliza el proceso
//
//	//if (rank == 0)
//	//{
//	//	printf("\nFinished %d iterations\n", iter - 1);
//	//}
//
//	//Pasa de old a buff para recolcetar
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			buf[i - 1][j - 1] = neww[i][j];
//		}
//	}
//
//	//Imprime para ver resultado de old
//	printf("BUF_ANTES DE RECOLECTAR\n");
//	for (int i = 0; i < MP; i++)
//	{
//		for (int j = 0; j < NP; j++)
//		{
//			printf("[%1.4f]\t", buf[i][j]);
//		}
//		printf("\n");
//	}
//	printf("BUF_OLD_ANTES DE RECOLECTAR--------\n");
//
//	MPI_Gather(buf, MP * NP, MPI_FLOAT, masterbuf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
//
//	if (rank == 0)
//	{
//		//Imprime para ver resultado
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				printf("[%1.4f]\t", masterbuf[i][j]);
//			}
//			printf("\n");
//		}
//	}
//
//	MPI_Finalize();
//}


////Deteccion de bordes
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <mpi.h>
//#include "imageio.h"
//#include <string.h>
//
//#define M 10
//#define N 10
//
//#define P 2
//
//#define MP M/P
//#define NP N
//#define MASTER 0
//
//#define MAXITER 1
//
//void printMatrixInt(float m[][N], int n) {
//	printf("\nPrint Matriz.\n");
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("[%1.2f]\t", m[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//int main(int argc, char** argv)
//{
//	float old[MP + 2][NP + 2],
//		neww[MP + 2][NP + 2],
//		edge[MP + 2][NP + 2];
//
//	float masterbuf[M][N];
//	float buf[MP][NP];
//
//	int i, j, iter, maxiter;
//	char filename[] = "linea.pgm";
//	char filename_out[] = "linea_out.pgm";
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
//	//Limpia la matriz contenedor (old) con 255
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			old[i][j] = 255.0;
//		}
//	}
//
//	//Limpia la matriz donde se almacena el resultado (neww) con 0
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
//
//		/*for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				masterbuf[i][j] = 1;
//			}
//		}*/
//		
//
//		pgmread(filename, masterbuf, M, N);
//
//		printMatrixInt(masterbuf, M);
//		printf("\n");
//	}
//
//	printf("*****************************PROCESO %d**********************\n", rank);
//	//Aqui se reparte toda la matriz en los n procesos
//	MPI_Scatter(masterbuf, MP * NP, MPI_FLOAT, buf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
//
//	//Imprimimos lo que le toca a cada procceso
//	printf("IMPRIME BUF\n");
//	printMatrixInt(buf, MP);
//
//	//Pasa de buf a old con margenes 255
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			old[i][j] = buf[i - 1][j - 1];
//		}
//	}
//
//	//Imprime para ver resultado de old
//	printf("OLD\n");
//	for (int i = 0; i < MP + 2; i++)
//	{
//		for (int j = 0; j < NP + 2; j++)
//		{
//			printf("[%1.4f]\t", old[i][j]);
//		}
//		printf("\n");
//	}
//	printf("FIN_OLD--------\n");
//
//	//Aqui empieza el proceso***************************************************************
//	for (iter = 1; iter <= MAXITER; iter++)
//	{
//		MPI_Sendrecv(&old[MP][1], NP - 2, MPI_FLOAT, next, 1, &old[0][1], NP - 2, MPI_FLOAT, prev, 1, MPI_COMM_WORLD, &status);
//
//		MPI_Sendrecv(&old[1][1], NP - 2, MPI_FLOAT, prev, 2, &old[MP + 1][1], NP - 2, MPI_FLOAT, next, 2, MPI_COMM_WORLD, &status);
//
//		//Suma sus vecinos verticales y horizontales y resta 4 veces el valir de la casilla
//		for (i = 1; i < MP + 1; i++)
//		{
//			for (j = 1; j < NP + 1; j++)
//			{
//				neww[i][j] = old[i - 1][j] + old[i + 1][j] + old[i][j - 1] + old[i][j + 1] - 4.0 * old[i][j];
//			}
//		}
//
//		//Imprime para ver resultado de neww
//		printf("NEW\n");
//		for (int i = 0; i < MP + 2; i++)
//		{
//			for (int j = 0; j < NP + 2; j++)
//			{
//				printf("[%1.4f]\t", neww[i][j]);
//			}
//			printf("\n");
//		}
//		printf("FIN_NEW--------\n");
//
//
//		////Reemplaza los valores de old con neww (Por si hay mas iteraciones)
//		//for (i = 0; i < MP; i++)
//		//{
//		//	for (j = 0; j < NP; j++)
//		//	{
//		//		old[i][j] = neww[i][j];
//		//	}
//		//}
//		////Imprime para ver resultado de old
//		//printf("OLD_nuevo\n");
//		//for (int i = 0; i < MP + 2; i++)
//		//{
//		//	for (int j = 0; j < NP + 2; j++)
//		//	{
//		//		printf("[%1.2f]\t", old[i][j]);
//		//	}
//		//	printf("\n");
//		//}
//		//printf("FIN_OLD--------\n");
//	} //Finaliza el proceso
//
//	//if (rank == 0)
//	//{
//	//	printf("\nFinished %d iterations\n", iter - 1);
//	//}
//
//	//Pasa de old a buff para recolcetar
//	for (i = 1; i < MP + 1; i++)
//	{
//		for (j = 1; j < NP + 1; j++)
//		{
//			buf[i - 1][j - 1] = neww[i][j];
//		}
//	}
//
//	//Imprime para ver resultado de old
//	printf("BUF_ANTES DE RECOLECTAR\n");
//	for (int i = 0; i < MP; i++)
//	{
//		for (int j = 0; j < NP; j++)
//		{
//			printf("[%1.4f]\t", buf[i][j]);
//		}
//		printf("\n");
//	}
//	printf("BUF_OLD_ANTES DE RECOLECTAR--------\n");
//
//	MPI_Gather(buf, MP * NP, MPI_FLOAT, masterbuf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
//
//	if (rank == 0)
//	{
//		//Imprime para ver resultado
//		for (int i = 0; i < M; i++)
//		{
//			for (int j = 0; j < N; j++)
//			{
//				printf("[%1.4f]\t", masterbuf[i][j]);
//			}
//			printf("\n");
//		}
//		pgmwrite(filename_out, masterbuf, M, N);
//	}
//
//	MPI_Finalize();
//}


//Deteccion de bordes iterativo
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include "imageio.h"
#include <string.h>

#define M 200
#define N 200

#define P 10

#define MP M/P
#define NP N
#define MASTER 0

#define MAXITER 1

void printMatrixInt(float m[][N], int n) {
	printf("\nPrint Matriz.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("[%1.2f]\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char** argv)
{
	float old[MP + 2][NP + 2],
		edge[MP + 2][NP + 2];
	//matriz original
	float masterbuf[M][N];
	//matrix con procesos
	float buf[MP][NP];

	int iter;
	char filename[] = "dragon200x200.pgm";
	char filename_out[] = "dragon200x200_out.pgm";

	int rank, size, next, prev;
	MPI_Status status;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (size != P)
	{
		if (rank == MASTER) printf("ERROR: size = %d, P = %d\n", size, P);
		MPI_Finalize();
		exit(-1);
	}
	//calculo el siguiente o anterior proceso
	next = rank + 1;
	prev = rank - 1;
	//validar que hay algun next o prev de proceso
	if (next >= size)
	{
		next = MPI_PROC_NULL;
	}
	if (prev < 0)
	{
		prev = MPI_PROC_NULL;
	}
	//Limpia la matriz contenedor (old) con 255
	//prepara la matriz de 255
	for (int i = 0; i < MP + 2; i++)
	{
		for (int j = 0; j < NP + 2; j++)
		{
			old[i][j] = 255.0;
		}
	}
	//Limpia la matriz donde se almacena el resultado de edge con 0
	for (int i = 0; i < MP + 2; i++)
	{
		for (int j = 0; j < NP + 2; j++)
		{
			edge[i][j] = 0;
		}
	}

	if (rank == MASTER)
	{
		printf("Prosesando %d x %d imagen en %d procesos...\n", M, N, P);

		/*for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				masterbuf[i][j] = 1;
			}
		}*/
		//libreria para llenar la matrix original principal
		read(filename, masterbuf, M, N);
		//printMatrixInt(masterbuf, M);
		printf("\n");
	}

	//printf("*****************************PROCESO %d**********************\n", rank);
	//Aqui se reparte toda la matriz en los n procesos
	MPI_Scatter(masterbuf, MP * NP, MPI_FLOAT, buf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);

	//Imprimimos lo que le toca a cada procceso
	//printf("IMPRIME BUF\n");
	//printMatrixInt(buf, MP);

	//Pasa de buf a old con margenes 255
	for (int i = 1; i < MP + 1; i++)
	{
		for (int j = 1; j < NP + 1; j++)
		{
			old[i][j] = buf[i - 1][j - 1];
		}
	}

	////Imprime para ver resultado de old
	//printf("OLD\n");
	//for (int i = 0; i < MP + 2; i++)
	//{
	//	for (int j = 0; j < NP + 2; j++)
	//	{
	//		printf("[%1.4f]\t", old[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("FIN_OLD--------\n");

	//Aqui empieza el proceso***************************************************************
	for (iter = 1; iter <= MAXITER; iter++)
	{//canal de comunicacion entre procesos. Envia y recibe al siguiente-previo
		MPI_Sendrecv(&old[MP][1], NP, MPI_FLOAT, next, 1, &old[0][1], NP, MPI_FLOAT, prev, 1, MPI_COMM_WORLD, &status);
		//Envia y recibe al previo-siguiente
		MPI_Sendrecv(&old[1][1], NP, MPI_FLOAT, prev, 2, &old[MP + 1][1], NP, MPI_FLOAT, next, 2, MPI_COMM_WORLD, &status);

		//Suma sus vecinos verticales y horizontales y resta 4 veces el valor de la casilla
		for (int i = 1; i < MP + 1; i++)
		{
			for (int j = 1; j < NP + 1; j++)
			{
				edge[i][j] = old[i - 1][j] + old[i + 1][j] + old[i][j - 1] + old[i][j + 1] - 4.0 * old[i][j];
			}
		}
		////Imprime para ver resultado de edge
		//printf("NEW\n");
		//for (int i = 0; i < MP + 2; i++)
		//{
		//	for (int j = 0; j < NP + 2; j++)
		//	{
		//		printf("[%1.4f]\t", edge[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("FIN_NEW--------\n");
		//Reemplaza los valores de old con edge (Por si hay mas iteraciones)
		for (int i = 0; i < MP+2; i++)
		{
			for (int j = 0; j < NP+2; j++)
			{
				old[i][j] = edge[i][j];
			}
		}	
	} //Finaliza el proceso
	if (rank == 0)
	{
		printf("\nTermino con %d iteraciones.\n", iter - 1);
	}
	//Pasa de old a buff para recolectar y sacar la nueva imagen
	for (int i = 1; i < MP + 1; i++)
	{
		for (int j = 1; j < NP + 1; j++)
		{
			buf[i - 1][j - 1] = old[i][j];
		}
	}
	////Imprime para ver resultado de old
	//printf("BUF_ANTES DE RECOLECTAR\n");
	//for (int i = 0; i < MP; i++)
	//{
	//	for (int j = 0; j < NP; j++)
	//	{
	//		printf("[%1.4f]\t", buf[i][j]);
	//	}
	//	printf("\n");
	//}
	//printf("BUF_OLD_ANTES DE RECOLECTAR--------\n");
	//almacena los nuevos valores de la matrix a la matriz original
	MPI_Gather(buf, MP * NP, MPI_FLOAT, masterbuf, MP * NP, MPI_FLOAT, MASTER, MPI_COMM_WORLD);

	if (rank == MASTER)
	{
		////Imprime para ver resultado
		//for (int i = 0; i < M; i++)
		//{
		//	for (int j = 0; j < N; j++)
		//	{
		//		printf("[%1.4f]\t", masterbuf[i][j]);
		//	}
		//	printf("\n");
		//}
		//matriz resultante
		write(filename_out, masterbuf, M, N);
	}

	MPI_Finalize();
}