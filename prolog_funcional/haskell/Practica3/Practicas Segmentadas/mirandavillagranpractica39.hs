--José Manuel Miranda Villagrán
{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 3
			Elabore una función que reciba una lista y un número entero n. La función devolverá 
			la suma de los primeros n elementos de la lista. Ejemplo: 
			f 3 [23,13,5,67,100,3] = 41
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvSumaNElement

PARÁMETROS
			mir1   -> Numero entero N.
			(x:xs) -> Lista de enteros.

DESCRIPCIÓN
			Funcion suma los primeros N elementos de la lista.
-}
jmmvSumaNElement :: (Ord t, Num t, Num p) => t -> [p] -> p
jmmvSumaNElement mir1 _ | mir1 <= 0 = 0
jmmvSumaNElement _ [] = 0
jmmvSumaNElement mir1 (x:xs) = x + jmmvSumaNElement (mir1 - 1) xs


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 8
			COSNTRUYA UNA FUNCIÓN QUE RECIBA COMO PARAMETROB UN NUMERO ENTERO DE VARIOS DIGITOS Y 
			UN NUMERO ENTERO DE UN DIGITO. LA FUNCION VERIFICARA QUE EL DIGITO DADO ESIGUAL AL PRIMER 
			DIGITO DE DERECHA A IZQUIERDA DEL NUMERO ENTERO DE VARIOS DIGITOS.

			SI SE VERIFICA LO ANTERIOR LA FUNCIÓN REPOTARA LO SIGUIENTE:
			primerD 987654 9 => "PRIMER DIGITO ES nueve"
			DE LO CONTRARIO
			primerD 987654 1 => "PRIMER DIGITO ES DIFERENTE DE uno"
			NOTA: USE MAS DE UNA FUNCIÓN
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvPrimerDigito

PARÁMETROS
			mir1   -> Numero entero N >= 2 digitos.
			mir2   -> Numero entero W de un digito.

DESCRIPCIÓN
			Verifica que el primer digito de N es igual W
-}
jmmvPrimerDigito :: Integral a => a -> a -> [Char]
jmmvPrimerDigito mir1 mir2 
    | digito /= mir2 = "PRIMER DIGITO ES DIFERENTE DE " ++ jmmvStrDig mir2
    | otherwise      = "PRIMER DIGITO ES " ++ jmmvStrDig mir2
   where
      digito = jmmvHead (jmmvToList mir1)


--DESCRIPCIÓN: Convierte un numero entero dado en una lista de elementos de sus digitos.
jmmvToList :: Integral a => a -> [a]
jmmvToList mir1 | mir1 <= 0 = []
    | otherwise = jmmvToList (div mir1 10) ++ [(mod mir1 10)]


--DESCRIPCIÓN: Obtiene el primer elemento de una lista.
jmmvHead :: [a] -> a
jmmvHead [] = error "jmmvHead no funciona con listas vacías!"
jmmvHead (x:xs) = x


--DESCRIPCIÓN: Ajuste de patrones que devuelve la cadena de un digito.
jmmvStrDig :: (Eq a, Num a) => a -> [Char]
jmmvStrDig 0 = "cero"
jmmvStrDig 1 = "uno"
jmmvStrDig 2 = "dos"
jmmvStrDig 3 = "tres"
jmmvStrDig 4 = "cuatro"
jmmvStrDig 5 = "cinco"
jmmvStrDig 6 = "seis"
jmmvStrDig 7 = "siete"
jmmvStrDig 8 = "ocho"
jmmvStrDig 9 = "nueve"


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 9
			Cree una función que descomponga numéricamente una cadena de caracteres numérica hasta 
			de 9 dígitos “999999999”, dada como parámetro. Sugerencia: use la instrucción case 
			y la función length de haskell. 

			Ejemplo: desnum "425" => "4 Centenas | 2 Decenas | 5 Unidades"
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvDesNum

PARÁMETROS
			mir1 -> Cadena de caracteres numérica.

DESCRIPCIÓN
			Descompone numericamente una cadena numerica dada.
-}
jmmvDesNum :: [Char] -> [Char]
jmmvDesNum mir1 | length mir1 <= 9 = jmmvCDU mir1 (length mir1) 1


{-
PARÁMETROS: 
            (x:xs) -> Cadena de caracteres numerica.
            mir1   -> Longitud de la cadena de caracteres numérica.
            mir1   -> Parámetro bandera.

DESCRIPCIÓN: Descompone numericamente una cadena numerica dada.
-}
jmmvCDU :: (Ord a1, Num a1, Num a2, Eq a2) => [Char] -> a1 -> a2 -> [Char]
jmmvCDU [] _ _ = []
jmmvCDU _ mir1 _ | mir1 <= 0 = []
jmmvCDU (x:xs) mir1 mir2 = (if mir2 /= 1 then " | " else "") ++ [x] ++ 
                           case mir1 of mir1 -> jmmvStrCDU mir1 ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)


jmmvStrCDU :: (Eq a, Num a) => a -> [Char]
jmmvStrCDU 1 = " Unidaes"
jmmvStrCDU 2 = " Decenas"
jmmvStrCDU 3 = " Centenas"
jmmvStrCDU 4 = " Unidaes de millar"
jmmvStrCDU 5 = " Decenas de millar"
jmmvStrCDU 6 = " Centenas de millar"
jmmvStrCDU 7 = " Unidaes de millon"
jmmvStrCDU 8 = " Decenas de millon"
jmmvStrCDU 9 = " Centenas de millon"

