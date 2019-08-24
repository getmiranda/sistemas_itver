/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SINTACTICO_TAB_H_INCLUDED
# define YY_YY_SINTACTICO_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     PRINT = 259,
     TIPO_INTEGER = 260,
     TIPO_LOGICAL = 261,
     TIPO_STRING = 262,
     TIPO_NUMERIC = 263,
     FOR = 264,
     WHILE = 265,
     DO_IF = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     SCAN = 270,
     RETURN = 271,
     VOID = 272,
     IMPORT = 273,
     SWITCH = 274,
     CASE = 275,
     BREAK = 276,
     ASIGNA = 277,
     INCREMENTO = 278,
     DECREMENTO = 279,
     MOD = 280,
     MAYOR_IGUAL = 281,
     MENOR_IGUAL = 282,
     DIFERENTE = 283,
     IGUAL = 284,
     AND = 285,
     OR = 286,
     VALOR_LOGICAL = 287,
     VALOR_STRING = 288,
     VALOR_NUMERIC = 289,
     VALOR_INTEGER = 290,
     IDENTIFICADOR = 291,
     ESPECIFICADOR_STRING = 292,
     ESPECIFICADOR_NUMERIC = 293,
     ESPECIFICADOR_LOGICAL = 294,
     ESPECIFICADOR_INTEGER = 295,
     MATH = 296,
     IO = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SINTACTICO_TAB_H_INCLUDED  */
