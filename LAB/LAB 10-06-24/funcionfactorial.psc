Algoritmo funcionfactorial
	Definir num, resultado Como Entero
	
	Escribir "Ingrese un numero entero positivo: "
	Leer num
	
	resultado <- CalcularFactorial(num)
	Escribir "El factorial de ", num, " es ", resultado
FinAlgoritmo

Funcion res <- CalcularFactorial(n)
	Mientras n > 0 Hacer
		Escribir n
		res <- n*(n-1)
		n  <- n-1
	FinMientras
FinFuncion
