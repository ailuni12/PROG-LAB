//10. Queremos guardar los nombres y las edades de los alumnos de un curso. Realiza un
//programa que introduzca el nombre y la edad de cada alumno. El proceso de lectura de
//	datos terminará cuando se introduzca como nombre un asterisco (*) Al finalizar se mostrará
//los siguientes datos:
//	Los alumnos mayores de edad.
//	Todos los alumnos de mayor a menor edad.

Algoritmo TP5EJ10
	Definir nombreAlumnos, listaNombres Como Cadenas
	Definir edadAlumno, listaEdades Como Entero
	Dimension listaNombres[100]
	Dimension listaEdades[100]
	Definir longitudLista, n Como Entero
	longitudLista<-0
	
	Mostrar "Ingresar los nombres de los alumnos y sus respectivas edades (ingresar * para terminar):"
	Mostrar "Nombre:"
	Leer nombreAlumnos
	Mientras nombreAlumnos<>"*" Hacer
		listaNombres[longitudLista]<-nombreAlumnos
		Mostrar "Edad:"
		Leer edadAlumno
		listaEdades[longitudLista]<-edadAlumno
		longitudLista<-longitudLista+1
		Mostrar "Nombre:"
		Leer nombreAlumnos
	FinMientras
	
	ordenarListas(listaEdades,listaNombres,longitudLista)
	
	mayoresDeEdad(listaEdades,listaNombres,longitudLista)
	
	Mostrar "Alumnos listados, ordenados de mayor a menor:"
	Para n<-0 Hasta longitudLista-1 Con Paso 1 Hacer
		Mostrar "[",n+1,"]: ", listaNombres[n], " Edad: ", listaEdades[n]
	FinPara
	
FinAlgoritmo

SubAlgoritmo ordenarListas(listaEdades,listaNombres,longitudLista)
	Definir i, j, aux1 Como Entero
	Definir aux2 Como Cadena
	
	Para i<-0 Hasta longitudLista-1 Con Paso 1 Hacer
		
		Para j<-0 Hasta longitudLista-i-2 Con Paso 1 Hacer
			Si listaEdades[j]<listaEdades[j+1] Entonces
				aux1<-listaEdades[j]
				listaEdades[j]<-listaEdades[j+1]
				listaEdades[j+1]<-aux1
				
				aux2<-listaNombres[j]
				listaNombres[j]<-listaNombres[j+1]
				listaNombres[j+1]<-aux2
			FinSi
		FinPara
		
	FinPara
	
FinSubAlgoritmo

SubAlgoritmo mayoresDeEdad(listaEdades,listaNombres,longitudLista)
	Definir listaMayoresEdades Como Entero
	Dimension listaMayoresEdades[longitudLista]
	Definir listaNombreMayores Como Cadena
	Dimension listaNombreMayores[longitudLista]
	Definir i, tope Como Entero
	tope<-0
	
	Para i<-0 Hasta longitudLista-1 Con Paso 1 Hacer
		Si listaEdades[i]>=18 Entonces
			tope<-tope+1
		FinSi
	FinPara
	
	Para i<-0 Hasta longitudLista-1 Con Paso 1 Hacer
		Si listaEdades[i]>=18 Entonces
			listaMayoresEdades[i]<-listaEdades[i]
			listaNombreMayores[i]<-listaNombres[i]
		FinSi
	FinPara
	
	Mostrar "Lista de alumnos mayores de edad:"
	Para i<-0 Hasta tope-1 Con Paso 1 Hacer
		Mostrar listaNombreMayores[i]
	FinPara
	
FinSubAlgoritmo
