--José Manuel Miranda Villagrán

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 4
			Determine los parámetros de entrada y cree una función de calcule la pendiente y la
			intercepción con el eje de las ordenadas de una ecuación lineal de la forma Ax + By + C = 0.
			Solo si la pendiente y/o la intercepción con el eje de las ordenadas NO son enteros exprese
			el resultado en forma de quebrado. Utilice la función predeterminada de Haskell SHOW. 
			Analice si es posible el uso de MAS DE UNA función.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvEcuacionRecta

PARÁMETROS
			mir1 -> Coeficiente a
			mir2 -> Coeficiente b
			mir3 -> Coeficiente c

DESCRIPCIÓN
			Estructura la oracion de salida para la ecuacion de la recta dada con el vaor de la pendiente y la interseccion en el eje Y.
-}
jmmvEcuacionRecta :: (Show a, Integral a) => a -> a -> a -> [Char]
jmmvEcuacionRecta mir1 mir2 mir3 = "La recta " ++ jmmvSignoCoeficienteA mir1 ++ "x" ++ jmmvSignoCoeficienteB mir2 ++ "y" ++ jmmvSignoConstanteC mir3 ++ "=0"
                                   ++ " tiene pendiente " ++ jmmvPendienteEcuacion mir1 mir2 
                                   ++ " e intersecta al eje Y en " ++ jmmvInterseccionY mir3 mir2


{-
NOMBRE DE LA FUNCION: 
			jmmvSignoCoeficienteA, jmmvSignoCoeficienteB y jmmvCoeficienteC

PARÁMETROS
			mir1 -> Corresponde a los coeficientes a, b y c respectivamente

DESCRIPCIÓN
			Establece el signo correcto y respeta la notacion matemática para definir una ecuación.
-}
jmmvSignoCoeficienteA :: (Num a, Ord a, Show a) => a -> [Char]
jmmvSignoCoeficienteA mir1 
        | mir1 == -1 = "-"
        | mir1 < -1 = show mir1
        | mir1 == 1 = ""
        | mir1 > 1 = show mir1

jmmvSignoCoeficienteB :: (Num a, Ord a, Show a) => a -> [Char]
jmmvSignoCoeficienteB mir1
        | mir1 == -1 = "-"
        | mir1 < -1 = show mir1
        | mir1 == 1 = "+"
        | mir1 > 1 = "+" ++ show mir1

jmmvSignoConstanteC :: (Ord a, Num a, Show a) => a -> String
jmmvSignoConstanteC mir1
        | mir1 < 0 = show mir1
        | mir1 > 0 = "+" ++ show mir1


{-
NOMBRE DE LA FUNCION: 
			jmmvPendienteEcuacion

PARÁMETROS
			mir1 -> Corresponde al coeficiente a
			mir2 -> Corresponde al coeficiente b

DESCRIPCIÓN
			Calcula la pendiente de la recta 
-}
jmmvPendienteEcuacion :: (Integral a, Show a) => a -> a -> String
jmmvPendienteEcuacion mir1 mir2 = if mir1 `mod` mir2 == 0 
                          then show ( -( div mir1 mir2) ) 
                          else jmmvNormalizaFraccion ( jmmvSimplificaFraccion (-mir1, mir2) )


{-
NOMBRE DE LA FUNCION: 
			jmmvInterseccionY

PARÁMETROS
			mir1 -> Corresponde al coeficiente c
			mir2 -> Corresponde al coeficiente b

DESCRIPCIÓN
			Calcula la interseccion con el eje Y 
-}
jmmvInterseccionY :: (Integral a, Show a) => a -> a -> String
jmmvInterseccionY mir1 mir2 = if mir1 `mod` mir2 == 0 
                              then show ( -( div mir1 mir2) ) 
                              else jmmvNormalizaFraccion ( jmmvSimplificaFraccion (-mir1, mir2) )


