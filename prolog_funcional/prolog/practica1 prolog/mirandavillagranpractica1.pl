/*José Manuel Miranda Villagrán*/

/*CONJUNTOS*/
% Persona = {pedro, juan, maria, carlos}
% Sintoma = {fiebre, cansancio, diarrea}
% Enfermedad = {gripe, hepatitis, intoxicacion}
% Farmaco = {aspirina, lomotil}

/*HECHOS BASE DE CONOCIMIENTOS*/
/*padece(Persona, Enfermedad)*/
padece(pedro, gripe).
padece(pedro, hepatitis).
padece(juan, hepatitis).
padece(maria, gripe).
padece(carlos, intoxicacion).

/*sintoma(Sintoma, Enfermedad)*/
es_sintoma(fiebre, gripe).
es_sintoma(cansancio, hepatitis).
es_sintoma(diarrea, intoxicacion).
es_sintoma(cansancio, gripe).

/*suprime(Farmaco, Sintoma)*/
suprime(aspirina, fiebre).
suprime(lomotil, diarrea).

/*INFERENCIAS*/
alivia(Farmaco, Enfermedad) :- 
    es_sintoma(Sintoma, Enfermedad) , suprime(Farmaco, Sintoma).
deberia_tomar(Persona, Farmaco) :- 
    padece(Persona, Enfermedad) , alivia(Farmaco, Enfermedad).

/*RESPUESTAS*/
% 1) Puesto direntamente en consola
% padece(pedro, Dolencia).

% 2) Puesto directamente en consola.
% padece(Persona, gripe).

% 3), 4) y 5) Regla
tiene_sintoma(Persona, Sintoma) :- 
    padece(Persona, Enfermedad) , es_sintoma(Sintoma, Enfermedad).

% 6) Puesto directamente en consola
% deberia_tomar(pedro, Farmaco).

% 7) Regla
comparten(Persona, Persona2, Sintoma) :- 
    tiene_sintoma(Persona, Sintoma) , tiene_sintoma(Persona2, Sintoma).

% 8) AND
comparten2(Persona, Persona2, Enfermedad) :- 
    padece(Persona, Enfermedad) , padece(Persona2, Enfermedad).