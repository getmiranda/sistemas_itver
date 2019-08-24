----"cuatro dos"
--[4,3,2,1]

convDigito num 
    | num <= 0 = []
    | otherwise = if mod residuo 2 == 0
                   then strNum residuo ++ " " ++ convDigito cociente
                   else convDigito cociente
  where 
     cociente = div num 10
     residuo = mod num 10
     par = mod residuo 2 
     digito = head' (toList num)

strNum 0 = "cero"
strNum 1 = "uno"
strNum 2 = "dos"
strNum 3= "tres"
strNum 4 = "cuatro"
strNum 5 = "cinco"
strNum 6 = "seis"
strNum 7 = "siete"
strNum 8 = "ocho"
strNum 9 = "nueve"


--DESCRIPCIÓN: Convierte un numero entero dado en una lista de elementos de sus digitos.
toList :: Integral a => a -> [a]
toList x | x <= 0 = []
    | otherwise = [(mod x 10)] ++ toList (div x 10)

--DESCRIPCIÓN: Obtiene el primer elemento de una lista.
head' :: [a] -> a
head' [] = error "head' no funciona con listas vacías!"
head' (x:xs) = x


ocurrenciaPaar num 
    | (mod residuo 2) == 0 = ocurrenciaPaar cociente
    | otherwise = if mod residuo 2 == 0
                   then 1 + ocurrenciaPaar cociente
                   else ocurrenciaPaar cociente
  where 
     cociente = div num 10
     residuo = mod num 10
     digito = head' (toList num)
