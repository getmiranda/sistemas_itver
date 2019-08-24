--José Manuel Miranda Villagrán
{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 4
			Construye una función que calcule la sumatoria de los dígitos menores que
			N que pertenecen a un número entero M. La función recibirá dos parámetros
			1) un numero entero M de más de 2 dígitos y 2) un numero entero N de un
			digito (0 a 9). Ejemplo: 
			ctaND 98653 8 => “La suma de los dígitos menores que N en M es 14”
-}

{-
NOMBRE DE LA FUNCION: 
			jmmvCuentaNMPadre, jmmvCuentaNM

PARÁMETROS
			mir1 -> Numero (0-9)
			mir2 -> Cualquier numero > 9

DESCRIPCIÓN
			Calcula la suma de todos los digitos que conforman el numero M que sean menores que mir1.	
-}

jmmvCuentaNMPadre :: (Show a, Integral a) => a -> a -> [Char]
jmmvCuentaNMPadre mir1 mir2 = "La suma de los digitos menores que N en M es " ++ show (jmmvCuentaNM mir1 mir2)

jmmvCuentaNM :: Integral p => p -> p -> p
jmmvCuentaNM mir1 mir2
    | mir1 /= 0 = if residuo < mir2 
                  then residuo + (jmmvCuentaNM (div mir1 10) mir2)
                  else jmmvCuentaNM (div mir1 10) mir2
    | otherwise = 0
    where 
        residuo = mir1 `mod` 10

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 5
			CONSTRUYA UNA FUNCION QUE RECIBA 2 PARAMETROS UNO DE Ellos SERA UN NUMERO ENTERO NEGATIVO
			Y EL OTRO un NUMERO ENTERO POSITIVO. LA FUNCIÓN CONSTRUIDA ENTREGARA COMO SALIDA EL TOTAL
			DE NUMEROS CONTADOS, EL TOTAL DE NUMEROS NEGATIVOS Y EL TOTAL DE NUMEROS POSITIVOS. ejemplo:

			ctaABNP (-6) 6 => “TOTAL DE NUMEROS CONTADOS 12, TOTAL NUMEROS NEGATIVOS 6 TOTAL DE NUMEROS POSITIVOS 6”.

			Use la función show. VERIFIQUE SI EL PROBLEMA SE PUEDE SOLUCIONAR CON MAS DE UNA FUNCIÓN 
			DEFINIDA POR EL USUARIO.
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvCuentaNABPadre, jmmvCuentaNumeros

PARÁMETROS
			mir1 -> Numero entero negativo.
			mir2 -> Numero entero positivo.

DESCRIPCIÓN
			Cuenta los numeros de un rango dado.	
-}
jmmvCuentaNABPadre :: (Ord t, Num t) => t -> t -> [Char]
jmmvCuentaNABPadre mir1 mir2 = "TOTAL NUMEROS CONTADOS> " ++ show (jmmvCuentaNumeros mir1 mir2) ++
                               ". TOTAL NUMEROS NEGATIVOS> " ++ show (jmmvCuentaNumeros mir1 0) ++
                               ". TOTAL NUMEROS POSITIVOS> " ++ show (jmmvCuentaNumeros 0 mir2)

jmmvCuentaNumeros :: (Ord t, Num p, Num t) => t -> t -> p
jmmvCuentaNumeros mir1 mir2
    | mir1 < mir2 = 1 + jmmvCuentaNumeros (mir1 + 1) mir2
    | otherwise = 0


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 6
			Construya una función que reciba como parámetro un numero entero de más de un digito, 
			la función devolverá el parámetro recibido en orden inverso.

			Ejemplo: invN 123 => 321

			Use mas de una función definida por el usuario y la cláusula where
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvInverso

PARÁMETROS
			mir1 -> Numero entero mayor a un digito.

DESCRIPCIÓN
			Invierte un numero entero dado.	
