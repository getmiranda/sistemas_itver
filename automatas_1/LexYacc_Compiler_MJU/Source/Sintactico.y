%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "headers/errors.h"

	/*VARIABLES*/
	extern char *yytext;
	extern FILE *yyin;
	extern int yylineno;
	extern int noerror;
	extern int flag;
	int tipoError = 0;
	int linea = 0;
	%}

 /* PALABRAS RESERVADAS DEL LENGUAJE*/
%token PROGRAM PRINT TIPO_INTEGER TIPO_LOGICAL TIPO_STRING TIPO_NUMERIC FOR WHILE DO_IF 
%token IF THEN ELSE SCAN RETURN VOID IMPORT SWITCH CASE BREAK

 /* OPERADORES*/
%token ASIGNA INCREMENTO DECREMENTO MOD MAYOR_IGUAL MENOR_IGUAL DIFERENTE IGUAL AND OR

 /* VALORES */
%token VALOR_LOGICAL VALOR_STRING VALOR_NUMERIC VALOR_INTEGER IDENTIFICADOR 

 /* ESPECIFICADORES */
%token ESPECIFICADOR_STRING ESPECIFICADOR_NUMERIC ESPECIFICADOR_LOGICAL ESPECIFICADOR_INTEGER

 /* CABECERAS */

%token MATH IO

%start	axioma

%%
axioma               : cabeceras main funciones;

	/* CABECERAS */

cabeceras            : cabecera cabeceras | cabecera;
cabecera             : IMPORT '<' libreria '>' ;
libreria             : MATH | IO;

cabecera             : { tipoError = 1; } error '<' libreria '>' ;
cabecera             : IMPORT { tipoError = 2; } error libreria '>' ;
cabecera             : IMPORT '<' libreria { tipoError = 3; linea = yylineno - 1; } error; 
cabecera             : IMPORT '<' { tipoError = 9; } error '>' ;



	/* METODO MAIN */

main                 : VOID PROGRAM '(' parametros ')' '{' instrucciones '}';

main                 : { tipoError = 14; imprimeError("syntax error", yylineno); } PROGRAM '(' parametros ')' '{' instrucciones '}' ;
main                 : VOID { tipoError = 4; } error '(' parametros ')' '{' instrucciones '}';
main                 : VOID PROGRAM { tipoError = 5; } error parametros ')' '{' instrucciones '}';
main                 : VOID PROGRAM '(' parametros { tipoError = 6; } error '{' instrucciones '}';
main                 : VOID PROGRAM '(' parametros ')' { tipoError = 7; linea = yylineno - 1; } error instrucciones '}';
main                 : VOID PROGRAM '(' parametros ')' '{' instrucciones { tipoError = 8; linea = yylineno - 1; } error;



	/* FUNCIONES */

funciones            : funcion funciones | ;
funcion              : VOID IDENTIFICADOR '(' parametros ')' '{' instrucciones '}';
funcion              : tipo IDENTIFICADOR '(' parametros ')' '{' instrucciones RETURN valor ';' '}';

funcion              : { tipoError = 14; imprimeError("syntax error", yylineno); } IDENTIFICADOR '(' parametros ')' '{' instrucciones '}';
funcion              : VOID { tipoError = 10; } error '(' parametros ')' '{' instrucciones '}';
funcion              : VOID IDENTIFICADOR { tipoError = 5; } error parametros ')' '{' instrucciones '}';
funcion              : VOID IDENTIFICADOR '(' parametros { tipoError = 6; } error '{' instrucciones '}';
funcion              : VOID IDENTIFICADOR '(' parametros ')' { tipoError = 7; linea = yylineno - 1; } error instrucciones '}';
funcion              : VOID IDENTIFICADOR '(' parametros ')' '{' instrucciones { tipoError = 8; } error;

