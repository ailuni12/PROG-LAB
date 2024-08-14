//11. Queremos guardar la temperatura mínima y máxima de 7 días. realiza un programa que
//	de la siguiente información:
//	La temperatura media de cada día.
//	Todos los días de menor a mayor temperatura media por día.
//	Se lee una temperatura por teclado y se muestran los días cuya temperatura máxima coincide con
//	ella. Si no existe ningún día se muestra un mensaje de información.

Algoritmo TP5EJ11
	Definir dia, tempsRegistradas, rankingTemps como numeros
	
	dimension dia[7], tempsRegistradas[7,3], rankingTemps[7,2]

	registrarTemps(dia,tempsRegistradas)
	ordenarDias(tempsRegistradas,rankingTemps)
	buscarTemp(tempsRegistradas)

FinAlgoritmo

SubAlgoritmo registrarTemps(dia,tempsRegistradas)
	definir i Como Entero
	Para i<-0 Hasta 7-1 Con Paso 1 Hacer
		Mostrar "Ingresar temperatura minima y maxima para el día ", i+1,":"
		dia[i]<-i+1
		Mostrar "Temp. Minima:"
		Leer tempsRegistradas[i,0]
		Mostrar "Temp. Maxima:"
		Leer tempsRegistradas[i,1]
		tempsRegistradas[i,2]<-(tempsRegistradas[i,0]+tempsRegistradas[i,1])/2
		Mostrar "Temp. Media del día: ", tempsRegistradas[i,2]
	Fin Para
FinSubAlgoritmo

SubAlgoritmo ordenarDias(tempsRegistradas,rankingTemps)
	definir i Como Entero
	definir j Como Entero
	j<-0
	definir aux Como Numero
	aux<-0
	Para i<-0 Hasta 7-1 Con Paso 1 Hacer
		rankingTemps[i,0]<-i+1
		rankingTemps[i,1]<-tempsRegistradas[i,2]
	Fin Para
	
	Para i<-0 Hasta 7-1 Con Paso 1 Hacer

		Para j<-0 Hasta 6-i-1 Con Paso 1 Hacer
			Si rankingTemps[j,1]>rankingTemps[j+1,1] Entonces
				aux<-rankingTemps[j,1]
				rankingTemps[j,1]<-rankingTemps[j+1,1]
				rankingTemps[j+1,1]<-aux
			FinSi
		FinPara
		
	FinPara
	
	Mostrar "Temperaturas Medias, de menor a mayor:"
	Para j<-0 Hasta 7-1 Con Paso 1 Hacer
		Mostrar "[", j+1,"]: ", rankingTemps[j,1]
	FinPara
FinSubAlgoritmo

SubAlgoritmo buscarTemp(tempsRegistradas)
	Definir i Como Entero
	Definir temp Como Numero
	
	Mostrar "Ingrese la temperatura que desea buscar:"
	Leer temp
	
	Para i<-0 Hasta 7-1 Con Paso 1 Hacer
		Si tempsRegistradas[i,1]=temp Entonces
			Mostrar "El dia ", i+1, " COINCIDE, con temperatura máxima registrada de ", tempsRegistradas[i,1]
		SiNo
			Mostrar "El día ", i+1, " no se registro esa temperatura."
		FinSi
	FinPara
	
FinSubAlgoritmo

