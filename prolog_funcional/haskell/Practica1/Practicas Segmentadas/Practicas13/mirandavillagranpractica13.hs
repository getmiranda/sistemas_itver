--José Manuel Miranda Villagrán

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 1
			Cree una función que reciba como parámetros a longitud y anchura de un rectángulo.
			La función dará como salida la anchura y longitud del rectángulo además del área,
			únicamente si el perímetro del rectángulo es mayor que 12. De lo contrario la función
			dará como salida la frase: “PERIMETRO MENOR O IGUAL A 12”, utilice la función
			predeterminada de Haskell SHOW.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvRectangulo

PARÁMETROS
			mir1 -> Lonitud
			mir2 -> anchura

DESCRIPCIÓN
			Función de validación para el perimetro		
-}
jmmvRectangulo :: (Ord a, Num a, Show a) => a -> a -> [Char]
jmmvRectangulo mir1 mir2 = if (mir1 * 2 + mir2 * 2) > 12
        then 
            "Anchura:" ++ show mir2
            ++ " Longitud:" ++ show mir1 
            ++ " Area:" ++ show (jmmvAreaRectangulo mir1 mir2)
        else
            "PERIMETRO MENOR O IGUAL A 12"

{-
NOMBRE DE LA FUNCION: 
			jmmvAreaRectangulo

PARÁMETROS
			mir3 -> Base
			mir4 -> Altura

DESCRIPCIÓN
			Calcula el área de un rectangulo	
-}

jmmvAreaRectangulo :: Num a => a -> a -> a
jmmvAreaRectangulo mir3 mir4 = mir3 * mir4


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 2
			Construya una función que simplifique un quebrado. El quebrado estará representado
			por una tupla de dos elementos, el primer elemento es el numerador y el segundo es el
			denominador. Investigue sobre la función predeterminada de Haskell gcd y úsela en la
			construcción de la función. Ejemplo:
										simplificaQ (4,10) ➔ (2,5) 
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvSimplificaFraccion

PARÁMETROS
			mir1 -> Numerador
			mir2 -> Denominador

DESCRIPCIÓN
			Simplifica una fraccion dada de la forma (Numerador, Denominador)
-}

jmmvSimplificaFraccion :: Integral b => (b, b) -> (b, b)
jmmvSimplificaFraccion (mir1, mir2) =  (div mir1 (gcd mir1 mir2), div mir2 (gcd mir1 mir2))


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 3
			Construya una función que divida dos quebrados. Cada quebrado estará representado
			por una tupla de dos elementos, el primer elemento es el numerador y el segundo es el
			denominador. El resultado de la función deberá estar simplificado use la función anterior
			para lograrlo. Use más de una función.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvDivFraccion

PARÁMETROS
			mir1 -> Numerador a
			mir2 -> Denominador a
			mir3 -> Numerador b
			mir4 -> Denominador b

DESCRIPCIÓN
			Realiza una divicion de quebrado y lo simplifica
-}
jmmvDivFraccion :: Integral b => (b, b) -> (b, b) -> (b, b)
jmmvDivFraccion (mir1, mir2) (mir3, mir4) = jmmvSimplificaFraccion (mir1 * mir4, mir2 * mir3)