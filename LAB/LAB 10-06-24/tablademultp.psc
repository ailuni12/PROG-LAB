Algoritmo tablademultp
	Definir num, multp como Entero
	Escribir "Ingrese un numero entero positivo para visualizar su tabla de multiplicar: "
	Leer num
	
	Si num >= 0 Entonces
		Para multp <- 1 hasta 10 con paso 1 Hacer
			Escribir num, " x ", multp, " = ", num*multp
		FinPara
	SiNo
		Escribir "El numero ingresado debe ser positivo o 0."
	FinSi

FinAlgoritmo
	