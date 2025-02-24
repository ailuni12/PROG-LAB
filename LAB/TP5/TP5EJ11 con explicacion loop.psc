//11. Queremos guardar la temperatura m�nima y m�xima de 7 d�as. realiza un programa que
//	de la siguiente informaci�n:
//	La temperatura media de cada d�a.
//	Todos los d�as de menor a mayor temperatura media por d�a.
//	Se lee una temperatura por teclado y se muestran los d�as cuya temperatura m�xima coincide con
//	ella. Si no existe ning�n d�a se muestra un mensaje de informaci�n.

Algoritmo TP5EJ11
	Definir dia, tempsRegistradas, rankingTemps como numeros
	
	dimension dia[7], tempsRegistradas[7,3], rankingTemps[7,2]

	registrarTemps(dia,tempsRegistradas)
	ordenarDias(tempsRegistradas,rankingTemps)

FinAlgoritmo

SubAlgoritmo registrarTemps(dia,tempsRegistradas)
	definir i Como Entero
	Para i<-0 Hasta 7-1 Con Paso 1 Hacer
		Mostrar "Ingresar temperatura minima y maxima para el d�a ", i+1,":"
		dia[i]<-i+1
		Mostrar "Temp Minima:"
		Leer tempsRegistradas[i,0]
		Mostrar "Temp Maxima:"
		Leer tempsRegistradas[i,1]
		tempsRegistradas[i,2]<-(tempsRegistradas[i,0]+tempsRegistradas[i,1])/2
		Mostrar "Media del d�a: ", tempsRegistradas[i,2]
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
		
		mostrar "loop: ", i, " i vale ",i

		Para j<-0 Hasta 6-i-1 Con Paso 1 Hacer
			Si rankingTemps[j,1]>rankingTemps[j+1,1] Entonces
				Mostrar rankingTemps[0,1], " ",rankingTemps[1,1], " ",rankingTemps[2,1], " ", rankingTemps[3,1], " ", rankingTemps[4,1], " ", rankingTemps[5,1], " ", rankingTemps[6,1]
				
				aux<-rankingTemps[j,1]
				rankingTemps[j,1]<-rankingTemps[j+1,1]
				rankingTemps[j+1,1]<-aux
				
				Mostrar "i dentro del 2do loop: ",i
				Mostrar "j: ",j
				Mostrar rankingTemps[0,1], " ",rankingTemps[1,1], " ",rankingTemps[2,1], " ", rankingTemps[3,1], " ", rankingTemps[4,1], " ", rankingTemps[5,1], " ", rankingTemps[6,1]
				mostrar " "
			FinSi
		FinPara
		
		mostrar " "
	FinPara
	
	
	Mostrar "Temperaturas Medias, de menor a mayor:"
	Para j<-0 Hasta 7-1 Con Paso 1 Hacer
		Mostrar "[", j+1,"]: ", rankingTemps[j,1]
	FinPara
FinSubAlgoritmo

