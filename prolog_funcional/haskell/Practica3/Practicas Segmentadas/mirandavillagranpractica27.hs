--José Manuel Miranda Villagrán
{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 2
			Hacer una función recursiva que reciba 2 parámetros una lista y un número. 
			La función dará como salida cuantas veces se repite el numero en la lista.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvCER

PARÁMETROS
			mir2   -> Parametro de cualquier tipo.
			(x:xs) -> Lista de cualquier tipo.

DESCRIPCIÓN
            Funcion que cuenta elementos repetidos en la lista.
			
-}
jmmvCER :: (Eq t, Num p) => t -> [t] -> p
jmmvCER mir1 (x:xs)
    | mir1 == x = 1 + jmmvCER mir1 xs
    | otherwise = jmmvCER mir1 xs
jmmvCER _ [] = 0


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 4
			Cree una función que cuente el numero de veces que se encuentra una letra en una cadena 
			de caracteres. Ejemplo: cuentaletras ‘e’ “eWtitffgeuyteee” => 5
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvCER

PARÁMETROS
			mir1   -> Parametro de cualquier tipo. Para ejercicio tipo char.
			(x:xs) -> Lista de cualquier tipo. Para ejercicio una lista de char.

DESCRIPCIÓN
			Funcion que cuenta caracteres repetidos en una cadena.
-}
jmmvCER' :: (Eq t, Num p) => t -> [t] -> p
jmmvCER' mir1 (x:xs)
    | mir1 == x = 1 + jmmvCER' mir1 xs
    | otherwise = jmmvCER' mir1 xs
jmmvCER' _ [] = 0


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 5
			CONTRUYA UNA FUNCION QUE RECIBA COMO PARÁMETRO UN NUMERO ENTERO. A PARTIR DEL CUAL, 
			LA FUNCIÓN GENERARA UNA LISTA DE NUMEROS ORDENADA DESCENDENTEMENTE FORMADASOLO POR LOS 
			NUMEROS PARES GENERADOS A PARTIR DEL ENTERO DADO. EJEMPLO:devuelvelistaP 10➔[10,8,6,4,2]
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvListaParDesc

PARÁMETROS
			mir1   -> Numero entero positivo.

DESCRIPCIÓN
			Crea una lista de numeros pares de manera descendiente a partir de mir1.
-}
jmmvListaParDesc :: Integral a => a -> [a]
jmmvListaParDesc mir1
    | mir1 >= 0 = if residuo == 0 
                  then mir1 : jmmvListaParDesc (mir1 - 1) 
                  else jmmvListaParDesc (mir1 - 1)
    | otherwise = []
    where
        residuo = mod mir1 2


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 6
			CREE UNA FUNCION QUE RECIBA COMO PARAMETRO UNA LISTA DE ENTEROS Y UN NUMERO ENTERO W.
			LA LISTA CONTENDRA ENTEROS POSITIVOS, Y NEGATIVOS TAMBIEN CONTENDRA CEROS.
			W MULTIPLICARA SOLO A LOS ELEMENTOS DE LA LISTA QUE SEAN MAYORES QUE CERO. 
			EJEMPLO:mul [-1,-2,-3,0,0,0,1,2,3] 100 ➔[-1,-2,-3,0,0,0,100,200,300]
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvMulFactor

PARÁMETROS
			mir1   -> Numero entero W.
			(x:xs) -> Lista de enteros negativos y positivos.

DESCRIPCIÓN
			Funcion que multiplica los elementos de la lista mayores a cero con W.
-}
jmmvMulFactor :: (Ord t, Num t) => t -> [t] -> [t]
jmmvMulFactor mir1 (x:xs) = if x > 0 
                            then (x * mir1) : jmmvMulFactor mir1 xs 
                            else x : jmmvMulFactor mir1 xs
jmmvMulFactor _ [] = []


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 7
			CREE UNA FUNCION QUE RECIBA COMO PARAMETRO UNA LISTA DE ENTEROS, UN NUMERO N Y UN NUMERO W. 
			LA FUNCION OMITIRA SUMAR LOS N PRIMEROS ELEMENTOS DE LA LISTA, PARA POSTERIORMENTE SOLO 
			SUMAR LOS ELEMENTOS DE LA LISTA MAYORES A W.

			sumaSinP 3 10 [1,2,3,12,13,14]=> 39
			sumaSinP 3 19 [1,2,3,12,13,14]=> 0
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvMulFactor

PARÁMETROS
			mir1   -> Numero entero N.
			mir2   -> Numero entero W.
			(x:xs) -> Lista de enteros.

DESCRIPCIÓN
			Funcion omite los N primeros elementos, y suma aquellos que sean mayores a W.
-}
jmmvSumaEMW :: (Ord t, Ord a, Num t, Num a) => t -> a -> [a] -> a
jmmvSumaEMW mir1 mir2 (x:xs)
    | mir1 > 0 = jmmvSumaEMW (mir1 - 1) mir2 xs
    | otherwise = if x > mir2
                  then x + jmmvSumaEMW mir1 mir2 xs 
                  else jmmvSumaEMW mir1 mir2 xs
jmmvSumaEMW _ _ [] = 0