{-
NOMBRE DE LA FUNCION: 
			jmmvNormalizaFraccion

PARÁMETROS
			mir1 -> Corresponde al numerador
			mir2 -> Corresponde al denominador

DESCRIPCIÓN
			Establece el signo correcto y respeta la notacion matemática para definir una fracción.
-}
jmmvNormalizaFraccion :: (Ord a1, Ord a2, Num a1, Num a2, Show a1, Show a2) => (a1, a2) -> [Char]
jmmvNormalizaFraccion (mir1, mir2)
       | mir1 > 0 && mir2 > 0 = "" ++ show mir1 ++ "/" ++ show mir2
       | mir1 > 0 && mir2 < 0 = "-" ++ show mir1 ++ "/" ++ show (-mir2)
       | mir1 < 0 && mir2 > 0 = "-" ++ show (-mir1) ++ "/" ++ show mir2
       | mir1 < 0 && mir2 < 0 = "" ++ show (-mir1) ++ "/" ++ show (-mir2)


jmmvNormalizaFraccionConstanteC :: (Ord a1, Ord a2, Num a1, Num a2, Show a1, Show a2) => (a1, a2) -> [Char]
jmmvNormalizaFraccionConstanteC (mir1, mir2)
       | mir1 > 0 && mir2 > 0 = "+" ++ show mir1 ++ "/" ++ show mir2
       | mir1 > 0 && mir2 < 0 = "-" ++ show mir1 ++ "/" ++ show (-mir2)
       | mir1 < 0 && mir2 > 0 = "-" ++ show (-mir1) ++ "/" ++ show mir2
       | mir1 < 0 && mir2 < 0 = "+" ++ show (-mir1) ++ "/" ++ show (-mir2)



{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 5
			Cree una función que devuelva como salida la ecuación de la línea recta que pasa los
			puntos A y B los cuales serán dados como parámetro (use tuplas de 2 elementos). Utilice
			la función SHOW, use más de una función.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvEcuacionRecta2

PARÁMETROS
			mir1 -> x1
			mir2 -> y1
			mir3 -> x2
			mir4 -> y2

DESCRIPCIÓN
			Calcula la ecuacion de la linea recta.
-}
jmmvEcuacionRecta2 :: (Show a2, Integral a2) => (a2, a2) -> (a2, a2) -> [Char]
jmmvEcuacionRecta2 (mir1, mir2) (mir3, mir4) = "La ecuacion de la recta es y=" 
 ++ jmmvCoeficienteA ( jmmvSimplificaFraccion ( jmmvPendienteDosPuntos (mir1, mir2) (mir3, mir4) ) ) ++ "x"
 ++ jmmvConstanteC ( jmmvSimplificaFraccion ( jmmvSumFraccionEntero ( jmmvMulFraccionEntero ( jmmvPendienteDosPuntos (mir1, mir2) (mir3, mir4) ) (-mir1) ) mir2 ) )
                                             
                                             

{-
NOMBRE DE LA FUNCION: 
			jmmvPendienteDosPuntos

PARÁMETROS
			mir1 -> x1
			mir2 -> y1
			mir3 -> x2
			mir4 -> y2

DESCRIPCIÓN
			Calcula la pendiete a partir de dos puntos de la recta. Devuelve el valor numerico o fraccional en una tupla.
-}
jmmvPendienteDosPuntos :: Integral b => (b, b) -> (b, b) -> (b, b)
jmmvPendienteDosPuntos (mir1, mir2) (mir3, mir4) = if ((mir4 - mir2) `mod` (mir3 - mir1)) == 0
                                                   then ( (div (mir4 - mir2) (mir3 - mir1) ), 1)
                                                   else jmmvSimplificaFraccion (mir4 - mir2, mir3 - mir1)


{-
NOMBRE DE LA FUNCION: 
			jmmvG y jmmvH

PARÁMETROS
			mir1 -> Numerador
			mir2 -> Denominador

DESCRIPCIÓN
			Verifica si la tupla representa un numero entero o una fraccion.
-}
jmmvCoeficienteA :: (Num a2, Num a1, Ord a1, Ord a2, Show a1, Show a2) => (a1, a2) -> [Char]
jmmvCoeficienteA (mir1, mir2) = if mir2 == 1 then jmmvSignoCoeficienteA mir1 else jmmvNormalizaFraccion (mir1, mir2)

