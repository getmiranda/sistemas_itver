%{
    #include <stdio.h>
	#include "Sintactico.tab.h"
    int flag;
    int noerror = 0;
%}

    /* VARIABLES DE ER ------------------------------*/

VCONSTANTE      [0-9]+
VREAL		    [0-9]*\.[0-9]+
VLOGICO		    "TRUE"|"FALSE"
VIDENTIFICADOR  [a-zA-Z]+[a-zA-Z0-9]*
VCADENA         \'[^']+\'
ESPACIO	        [ \t\n]


    /* OPCIONES DE FLEX ---------------------------------*/

%option noyywrap
%option yylineno
%x COMENTARIO
%x COMENTERIOLINEA

%%

    /* ELIMINACION DE COMENTARIOS Y ESPACIOS ------------*/

{ESPACIO}*                 { ; }

"#"			              {BEGIN(COMENTERIOLINEA); }
<COMENTERIOLINEA>[\n]	  {BEGIN(INITIAL); }
<COMENTERIOLINEA>[ ]+ 
<COMENTERIOLINEA>[\t]+ 
<COMENTERIOLINEA>. 

"#*"			          {BEGIN(COMENTARIO); }
<COMENTARIO>"*#"	      {BEGIN(INITIAL); }
<COMENTARIO>[\n] 
<COMENTARIO>[ ]+ 
<COMENTARIO>[\t]+	
<COMENTARIO>. 


    /* PALABRAS RESERVADAS ------------------------------*/

"program"		    { return PROGRAM; }
"print"			    { return PRINT; }
"integer"		    { return TIPO_INTEGER; }
"logical"		    { return TIPO_LOGICAL; }
"string"		    { return TIPO_STRING; }
"numeric"		    { return TIPO_NUMERIC; }
"for"			    { return FOR; }
"while"			    { return WHILE; }
"do"			    { return DO_IF; }
"if"			    { return IF; }
"then"			    { return THEN; }
"else"			    { return ELSE; }
"scan"			    { return SCAN; }
"return"            { return RETURN; }
"void"              { return VOID; }
"import"            { return IMPORT; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"break"             { return BREAK;}


    /* CABECERAS ---------------------------------------*/

"math.gg"           { return MATH; }
"io.gg"             { return IO; }


    /* OPERADORES ---------------------------------------*/

"+"				    { return '+'; }
"-"				    { return '-'; }
"*"				    { return '*'; }
"/"				    { return '/'; }
"^"                 { return '^'; }
"<-"			    { return ASIGNA; }
"++"			    { return INCREMENTO; }
"--"			    { return DECREMENTO; }
"mod"			    { return MOD; }
"$"                 { return '$'; }
"<"				    { return '<'; }
">"				    { return '>'; }
">="			    { return MAYOR_IGUAL; }
"<="			    { return MENOR_IGUAL; }
"!!"			    { return DIFERENTE; }
"=="			    { return IGUAL; }
"&&"			    { return AND; }
"||"			    { return OR; }
"!"				    { return '!'; }
"%s"                { return ESPECIFICADOR_STRING; }
"%d"                { return ESPECIFICADOR_INTEGER; }
"%l"                { return ESPECIFICADOR_LOGICAL; }
"%n"                { return ESPECIFICADOR_NUMERIC; }


    /* DELIMITADORES ------------------------------------*/

"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
";"                 { return ';'; }
","                 { return ','; }
":"                 { return ':'; }


    /* VALORES ------------------------------------------*/

{VREAL}             { return VALOR_NUMERIC; }
{VCONSTANTE}        { return VALOR_INTEGER; }
{VLOGICO}           { return VALOR_LOGICAL; }
{VCADENA}           { return VALOR_STRING; }
{VIDENTIFICADOR}    { return IDENTIFICADOR; }


    /* CONTADOR DE LINEAS Y ERRORES ---------------------*/

\n                  { yylineno++; }
.                   { printf( "<lexico error> linea: %d - no se reconoce token '%s'. Borrar simbolo.\n", yylineno, yytext ); flag = 1; noerror++; }
<<EOF>>             { return 0; }

%%