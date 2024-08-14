Algoritmo sin_titulo
	Definir tope, i, nroAleatorio Como Entero
	Mostrar "Ingrese tope: "
	Leer tope
	i=0
	Mientras i<tope Hacer
		i=i+1
		nroAleatorio=azar(20-1+1)+1
		Mostrar " ", nroAleatorio Sin Saltar
		
		Si (i mod 5)=0 Entonces
			Mostrar " "
		FinSi

	FinMientras
FinAlgoritmo