jmmvCoeficienteB :: (Num a2, Num a1, Ord a1, Ord a2, Show a1, Show a2) => (a1, a2) -> [Char]
jmmvCoeficienteB (mir1, mir2) = if mir2 == 1 then jmmvSignoCoeficienteB mir1 else jmmvNormalizaFraccion (mir1, mir2)

jmmvConstanteC :: (Num a2, Num a1, Ord a1, Ord a2, Show a1, Show a2) => (a1, a2) -> String
jmmvConstanteC (mir1, mir2) = if mir2 == 1 then jmmvSignoConstanteC mir1 else jmmvNormalizaFraccionConstanteC (mir1, mir2)



{-
NOMBRE DE LA FUNCION: 
			jmmvMulFraccionEntero

PARÁMETROS
			mir1 -> Numerador
			mir2 -> Denominador
			mir3 -> Número entero

DESCRIPCIÓN
			Realiza una multiplicacion de una fraccion con un número entero de la forma (a, b) * c
-}
jmmvMulFraccionEntero :: Num a => (a, b) -> a -> (a, b)
jmmvMulFraccionEntero ( mir1, mir2 ) mir3 = ( ( mir1 * mir3 ), mir2 )


{-
NOMBRE DE LA FUNCION: 
			jmmvSumFraccionEntero

PARÁMETROS
			mir1 -> Numerador
			mir2 -> Denominador
			mir3 -> Número entero

DESCRIPCIÓN
			Realiza una suma de una fraccion con un número entero de la forma (a, b) + c
-}
jmmvSumFraccionEntero :: Num b => (b, b) -> b -> (b, b)
jmmvSumFraccionEntero ( mir1, mir2 ) mir3 = ( ( mir1 + mir2 * mir3 ), mir2 ) 



{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 6
			Realiza una función para resolver el siguiente tipo de problema:
			Si la razón en que el punto P divide al segmento P1P2 se define como P1P/PP2=-2 y las
			coordenadas de sus extremos son P1(7,4) y P2 (-2,1). ¿Cuáles son las coordenadas del punto P?

			Use tuplas de 2 elementos para pasar como parámetro los puntos P1 y P2. También use
			una tupla de 2 elementos para pasar como parámetro la razón dada ya que, de esta
			manera, la razón podrá ser un entero o una fracción. Para expresar la salida puede usar
			una tupla o lo que usted determine. Analice si es posible el uso de MAS DE UNA función
			y el uso de la función SHOW. Consulte el tema: puntos que dividen segmentos en una razón dada


NOMBRE DE LA FUNCION: 
			jmmvRazonSegmento

PARÁMETROS
			(mir1, mir2) -> Punto P. Coordenada X: mir1. Coordenada Y: mir2
			(mir3, mir4) -> Punto Q. Coordenada X: mir3. Coordenada Y: mir4
			(mir5, mir6) -> Razon. Valor expresado en fracción.

DESCRIPCIÓN
			Calcula las coordenadas del punto R dada una razón en un segmento PQ.
-}
jmmvRazonSegmento :: (Show a2, Integral a2) => (a2, a2) -> (a2, a2) -> (a2, a2) -> [Char]
jmmvRazonSegmento (mir1, mir2) (mir3, mir4) (mir5, mir6) = "El punto R(" 
                   ++ jmmvTuplaToEnteroOrFraccion ( jmmvSimplificaFraccion ( jmmvCoordenadaPuntoRazon (mir1, mir3) (mir5, mir6) ) ) 
                   ++ "," ++ jmmvTuplaToEnteroOrFraccion ( jmmvSimplificaFraccion ( jmmvCoordenadaPuntoRazon (mir2, mir4) (mir5, mir6) ) ) 
                   ++ ") divide al segmento PQ con coordenadas" ++ " P" ++ show (mir1, mir2) ++ " y Q" ++ show (mir3, mir4) 
                   ++ " con una razon r = " ++ jmmvTuplaToEnteroOrFraccion (mir5, mir6)

