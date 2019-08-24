doubleMe x = 2 * x

doubleUs x y = doubleMe x + doubleMe 2

doubleSmallNumber x = if (x > 100) then x else (2 * x)

doubleSmallNumber' x = (if x > 100 then x else x*2) + 1

--Intro a listas

--con let asignamos nombres en ghci
fx :: Fractional a => a -> a
fx x = (0.2) + (2*x) + (200 * x^2)

validar :: (Ord p, Fractional p) => p -> p -> p
validar x1 x2 = if (x1 < x2) && (0 <= x1 && x1 <= 1) && (0 <= x2 && x2 <= 1) then areaTrapecio x1 x2 else error "Las condiciones de entrada no son correctas"

areaTrapecio :: Fractional a => a -> a -> a
areaTrapecio x1 x2 = ((fx x2 + fx x1 ) * (x2 - x1))/2

isTrianguloRectangulo a b c 
    | a == max (max a b) c = if cuadrado a == (cuadrado b + cuadrado c) then "Es triangulo rectangulo" else "no mames"
    | b == max (max a b) c = if cuadrado b == (cuadrado b + cuadrado c) then "Es triangulo rectangulo" else "no mames"
    | c == max (max a b) c = if cuadrado c == (cuadrado b + cuadrado c) then "Es triangulo rectangulo" else "no mames"
    | otherwise = "Que vergas hiciste"

cuadrado x = x*x

numeroMmayor a b c 
    | a > b = if b > c then show a ++ show b ++ show c else show a ++ show c ++ show b
    | otherwise = ""

--Ultimo elemento de la lista
jmmvLast [x] = x
jmmvLast (x:xs) = jmmvLast xs


--CASE---------------------------------------------------------------------------
case expresion of patron -> resultado
                  patron -> resultado
                  patron -> resultado
                  ...


head' :: [a] -> a
head' xs = case xs of [] -> error "¡head no funciona con listas vacías!"
                      (x:_) -> x



describeList :: [a] -> String
describeList xs = "La lista es" ++ case xs of []  -> "una lista vacía."
                                              [x] -> "una lista unitaria."
                                              xs  -> "una lista larga."

------------------------------------------------------------------------------------

maximum' :: (Ord a) => [a] -> a
maximum' []     = error "maximum of empty list"
maximum' [x]    = x
maximum' (x:xs) = x `max` (maximum' xs)

--Por ejemplo, replicate 3 5 devuelve [5,5,5].
replicate' :: (Num i, Ord i) => i -> a -> [a]
replicate' n x
    | n <= 0    = []
    | otherwise = x:replicate' (n-1) x

--Esta función toma un cierto número de elementos de una lista. Por ejemplo, take 3 [5,4,3,2,1] devolverá [5,4,3].
take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _
    | n <= 0   = []
take' _ []     = []
take' n (x:xs) = x : take' (n-1) xs




reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort [a | a <- xs, a <= x]
        biggerSorted  = quicksort [a | a <- xs, a > x]
    in  smallerSorted ++ [x] ++ biggerSorted

jmmvCDU :: (Ord a1, Num a1, Num a2, Eq a2) => [Char] -> a1 -> a2 -> [Char]
jmmvCDU [] _ _ = []
jmmvCDU _ mir1 _ | mir1 <= 0 = []
jmmvCDU (x:xs) mir1 mir2 = (if mir2 /= 1 then " | " else "") ++ [x] ++ 
                           case mir1 of 1 -> " Unidaes" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        2 -> " Decenas" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        3 -> " Centenas" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        4 -> " Unidaes de millar" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        5 -> " Decenas de millar" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        6 -> " Centenas de millar" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        7 -> " Unidaes de millon" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        8 -> " Decenas de millon" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        9 -> " Centenas de millon" ++ jmmvCDU xs (mir1 - 1) (mir2 - 1)
                                        otherwise -> error "error case."

                                        --remover las minusculas
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]

--
length' xs = sum [1 | _ <- xs]