Algoritmo sin_titulo
	definir num1, divisor, contdPrimos Como Entero
	definir cociente como real
	
	Mostrar "Ingrese un numero:"
	Leer num1
	
	divisor=1
	
	Mientras divisor<=num1 Hacer
		Mientras  (num1 mod divisor <> 0) Hacer
			divisor=divisor+1
			Mostrar num1/divisor
		FinMientras
	FinMientras
	
FinAlgoritmo