{-
NOMBRE DE LA FUNCION: 
			jmmvCoordenadaPuntoRazon

PARÁMETROS
			(mir1, mir2) -> Coordenadas X´s o Y´s. Depende de dónde sea llamada; (mir1, mir2) pueden representar (x1, x2) o (y1, y2).
			(mir3, mir4) -> Razón r. Valor expresado en fracción. Numerador: mir3. Denominador: mir4

DESCRIPCIÓN
			Calcula la coordenada X o Y del punto R dada una razón en un segmento PQ. 
-}
jmmvCoordenadaPuntoRazon :: Integral b => (b, b) -> (b, b) -> (b, b)
jmmvCoordenadaPuntoRazon (mir1, mir2) (mir3, mir4) = 
    jmmvDivFraccion ( jmmvSumFraccionEntero ( jmmvMulFraccionEntero (mir3, mir4) mir2 ) mir1 ) ( jmmvSumFraccionEntero (mir3, mir4) 1 )


{-
NOMBRE DE LA FUNCION: 
			jmmvTuplaToEnteroOrFraccion

PARÁMETROS
			(mir1, mir2) -> Fracción. Numerador: mir1. Denominador: mir2

DESCRIPCIÓN
			Convierte una fracción expresada en una tupla a un entero o una fración en notación matemática.
-}
jmmvTuplaToEnteroOrFraccion :: (Num a2, Num a1, Ord a1, Ord a2, Show a1, Show a2) => (a1, a2) -> String
jmmvTuplaToEnteroOrFraccion (mir1, mir2)
       | mir2 == 1 = show mir1
       | mir2 == -1 = show (-mir1)
       | otherwise = jmmvNormalizaFraccion (mir1, mir2)



{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 7
			Elabore una función que determine si tres puntos del plano cartesiano forman una línea
			recta. Investigue lo necesario. Nota: Cada punto estará representado por una tupla de
			dos elementos, el primer elemento es la abscisa y el segundo es el la ordenada. Analice
			si es posible el uso de MAS DE UNA función Ejemplo:

			              palineados (2,1) (4,2) (6,3) ➔ forman una línea recta
			              palineados (2,5) (4,2) (6,6) ➔ No forman una línea recta

-}

{-
NOMBRE DE LA FUNCION: 
			jmmvPuntosRecta

PARÁMETROS
			(mir1, mir2) -> Punto A. Coerdenada X: mir1. Coordenada Y: mir2.
			(mir3, mir4) -> Punto B. Coerdenada X: mir3. Coordenada Y: mir4.
			(mir5, mir6) -> Punto C. Coerdenada X: mir5. Coordenada Y: mir6.

DESCRIPCIÓN
			Determinda si los tres puntos dasos pertencen a una misma recta
-}
jmmvPuntosRecta :: (Eq a, Fractional a) => (a, a) -> (a, a) -> (a, a) -> [Char]
jmmvPuntosRecta (mir1, mir2) (mir3, mir4) (mir5, mir6) =
    if pendienteAB == pendienteAC && pendienteAC == pendienteBC
        then "Forman una linea recta." 
        else "No forman una linea recta"

    where
        pendienteAB = jmmvPendienteDosPuntos2 (mir1, mir2) (mir3, mir4)
        pendienteAC = jmmvPendienteDosPuntos2 (mir1, mir2) (mir5, mir6)
        pendienteBC = jmmvPendienteDosPuntos2 (mir3, mir4) (mir5, mir6)


{-
NOMBRE DE LA FUNCION: 
			jmmvPendienteDosPuntos2

PARÁMETROS
			(mir1, mir2) -> Punto A. Coerdenada X: mir1. Coordenada Y: mir2.
			(mir3, mir4) -> Punto B. Coerdenada X: mir3. Coordenada Y: mir4.

DESCRIPCIÓN
			Calcula la pendiente en tipo real
-}
jmmvPendienteDosPuntos2 :: Fractional a => (a, a) -> (a, a) -> a
jmmvPendienteDosPuntos2 (mir1, mir2) (mir3, mir4) = ( mir4 - mir2 ) / ( mir3 - mir1 )





{----------------------------FUNCIONES DE LAS PRACTICAS 1-3 QUE FUERON UTILIZADAS ---------------------------}


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
