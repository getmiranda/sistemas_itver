require 'benchmark'
t1 = Benchmark.realtime do
	a = []
	for i in 0..9999
		a << rand(1000)
	end
	puts "Tamano del arreglo: #{a.length} \n\n"
	puts "Elementos del arreglo #{a} \n\n"
	class Array
	  def quick_sort                    
	    return self if length <= 1      
	    pivote = self[length / 2]       
	    find_all { |i| i <  pivote }.quick_sort +  
	      find_all { |i| i == pivote } +            
	      find_all { |i| i >  pivote}.quick_sort    
	  end
	end
	puts "a = " << a.quick_sort.join(" , ")
end
puts "\n\n-----------------------------------------------------------"
puts "Tiempo transcurrido: " + (t1).to_s + " segundos"