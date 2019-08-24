--José Manuel Miranda Villagrán

jmmvContarDigitosPares :: (Integral t, Num p) => t -> p
jmmvContarDigitosPares mir1 
    | mir1 /= 0 = if ( mir1 `mod` 2 ) == 0 
                  then 1 + (jmmvContarDigitosPares (div mir1 10))
                  else jmmvContarDigitosPares (div mir1 10)
    | otherwise = 0


jmmvListaImpares :: Integral a => [a] -> [a]
jmmvListaImpares (x:xs) = if (x `mod` 2) /= 0 then x : jmmvListaImpares xs else jmmvListaImpares xs
jmmvListaImpares [] = []