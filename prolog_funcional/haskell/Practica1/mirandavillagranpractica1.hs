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


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 8
			En una empresa manufacturera el jornal de cada obrero se calcula de la siguiente manera:
			Salario neto = Salario Bruto – Deducciones
			
			Determine los parámetros y realice una función que calcule el salario neto de un empleado, 
			de acuerdo con las siguientes definiciones:

			Salario Bruto = (Salario x hrs trabajadas) + Cuota x exceso de unidades producidas + Ayuda de despensa.

			(Salario por horas trabajadas) es igual al # de horas trabajadas X la cuota por hora. 
			Si el número de horas trabajadas supera las 40, las horas excedentes serán consideradas horas extra. 
			Cada hora extra tiene un costo de 2 ⅓ (7/3) veces la cuota por hora. 
			Después de la octava hora extra, el costo de la hora extra es 3 ⅔ (11/3) veces la cuota por hora.
			
			Cuota x exceso de unidades producidas es igual al 20 % del salario por horas trabajadas siempre 
			que se haya excedido en un 10% el mínimo de unidades producidas a la semana.

			Ayuda de despensa es igual 3% del salario por horas trabajadas multiplicado por el número de hijos.

			DEDUCCIONES
			FICA = 5.2% del salario bruto
			Retención
			Si el empleado tiene más de un hijo
			Retención = (salario por horas trabajadas/5) – 40 x (número de hijos-2),
			Si el empleado tiene un hijo o ninguno la retención será:
			Retención = salario por horas trabajadas / 5

-}


{-
NOMBRE DE LA FUNCION: 
			jmmvSalarioNeto

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de unidades producidas.
			mir4 -> Numero minimo de unidades producidas
			mir5 -> Numero de hijos.

DESCRIPCIÓN
			Calcula el salario neto
-}
jmmvSalarioNeto :: (Ord a1, Ord a2, Fractional a1, Fractional a2) => a1 -> a1 -> a2 -> a2 -> a1 -> a1
jmmvSalarioNeto mir1 mir2 mir3 mir4 mir5 = jmmvSalarioBruto mir1 mir2 mir3 mir4 mir5 - jmmvDeducciones mir1 mir2 mir3 mir4 mir5

{-
NOMBRE DE LA FUNCION: 
			jmmvSalarioBruto

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de unidades producidas.
			mir4 -> Numero minimo de unidades producidas
			mir5 -> Numero de hijos.

DESCRIPCIÓN
			Calcula el salario bruto
-}
jmmvSalarioBruto :: (Ord a1, Ord a2, Fractional a1, Fractional a2) =>a1 -> a1 -> a2 -> a2 -> a1 -> a1
jmmvSalarioBruto mir1 mir2 mir3 mir4 mir5 = jmmvSalarioXHorasTrabajadas mir1 mir2 
                                          + jmmvCuotaXExcesoUnidades mir3 mir4 mir1 mir2 
                                          + jmmvAyudaDespensa mir5 mir1 mir2

{-
NOMBRE DE LA FUNCION: 
			jmmvSalarioXHorasTrabajadas

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.

DESCRIPCIÓN
			Calcula el salario por as hors trabajadas
-}
jmmvSalarioXHorasTrabajadas :: (Ord a, Fractional a) => a -> a -> a
jmmvSalarioXHorasTrabajadas mir1 mir2 
        | mir1 > 0 && mir1 <= 40   = mir1 * mir2
        | mir1 > 40  && mir1 <= 48 = horasBase + horas40y48
        | mir1 > 48                = horasBase + horas40y48 + horasMayor48
    where 
        horasBase = ( 40 * mir2 )
        horas40y48 = ( (7 / 3) * mir2 ) * ( mir1 - 40 )
        horasMayor48 = ( (11 / 3) * mir2 ) * ( mir1 - 48 )


{-
NOMBRE DE LA FUNCION: 
			jmmvCuotaXExcesoUnidades

PARÁMETROS
			mir1 -> Numero de unidades producidas.
			mir2 -> Numero minimo de unidades producidas.
			mir3 -> Numero de horas trabajadas.
			mir4 -> Cuota por hora.

DESCRIPCIÓN
			Calcula la la cuota por exceso de unidades
-}
jmmvCuotaXExcesoUnidades :: (Ord a, Ord p, Fractional p, Fractional a) => a -> a -> p -> p -> p
jmmvCuotaXExcesoUnidades mir1 mir2 mir3 mir4 = if  ( mir1 > ( mir2 + diezPorciento ) ) then veintePorciento else 0
    where 
        diezPorciento = 0.10 * mir2
        veintePorciento = 0.20 * jmmvSalarioXHorasTrabajadas mir3 mir4


