--José Manuel Miranda Villagrán

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
jmmvConvertSeg2 :: (Show a, Integral a) => a -> [Char]
jmmvConvertSeg2 mir1 = show mir1 ++ " segundos. -> " ++ horas mir1 ++ min resHoras ++ seg resMin
    where
        horas mir1 = show (div mir1 3600) ++ " Hora(s) "
        min mir1  = show (div mir1 60) ++ " Minuto(s) "
        seg mir1  = show mir1 ++ " Segundo(s)."
        resHoras  = mir1 `mod` 3600
        resMin    = resHoras `mod` 60
