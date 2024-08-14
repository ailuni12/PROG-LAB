//1. Leer 10 elementos de un vector de enteros y mostrar su contenido

Algoritmo EJ1listar10numeros
		Definir listaNumeros Como Entero
		Dimension listaNumeros[20]

		generarNumeros(listaNumeros)
		Mostrar "Una lista de numeros se generó correctamente."
		Mostrar "10 elementos de la lista elegidos al azar y su posición en la lista:"
		mostrarLista(listaNumeros)
FinAlgoritmo

SubAlgoritmo generarNumeros(listaNumeros)
	Definir i Como Entero
	
	para i<-0 hasta (20-1) con paso 1 Hacer
		listaNumeros[i]<- azar(500-1+1)+1
	FinPara
	
FinSubAlgoritmo

SubAlgoritmo mostrarLista(listaNumeros)
	Definir i Como Entero
	i <- 0
	Definir posicionLista Como Entero
	posicionLista <- 0
	
	para i<-0 Hasta (10-1) con paso 1 Hacer
			posicionLista<- azar(20-1+1)+1
			Mostrar "[", posicionLista, "]:", listaNumeros[posicionLista], " "
	FinPara
	Mostrar " "

FinSubAlgoritmo