-}
jmmvInverso :: Integral p => p -> p
jmmvInverso mir1
    | mir1 /= 0 = residuo * x + jmmvInverso cociente
    | otherwise = 0
    where
        residuo = mir1 `mod` 10
        cociente = div mir1 10
        x = jmmvPotencia 10 ( (jmmvCuentaDigitos mir1) - 1 )

{-
NOMBRE DE LA FUNCION: 
			jmmvCuentaDigitos

PARÁMETROS
			mir1 -> Numero entero.

DESCRIPCIÓN
			Cuenta los digitos de un numero entero.
-}
jmmvCuentaDigitos :: (Integral t, Num p) => t -> p
jmmvCuentaDigitos mir1
    | mir1 /= 0 = 1 + jmmvCuentaDigitos (div mir1 10)
    | otherwise = 0

{-
NOMBRE DE LA FUNCION: 
			jmmvPotencia

PARÁMETROS
			mir1 -> Base: Numero entero
			mir2 -> Exponente: Numero entero.

DESCRIPCIÓN
			Calcula la potencia de un numero entero.
-}
jmmvPotencia :: (Eq t, Num t, Num p) => p -> t -> p
jmmvPotencia mir1 mir2
    | mir2 /= 0 = mir1 * jmmvPotencia mir1 (mir2 - 1)
    | otherwise = 1


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 7
			Cree una función que verifique si un numero entero dado como parámetro puede leerse igual 
			de derecha a izquierda que de izquierda aderecha
			Ejemplo: 	leeIgual 2002 => “puede leerse igual en ambos sentidos”
						Leelgual 3254 => “se lee diferente en ambos sentidos”

			Utilice mas de una función definida por el usuario, considere utilizar la función construida 
			en el punto 6 finalmente considere utilizar la cláusula “where”
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvIsPalindromo

PARÁMETROS
			mir1 -> Numero entero.

DESCRIPCIÓN
			Verifica si un numero entero es un palindromo.
-}
jmmvIsPalindromo :: Integral a => a -> [Char]
jmmvIsPalindromo mir1 = if mir1 == palindromo
                        then "Puede leerse igual en ambos sentidos."
                        else "Se lee diferente en ambos sentidos."
    where 
       palindromo = jmmvInverso mir1

{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 8
			CREA UNA FUNCION QUE SUME LOS UTIMOS W NUMEROS QUE SE ENCUENTRAN DENTRO DEL RANGO DE A HASTA B.
			W ES UN NUMERO QUE ES PASADO COMO PARAMETRO. DETERMINE LOS DEMAS PARAMETROS Y CONSTRUYA LA FUNCION.

			Ejemplo: si el rango de A hasta B es 1 a 5 y W es igual a 2. La función devolverá 9
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvSumaNW

PARÁMETROS
			mir1 -> A. Numero entero.
			mir2 -> B. Numero entero.
			mir3 -> W. Numero entero.

DESCRIPCIÓN
			Suma los ultimos W numeros del rango A-B.
-}
jmmvSumaNW :: (Eq t1, Num t1, Num p) => t2 -> p -> t1 -> p
jmmvSumaNW mir1 mir2 mir3 
    | mir3 /= 0 = mir2 + jmmvSumaNW mir1 (mir2 - 1) (mir3 - 1)
    | otherwise = 0


{--------------------------------------------------------------------------------------------------
PLANTEAMIENTO DEL PROBLEMA: 9
			Realizar una función que sume DE DOS EN DOS DE DERECHA A IZQUIERDA los dígitos de un número, 
			sumadigDI 123 => 4
-}
{-
NOMBRE DE LA FUNCION: 
			jmmvSumaPosPares

PARÁMETROS
			mir1 -> A. Numero entero.

DESCRIPCIÓN
			Suma los digitos en posiciones pares de un numero entero dado.
-}

jmmvSumaPosPares :: Integral p => p -> p
jmmvSumaPosPares mir1
    | mir1 /= 0 = residuo + jmmvSumaPosPares ( jmmvInverso cociente )
    | otherwise = 0
    where
       inverso = jmmvInverso mir1
       cociente = div inverso 100
       residuo = inverso `mod` 10