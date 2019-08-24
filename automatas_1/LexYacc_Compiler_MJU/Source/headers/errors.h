#include <stdio.h>

void tokenEsperado(int tipoError){

    switch(tipoError){

        case 1: printf("Se esperaba palabra reservada 'import'\n");
                break;
        case 2: printf("Se esperaba '<'\n");
                break;
        case 3: printf("Se esperaba '>'\n");
                break;
        case 4: printf("Se esperaba palabra reservada 'program'\n");
                break;
        case 5: printf("Se esperaba '('\n");
                break;
        case 6: printf("Se esperaba ')'\n");
                break;
        case 7: printf("Se esperaba '{'\n");
                break;
        case 8: printf("Se esperaba '}'\n");
                break;
        case 9: printf("No se reconoce libreria.\n");
                break;
        case 10: printf("Se esperaba un identificador.\n");
                break;
        case 11: printf("Se esperaba un parametro.\n");
                break;
        case 12: printf("Necesita retornar un valor.\n");
                break;
        case 13: printf("Se esperaba ';'\n");
                break;
        case 14: printf("Se esperaba palabra reservada 'void'\n");
                break;
        case 15: printf("Se esperaba un tipo de dato.\n");
                break;
        case 16: printf("Se esperaba un valor o tiene error aritmetico.\n");
                break;
        case 17: printf("Se esperaba '<-'\n");
                break;
        case 18: printf("Se esperaba una variable.\n");
                break;
        case 19: printf("Se esperaba una condicion.\n");
                break;
        case 20: printf("Argumentos incorrectos. Se espera un valor.\n");
                break;

    }
}