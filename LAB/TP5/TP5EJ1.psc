//	1. Realizar un programa que defina un vector llamado vecNum de 10 enteros, a continuación,
//	lo inicialice con valores aleatorios (del 1 al 10) y posteriormente muestre en pantalla cada
//	elemento del vector junto con su cuadrado y su cubo.

Algoritmo TP5EJ1
	Definir vecNum Como Entero
	dimension vecNum[10]
	Definir i Como Entero
	
	Mostrar "Lista de números generados al azar:"
	Para i<-0 Hasta 10-1 Con Paso 1 Hacer
		vecNum[i]<-ALEATORIO(1,10)
		Mostrar "[", i, "]: ",vecNum[i]
		resultadoCuadrado(vecNum[i])
		resultadoCubo(vecNum[i])
	Fin Para
	
FinAlgoritmo

SubAlgoritmo resultadoCuadrado(numero)
	Mostrar "Cuadrado de ", numero,": ",numero*numero
FinSubAlgoritmo

SubAlgoritmo resultadoCubo(numero)
	Mostrar "Cubo de ", numero,": ",numero*numero*numero
FinSubAlgoritmo