funcion              : tipo { tipoError = 10; } error '(' parametros ')' '{' instrucciones RETURN valor ';' '}';
funcion              : tipo IDENTIFICADOR { tipoError = 5; } error parametros ')' '{' instrucciones RETURN valor ';' '}';
funcion              : tipo IDENTIFICADOR '(' parametros { tipoError = 6; } error '{' instrucciones RETURN valor ';' '}';
funcion              : tipo IDENTIFICADOR '(' parametros ')' { tipoError = 7; linea = yylineno - 1; } error instrucciones RETURN valor ';' '}';
funcion              : tipo IDENTIFICADOR '(' parametros ')' '{' instrucciones {tipoError = 12; linea = yylineno - 1;} error '}';
funcion              : tipo IDENTIFICADOR '(' parametros ')' '{' instrucciones RETURN valor ';' { tipoError = 8; } error;



	/* PARAMETROS DE FUNCIONES */

parametros          : parametro | ;
parametro           : tipo IDENTIFICADOR ',' parametro 
					| tipo IDENTIFICADOR;

parametro           : tipo {tipoError = 10; } error ',' parametro;
parametro           : tipo IDENTIFICADOR ',' {tipoError = 11; } error;


	/* ARGUMENTOS */

argumentosFuncion   : argumentoFuncion | ;
argumentoFuncion    : valor ',' argumentoFuncion 
					| valor;
/* argumentoFuncion    : error argumentoFuncion { yyerrok; }; */

argumentosImprimir  : argumentoImprimir | ;
argumentoImprimir   : valor '$' argumentoImprimir | valor;
//argumentoImprimir   : error argumentoImprimir { yyerrok; };

argumentoFor        : variableControl condiciones ';' actualizacion;
argumentoFor        : variableControl condiciones ';';
argumentoFor        : variableControl ';' actualizacion;
argumentoFor        : ';' condiciones ';' actualizacion;
argumentoFor        : variableControl ';';
argumentoFor        : ';' condiciones ';';
//argumentoFor        : error ';' error ';' error { yyerrok; };

actualizacion       : IDENTIFICADOR INCREMENTO | IDENTIFICADOR DECREMENTO;

	/* INSTRUCCIONES */

instrucciones       : instruccion instrucciones | ;
instruccion         : declaracion | asignacion | llamaFuncion | imprimir | leer | control | incremento | decremento;


	/* DECLARACIONES */


declaracion         : tipo varios ';'

varios              : IDENTIFICADOR ',' varios 
					| IDENTIFICADOR ;

varios              : IDENTIFICADOR ASIGNA valor ',' varios 
					| IDENTIFICADOR ASIGNA valor;

declaracion         : tipo varios { tipoError = 13; linea = yylineno - 1; } error;
varios              : { tipoError = 18; } error ASIGNA valor ',' varios;
varios              : IDENTIFICADOR ASIGNA { tipoError = 16; linea = yylineno; } error ',' varios;


	/* ASIGNACIONES */

asignacion          : IDENTIFICADOR ASIGNA valor ';';

asignacion          : { tipoError = 10; imprimeError("syntax error", yylineno); } ASIGNA valor ';';
asignacion          : IDENTIFICADOR { tipoError = 17; linea = yylineno; } error valor ';';


	/* LLAMADA DE FUNCIONES */

llamaFuncion        : IDENTIFICADOR '(' argumentosFuncion ')' ';';

llamaFuncion        : { tipoError = 10; imprimeError("syntax error", yylineno); } '(' argumentosFuncion ')' ';';
llamaFuncion        : IDENTIFICADOR '(' argumentosFuncion ')' { tipoError = 13; linea = yylineno; } error;



	/* ENTRADA Y SALIDA */ 

imprimir            : PRINT '(' argumentosImprimir ')' ';';
leer                : SCAN '(' especificador ',' IDENTIFICADOR ')' ';';

imprimir            : PRINT '(' { tipoError = 20; linea = yylineno; } error ')' ';';
imprimir            : PRINT '(' argumentosImprimir ')' { tipoError = 13; imprimeError("syntax error", yylineno - 1); };



	/* CASOS SWITCH */

casos               : caso casos 
					| caso;
