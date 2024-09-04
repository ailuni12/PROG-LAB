Algoritmo ejemplovector2
	definir vec Como Entero
	dimension vec[10]
	
	cargar(vec)
	mostrarVector(vec)
FinAlgoritmo

SubAlgoritmo  cargar(vector)
	Definir i Como Entero
	para i<-0 hasta (10-1) con paso 1 Hacer
		vector[i]<- azar(250-50+1)+50
	FinPara
FinSubAlgoritmo

SubAlgoritmo mostrarVector(vector)
	mostrar "Vector: [", i, "] = ", vector[i]
FinSubAlgoritmo