--José Manuel Miranda Villagrán

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