{-
NOMBRE DE LA FUNCION: 
			jmmvAyudaDespensa

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de hijos.

DESCRIPCIÓN
			Calcula la ayuda de la despensa
-}
jmmvAyudaDespensa :: (Fractional a, Ord a) => a -> a -> a -> a
jmmvAyudaDespensa mir1 mir2 mir3 = mir3 * (0.03 * jmmvSalarioXHorasTrabajadas mir1 mir2 )


{-
NOMBRE DE LA FUNCION: 
			jmmvDeducciones

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de unidades producidas.
			mir4 -> Numero minimo de unidades producidas
			mir5 -> Numero de hijos.

DESCRIPCIÓN
			Calcula deducciones
-}
jmmvDeducciones :: (Ord a1, Ord a2, Fractional a1, Fractional a2) => a1 -> a1 -> a2 -> a2 -> a1 -> a1
jmmvDeducciones mir1 mir2 mir3 mir4 mir5 = jmmvFICA mir1 mir2 mir3 mir4 mir5 + jmmvRetencion mir1 mir2 mir5

{-
NOMBRE DE LA FUNCION: 
			jmmvFICA

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de unidades producidas.
			mir4 -> Numero minimo de unidades producidas
			mir5 -> Numero de hijos.

DESCRIPCIÓN
			Calcula FICA
-}
jmmvFICA :: (Ord a1, Ord a2, Fractional a1, Fractional a2) => a1 -> a1 -> a2 -> a2 -> a1 -> a1
jmmvFICA mir1 mir2 mir3 mir4 mir5 = (jmmvSalarioBruto mir1 mir2 mir3 mir4 mir5) * 0.052


{-
NOMBRE DE LA FUNCION: 
			jmmvRetencion

PARÁMETROS
			mir1 -> Numero de horas trabajadas.
			mir2 -> Cuota por hora.
			mir3 -> Numero de hijos.

DESCRIPCIÓN
			Calcula retencion
			DEDUCCIONES
			FICA = 5.2% del salario bruto
			Retención
			Si el empleado tiene más de un hijo
			Retención = (salario por horas trabajadas/5) – 40 x (número de hijos-2),
			Si el empleado tiene un hijo o ninguno la retención será:
			Retención = salario por horas trabajadas / 5
-}
jmmvRetencion :: (Ord a, Fractional a) => a -> a -> a -> a
jmmvRetencion mir1 mir2 mir3 
       | mir3 > 1 = ( jmmvSalarioXHorasTrabajadas mir1 mir2 ) / 5 - 40 * ( mir3 - 2 )
       | otherwise = ( jmmvSalarioXHorasTrabajadas mir1 mir2 ) / 5

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 9
			Una librería estima los precios de sus libros de la siguiente forma: El precio básico 
			de un libro es de $5.00 más $0.20 por página. Sin embargo, si el número de páginas excede 
			de 300, el precio sufrirá un recargo adicional de $10.00 y 0.75 por página excedente. Además, 
			si el número de páginas excede de 550 el precio se incrementará en otros $8.50 y $1.00 por 
			página excedente. Determine cuáles serán los parámetros de la función y cree una función que
			realice el cálculo descrito. Use mas de una función.

-}

{-
NOMBRE DE LA FUNCION: 
			jmmvLibro

PARÁMETROS
			mir1 -> Numero de paginas.

DESCRIPCIÓN
			Calcular el costo del libro
-}

jmmvLibro :: (Ord a, Fractional a) => a -> a
jmmvLibro mir1 
    | mir1 > 0 && mir1 <= 300   = 5 + ( 0.20 * mir1 )
    | mir1 > 300 && mir1 <= 550 = libroBasico + ( ( (mir1 - 300) * 0.75) + 10 )
    | mir1 > 550 = libroBasico + libro300y550 + ( ( (mir1 - 550) * 1) + 8.5 )
    where 
        libroBasico = 5 + ( 0.20 * 300 )
        libro300y550 = 10 + ( 0.75 * 250 )


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 10
			Una librería estima los precios de sus libros de la siguiente forma: El precio básico 
			de un libro es de $5.00 más $0.20 por página. Sin embargo, si el número de páginas excede 
			de 300, el precio sufrirá un recargo adicional de $10.00 y 0.75 por página excedente. Además, 
			si el número de páginas excede de 550 el precio se incrementará en otros $8.50 y $1.00 por 
			página excedente. Determine cuáles serán los parámetros de la función y cree una función que
			realice el cálculo descrito. Use mas de una función.

