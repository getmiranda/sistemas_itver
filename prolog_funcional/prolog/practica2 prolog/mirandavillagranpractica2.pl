% JOSE MANUEL MIRANDA VILLAGRAN


%%%%%%% HECHOS REALES %%%%%%%%%
% pepa es mujer
% lucia es mujer
% blanca es mujer
% rosa es mujer
% alba es mujer
% ines es mujer
% irene es mujer
% armando es hombre
% julian es hombre
% esteban es hombre
% mario es hombre
% alejandro es hombre
% martin es hombre
% matias es hombre
% pepa es progenitor de lucia
% pepa es progenitor de blanca
% pepa es progenitor de mario
% lucia es progenitor de rosa
% lucia es progenitor de alba
% blanca es progenitor ines
% blanca es progenitor de martin
% irene es progenitor de matias
% armando es progenitor de lucia
% armando es progenitor de blanca
% armando es progenitor mario
% julian es progenitor de rosa
% julian es progenitor de alba
% alejandro es progenitor de ines
% alejandro es progenitor de martin
% mario es progenitor de matias 


%%%%% BASE DE CONOCIMIENTO

es_mujer(pepa).
es_mujer(lucia).
es_mujer(blanca).
es_mujer(rosa).
es_mujer(alba).
es_mujer(ines).
es_mujer(irene).

es_hombre(armando).
es_hombre(julian).
es_hombre(esteban).
es_hombre(mario).
es_hombre(alejandro).
es_hombre(martin).
es_hombre(matias).

progenitor(pepa, lucia).
progenitor(pepa, blanca).
progenitor(pepa, mario).
progenitor(lucia, rosa).
progenitor(lucia, alba).
progenitor(blanca, ines).
progenitor(blanca, martin).
progenitor(irene, matias).
progenitor(armando, lucia).
progenitor(armando, blanca).
progenitor(armando, mario).
progenitor(julian, rosa).
progenitor(julian, alba).
progenitor(alejandro, ines).
progenitor(alejandro, martin).
progenitor(mario, matias).


es_padre(PER1, PER2):- es_hombre(PER1), progenitor(PER1, PER2), PER1\=PER2.

es_madre(PER1, PER2):- es_mujer(PER1), progenitor(PER1, PER2), PER1\=PER2.

es_hijo(PER1, PER2):- es_hombre(PER1), (es_padre(PER2, PER1) ; es_madre(PER2, PER1)), PER1\=PER2.

es_hija(PER1, PER2):- es_mujer(PER1), (es_padre(PER2, PER1) ; es_madre(PER2, PER1)), PER1\=PER2.

es_abuelo(PER1, PER2):- es_hombre(PER1), es_padre(PER1, PER3), (es_padre(PER3, PER2) ; es_madre(PER3, PER2)), PER1\=PER2.

es_abuela(PER1, PER2):- es_mujer(PER1), es_madre(PER1, PER3), (es_padre(PER3, PER2) ; es_madre(PER3, PER2)), PER1\=PER2.

es_hermano(PER1, PER2):- es_hombre(PER1), (es_padre(PER3, PER1) , es_madre(PER4, PER1)), (es_padre(PER3, PER2) , es_madre(PER4, PER2)), PER1\=PER2.

es_hermana(PER1, PER2):- es_mujer(PER1), (es_padre(PER3, PER1) , es_madre(PER4, PER1)), (es_padre(PER3, PER2) , es_madre(PER4, PER2)), PER1\=PER2.

es_tio(PER1, PER2):- es_hombre(PER1), es_hermano(PER1, PER4), (es_padre(PER4, PER2) ; es_madre(PER4, PER2)), PER1\=PER2.

es_tia(PER1, PER2):- es_mujer(PER1), es_hermana(PER1, PER4), (es_padre(PER4, PER2) ; es_madre(PER4, PER2)),	PER1\=PER2.

es_primo(PER1, PER2):- es_hombre(PER1), (es_abuelo(PER3, PER1), es_abuelo(PER3, PER2) , es_abuela(PER4, PER1), es_abuela(PER4, PER2)), PER1\=PER2.

es_prima(PER1, PER2):- es_mujer(PER1), (es_abuelo(PER3, PER1), es_abuelo(PER3, PER2) , es_abuela(PER4, PER1), es_abuela(PER4, PER2)), PER1\=PER2.

es_unico(PER1):- not(es_hermano(PER1, PER2)) , not(es_hermana(PER1, PER2)).


%% Agregar 3 reglas

hijo_de(PER1, PER2, PER3):- ((es_padre(PER2, PER1) , es_madre(PER3, PER1)) ; (es_padre(PER3, PER1) , es_madre(PER2, PER1))), PER1\=PER2, PER1\=PER3, PER2\=PER3. 

sobrino(PER1, PER2):- (es_tio(PER2, PER1) ; es_tia(PER2, PER1)), PER1\=PER2.

no_hermanos(PER1, PER2):- not(es_hermano(PER1, PER2)) , not(es_hermana(PER1, PER2)), PER1\=PER2.




