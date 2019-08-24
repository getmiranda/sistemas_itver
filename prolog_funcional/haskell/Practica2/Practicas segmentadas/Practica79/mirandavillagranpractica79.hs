--José Manuel Miranda Villagrán
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


 {--------------------------------------------------------------------------------------------------
	Funciones usadas de la practica anterior para resolver los problemas 7, 8 y 9
-}

jmmvInverso :: Integral p => p -> p
jmmvInverso mir1
    | mir1 /= 0 = residuo * x + jmmvInverso cociente
    | otherwise = 0
    where
        residuo = mir1 `mod` 10
        cociente = div mir1 10
        x = jmmvPotencia 10 ( (jmmvCuentaDigitos mir1) - 1 )


jmmvCuentaDigitos :: (Integral t, Num p) => t -> p
jmmvCuentaDigitos mir1
    | mir1 /= 0 = 1 + jmmvCuentaDigitos (div mir1 10)
    | otherwise = 0


jmmvPotencia :: (Eq t, Num t, Num p) => p -> t -> p
jmmvPotencia mir1 mir2
    | mir2 /= 0 = mir1 * jmmvPotencia mir1 (mir2 - 1)
    | otherwise = 1