-}

{-
NOMBRE DE LA FUNCION: 
			jmmvLibro2

PARÁMETROS
			mir1 -> Numero de paginas.

DESCRIPCIÓN
			Calcular el costo del libro. Usando clausula Let
-}
jmmvLibro2 :: (Ord a, Fractional a) => a -> a
jmmvLibro2 mir1 = 
    let libroBasico = 5 + ( 0.20 * 300 )
        libro300y550 = 10 + ( 0.75 * 250 )
        libroMas550 = 8.5 + ( 1 * ( mir1 - 550 ) )
    in
        if mir1 > 550
        then libroBasico + libro300y550 + libroMas550
        else if mir1 > 300
        then (10 + (mir1 - 300) * 0.75) + libroBasico
        else (mir1 * 0.20) + 5


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 11
			Definir la función mayor tal que mayor x y w devuelva como resultado el mayor número
			de tres cifras que puede construirse con los dígitos x, y, w Por ejemplo:

										mayor 251 ➔ 521
										mayor 125 ➔ 521
										mayor 512 ➔ 521
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvMayor

PARÁMETROS
			mir1 -> primer digito
			mir2 -> segundo digito
			mir3 -> tercer digito

DESCRIPCIÓN
			Calcular el numero mayor que se puede formar con los tres dígitos introducidos como parametros.
-}
jmmvMayor :: (Ord a, Show a) => a -> a -> a -> [Char]
jmmvMayor mir1 mir2 mir3 
    | (mir1 == mir2) && (mir2 == mir3) = "Los tres parametros son iguales."
    | mir1 == mir2 = "El primer parametro y el segundo son iguales."
    | mir1 == mir3 = "El primer parametro y el tercero son iguales."
    | mir2 == mir3 = "El segundo parametro y el tercero son iguales."
    | mir1 > mir2 && mir1 > mir3 = if (mir2 > mir3) then show mir1 ++ show mir2 ++ show mir3 else show mir1 ++ show mir3 ++ show mir2
    | mir2 > mir1 && mir2 > mir3 = if (mir1 > mir3) then show mir2 ++ show mir1 ++ show mir3 else show mir2 ++ show mir3 ++ show mir1
    | mir3 > mir1 && mir3 > mir2 = if (mir1 > mir2) then show mir3 ++ show mir1 ++ show mir2 else show mir3 ++ show mir2 ++ show mir1



{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 12
			Construya una función que convierta los segundos dados a horas, minutos y segundos.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvConvertSeg, jmmvHoras, jmmvMin, jmmvSeg

PARÁMETROS
			mir1 -> Segundos introducidos por el usuario

DESCRIPCIÓN
			Funciones que colaboran entre si para convertir los segundos a hora estandar
-}
jmmvConvertSeg :: (Show a, Integral a) => a -> [Char]
jmmvConvertSeg mir1 = show mir1 ++ " segundos. -> " ++ jmmvHoras mir1

jmmvHoras :: (Show a, Integral a) => a -> [Char]
jmmvHoras mir1 = show (div mir1 3600) ++ " Hora(s) " ++ jmmvMin (mir1 `mod` 3600)

jmmvMin :: (Show a, Integral a) => a -> [Char]
jmmvMin mir1 = show (div mir1 60) ++ " Minuto(s) " ++ jmmvSeg (mir1 `mod` 60)

jmmvSeg :: Show a => a -> [Char]
jmmvSeg mir1 = show mir1 ++ " Segundo(s)."

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 13
			Investigue como usar la cláusula WHERE del lenguaje Haskell. Construya una función
			que resuelva el problema anterior (inciso 12) usando la cláusula mencionada (WHERE).
			Utilice los mismos datos de prueba.
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvConvertSeg2

PARÁMETROS
			mir1 -> Segundos introducidos por el usuario.

DESCRIPCIÓN
			Funcion que convierte los segundos a hora estandar.
-}

jmmvConvertSeg2 mir1 = show mir1 ++ " segundos. -> " ++ horas mir1 ++ min resHoras ++ seg resMin
    where
        horas mir1 = show (div mir1 3600) ++ " Hora(s) "
        min mir1  = show (div mir1 60) ++ " Minuto(s) "
        seg mir1  = show mir1 ++ " Segundo(s)."
        resHoras  = mir1 `mod` 3600
        resMin    = resHoras `mod` 60