caso                : CASE valorSwitch ':' instrucciones BREAK ';';
valorSwitch         : VALOR_INTEGER 
					| VALOR_STRING;

//caso                : error ':' error ';' { yyerrok; } ;



	/* ESTRUCTURAS DE CONTROL */

control             : if | if-else | do-if | for | while | switch;

if                  : IF '(' condiciones ')' '{' instrucciones '}';
if-else             : IF '(' condiciones ')' '{' instrucciones '}' ELSE '{' instrucciones '}'; 
do-if               : DO_IF '{' instrucciones '}' IF '(' condiciones ')' ';';
for                 : FOR '(' argumentoFor ')' '{' instrucciones '}';
while               : WHILE '(' condiciones ')' '{' instrucciones '}';
switch              : SWITCH '(' condiciones ')' '{' casos '}';

if                  : IF '(' condiciones ')' '{' instrucciones { tipoError = 8; } error;
if                  : IF '(' condiciones ')' { tipoError = 7; } error instrucciones '}';
if                  : IF '(' { tipoError = 19; linea = yylineno;} error ')' '{' instrucciones '}';
 


	/* INCREMENTO y DECREMENTO */

incremento          : IDENTIFICADOR INCREMENTO ';' ;
decremento          : IDENTIFICADOR DECREMENTO ';' ;



	/* OPERACIONES CON JERARQUIA */

condiciones         : condiciones logico q | q ;
q                   : q relacional w | w;
w                   : '(' condiciones ')' | valorl | '!' valorl;
w                   : '(' { tipoError = 19; linea = yylineno; } error ')' { yyerrok; } ;


aritmetica 	        : aritmetica '+' termino | aritmetica '-' termino | termino;
termino	            : termino '*' factor | termino '/' factor | factor;
factor	            : '(' aritmetica ')' | '(' aritmetica ')' '^' VALOR_INTEGER | VALOR_NUMERIC | VALOR_INTEGER | IDENTIFICADOR;
factor              : '(' { tipoError = 16; linea = yylineno; } error ')' ;



	/* OTRAS*/


valorl              : VALOR_STRING | VALOR_LOGICAL | VALOR_NUMERIC | VALOR_INTEGER | IDENTIFICADOR;
valorl              : IDENTIFICADOR '(' argumentosFuncion ')';
//valorl              : IDENTIFICADOR error ')' { yyerrok; } ;

variableControl     : declaracion | asignacion;

valor               : VALOR_STRING | VALOR_LOGICAL | aritmetica;
valor               : IDENTIFICADOR '(' argumentosFuncion ')';

tipo                : TIPO_STRING | TIPO_LOGICAL | TIPO_INTEGER | TIPO_NUMERIC;
especificador       : ESPECIFICADOR_INTEGER | ESPECIFICADOR_LOGICAL | ESPECIFICADOR_NUMERIC | ESPECIFICADOR_STRING;
relacional	    	: MAYOR_IGUAL | MENOR_IGUAL | IGUAL | DIFERENTE | '<' | '>';
logico              : AND | OR;

%%

yyerror(char* mensaje){

    imprimeError(mensaje, linea);

}

int main( int argc, char const *argv[] )
{
	
	flag = 0;
	yyin = fopen( argv[ 1 ], "r" );

	yyparse();

	switch(flag){
		case 0: puts("COMPILACION EXITOSA.\n");
				break;
		case 1: printf( "\nErrores: %d\n", noerror );
	  			puts( "COMPILACION FALLIDA." );
	  			break;
	}

  	return 0;
}

int imprimeError(char* mensaje, int linea)
{
    flag = 1;
    noerror++;

    if(linea == 0)
        linea = yylineno;
    

    if( strlen( yytext ) != 0){
        printf( "<%s> linea: %d - token '%s' invalido. ", mensaje, linea, yytext );

        tokenEsperado(tipoError);
    }
    else
        printf( "<%s> linea: %d - Se esperaba una '}' final de la linea.\n", mensaje, linea );
     return 0;
}