--José Manuel Miranda Villagrán
{-
NOMBRE DE LA FUNCION: 
			jmmvIsTrianguloEscaleno

PARÁMETROS
			(mir1, mir2) -> Punto A. Coerdenada X: mir1. Coordenada Y: mir2.
			(mir3, mir4) -> Punto B. Coerdenada X: mir3. Coordenada Y: mir4.
			(mir5, mir6) -> Punto C. Coerdenada X: mir5. Coordenada Y: mir6.

DESCRIPCIÓN
			Calcula si los puntos forman un triangulo ecaleno
-}

jmmvIsTrianguloEscaleno :: (Eq a, Show a, Floating a) => (a, a) -> (a, a) -> (a, a) -> [Char]
jmmvIsTrianguloEscaleno (mir1, mir2) (mir3, mir4) (mir5, mir6) =
    if (dAB /= dBC) && (dBC /= dCA)
    then "Es un triangulo escaleno. AB = " ++ show dAB ++ " BC = " ++ show dBC ++ "y CA = " ++ show dCA
    else "No es un triangulo escaleno. AB = " ++ show dAB ++ " BC = " ++ show dBC ++ " y CA = " ++ show dCA

      where
         dAB = jmmvDistanciaPuntos (mir1, mir2) (mir3, mir4)
         dBC = jmmvDistanciaPuntos (mir3, mir4) (mir5, mir6)
         dCA = jmmvDistanciaPuntos (mir5, mir6) (mir1, mir2)

{-
NOMBRE DE LA FUNCION: 
            jmmvDistanciaPuntos

PARÁMETROS
            (mir1, mir2) -> Punto A. Coerdenada X: mir1. Coordenada Y: mir2.
            (mir3, mir4) -> Punto B. Coerdenada X: mir3. Coordenada Y: mir4.

DESCRIPCIÓN
            Calcula la distancia de dos puntos dados
-}
jmmvDistanciaPuntos :: Floating a => (a, a) -> (a, a) -> a
jmmvDistanciaPuntos (mir1, mir2) (mir3,mir4) = sqrt (jmmvCuadrado (mir3-mir1) + jmmvCuadrado (mir4-mir2))


{-
NOMBRE DE LA FUNCION: 
            jmmvCuadrado

PARÁMETROS
            mir1 -> Cualquier numero

DESCRIPCIÓN
            Calcula el cuadrado de un numero
-}
jmmvCuadrado :: Num a => a -> a
jmmvCuadrado mir1 = mir1 * mir1