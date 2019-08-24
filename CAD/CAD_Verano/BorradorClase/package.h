#pragma once

#define MASTER 0
#define TOKEN 1
#define DATA 2
#define ELEMENTS 4
#define FILA 20
#define COLUMNA 10
#define DIMENS 2
#define HORIZONTAL 1
#define VERTICAL 0

/* definimos una estructura para el paquete */
struct pack
{
	int origen;
	int destino;
	char contenido[50];

};
//paquete = {
//		1, /* Origen */
//		3, /* Destino */
//		"Mensaje que recorre el anillo.", /* Dato */
//};

struct matriz
{
	bool change;
	int value;
};