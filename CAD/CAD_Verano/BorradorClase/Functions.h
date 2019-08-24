#pragma once

#include <time.h>

int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	return fact;
}

void llenarMatrix(int m[][COLUMNA], int n) {
	srand(time(NULL));
	printf("\nMatriz inicial.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLUMNA; j++)
		{
			m[i][j] = 1 + rand() % 10;
			printf("[%d]\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void llenarVector(int vector[], int n) {
	srand(time(NULL));
	printf("\nVector inicial.\n");
	for (int i = 0; i < n; i++)
	{
		vector[i] = 1 + rand() % 10;
		printf("[%d]\t", vector[i]);
	}
	printf("\n\n");
}

void printVector(int vector[], int n) {
	printf("\nPrint Vector.\n");
	for (int i = 0; i < n; i++)
	{
		printf("[%d]\t", vector[i]);
	}
	printf("\n\n");
}

int mulMatrix(int a[], int b[], int n) {
	int ij = 0;
	for (int i = 0; i < n; i++)
	{
		ij += a[i] * b[i];
	}
	return ij;
}

//Param: FILA, COLUMNA
//void createMatrixInt(int fila, int columna) {
//	srand(time(NULL));
//	
//	printf("\nMatriz inicial.\n");
//	for (int i = 0; i < fila; i++)
//	{
//		for (int j = 0; j < columna; j++)
//		{
//			m[i][j] = 1 + rand() % 10;
//			printf("[%d]\t", m[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

//Param: FILA, COLUMNA
//addMatrixInt(int a[][COLUMNA], int b[][COLUMNA], int fila) {
//	int m[FILA][COLUMNA];
//	printf("\nMatriz inicial.\n");
//
//	for (int i = 0; i < FILA; i++)
//	{
//		for (int j = 0; j < COLUMNA; j++)
//		{
//			m[i][j] = a[i][j] + b[i][j];
//		}
//	}
//	return m;
//}

void printMatrixInt(int m[][COLUMNA], int n) {
	printf("\nPrint Matriz.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLUMNA; j++)
		{
			printf("[%d]\t", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}