//Dado un vector cargado al azar llamado vec1
//con 20 numeros en forma aleatoria entre 50 y 375
//se pide poder cargar un vector llamado vecPares
//con todos los numeros pares posibles que se encuentren
//dentro del vector original vec1
//informar el vector original vec1
//informar el vector vecPares

Algoritmo ejercicio1
	Definir i Como Entero
	
	Definir vec1 Como Entero
	Dimension vec1[20]
	
	Definir vecPares Como Entero
	Dimension vecPares[20]

	generarNumeros(vec1, vecPares)
	mostrarPares(vecPares)
FinAlgoritmo

SubAlgoritmo generarNumeros(vector1, vecParesLista)
	para i<-0 hasta (20-1) con paso 1 Hacer
		vector1[i]<- azar(375-50+1)+50
		
		Si ((vector1[i] Mod 2)=0) Entonces
			vecParesLista[i]<-vector1[i]
		FinSi
		
		mostrar "Vector: [", i, "] = ", vector1[i]
	FinPara
FinSubAlgoritmo

SubAlgoritmo mostrarPares(vecParesLista)
	Mostrar "Numeros pares en la lista: "
	para i<-0 Hasta (20-1) con paso 1 Hacer
		Si ((vecParesLista[i] Mod 2)=0) & vecParesLista[i]<>0 Entonces
			Mostrar vecParesLista[i], " " Sin Saltar
		FinSi
	FinPara
	Mostrar " "
FinSubAlgoritmo

	