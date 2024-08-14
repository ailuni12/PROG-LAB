//hacer un programa que inicialmente cargue dos vectores de 10 posiciones
//con numeros al azar entre 1 y 20 y puedan mostrarlos, luego calcule la
//sumatoria de los productos de cada elemento del vector.
//Para ello existen restricciones:
// - Para llevar acabo esta sumatoria de productos
//   los dos valores de cada vector deben ser pares
//Por ultimo informar el resultado.

Algoritmo ejercicio2vectores
	
	definir lista1 Como Entero
	dimension lista1[10]
	definir lista2 Como Entero
	dimension lista2[10]
	definir productosPares Como Entero
	dimension productosPares[10]
	
	definir sumatoriaFinal Como Entero
	
	definir a Como Entero
	
	mostrar "Numeros generados: "
	mostrar "lista 1 / lista 2: "
	para a<-0 hasta (10-1) con paso 1 Hacer
		lista1[a]<- azar(20-1+1)+1
		lista2[a]<- azar(20-1+1)+1
		mostrar lista1[a] " " lista2[a]
	FinPara
	
	mostrar "Productos de todos los numeros pares en ambas listas: "
	para a<-0 hasta (10-1) con paso 1 Hacer
		Si ((lista1[a] mod 2)=0) & ((lista2[a] mod 2)=0) Entonces
			productosPares[a]<-lista1[a]*lista2[a]
		FinSi
		
		Si productosPares[a]<>0 Entonces
			sumatoriaFinal<-sumatoriaFinal+productosPares[a]
			Mostrar productosPares[a] " " Sin Saltar
		FinSi
	FinPara
	
	mostrar " "
	Mostrar "Sumatoria de todos los productos pares obtenidos: ", sumatoriaFinal
	
FinAlgoritmo
