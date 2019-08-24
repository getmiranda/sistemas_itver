#!/usr/bin/env ruby
require 'benchmark'
t1 = Benchmark.realtime do
# ================================
#
# Algoritmo de ordenamiento de burbuja
#
# Ruby es un lenguaje que tiene muchas ventajas, incluyendo metodos de 
# ordenamiento, sin embargo, como una forma de irme familiarizando con el
# lenguaje haré algoritmos clásicos de ordenamiento.
#
#
#
#El usuario ingresa los datos de entrada

=begin
#El usuario ingrasa valores
loop do
  print "Ingresar valor (0 para finalizar):"
  valor = gets.to_i
  if valor == 0
    break
  end
  a << valor
end
=end

#Metodo aleatorio con 1000 valores entre 1 y 1000

	a = []

	for i in 0..9999
		a << rand(1000)
	end


	# El proceso es lo que se tiene que contar

	puts "Tamano del arreglo: #{a.length} \n"
	puts "\n"
	puts "Elementos del arreglo #{a} \n\n"

	# Empezamos con el ordenamiento burbuja en el arreglo a.
	# ------------------------------------------------------

	# elementos tiene el arreglo
	n = a.count - 1

	# count es un método, en este caso regresa la longitud del vector

	#Algoritmo para ordenar
	begin
		intercambio = false
		i = 1
		while i <= n do
			if a[i-1] > a[i] # Si se cumple la condición, entonces intercambiamos.
				aux = a[i-1]
				a[i-1] = a[i]
				a[i] = aux
				intercambio = true
			end # if
	    	i += 1 # El equivalente a i = i + 1 
		end #while i

	end while intercambio == true # Este ciclo se ejecuta mientras haga intercambios.

	# mostrar los resultados.

	# Arreglo ordenado con bubble sort.
	# join se usa para mostrar el arreglo separado por comas.

	puts "\n\nArreglo ordenado = " << a.join(" , ")

end
#Salida para el tiempo transcurrido de la ejecucion del programa

puts "\n\n-----------------------------------------------------------"

puts "Tiempo transcurrido: " + (t1).to_s + " segundos"