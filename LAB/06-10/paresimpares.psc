Algoritmo paresimpares
	Definir num, pares, impares, sumaPares, SumaImpares como Entero
	Escribir "Ingrese un numero entero positivo para visualizar su tabla de multiplicar: "
	Leer num
	
	Si num > 0 Entonces
		
		Si (num mod 2) = 0 Entonces
			Escribir "numeros pares hasta ", num, ":"
			Mientras num > 0 Hacer
				Escribir num, " " Sin Saltar
				pares <- num-2
			FinMientras
			
			Escribir "numeros impares hasta ", num, ":"
			Mientras num > 0 Hacer
				Escribir num, " " Sin Saltar
				impares <- num-1
			FinMientras
		FinSi
		
		Si (num mod 2) <> 0 Entonces
		FinSi
		
	SiNo
		Escribir "El numero ingresado debe ser positivo y mayor a 0."
	FinSi
	
FinAlgoritmo