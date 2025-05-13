Algoritmo Main
	Dimension vec[10]
	Dimension vecFinal[3]
	
	Mostrar "Lista de numeros:"
	Para i<-0 Hasta 9 Con Paso 1 Hacer
		vec[i]=aleatorio(1,1000)
		Mostrar " " vec[i] Sin Saltar
	Fin Para
	Mostrar ""
	
	contarMultiplos(vec,vecFinal)
	
	Mostrar "Multiplos de 5: " vecFinal[0]
	Mostrar "Multiplos de 2: " vecFinal[1]
	Mostrar "Multiplos de 3: " vecFinal[2]
	Mostrar ""
	Mostrar "El digito con mayor cantidad de numeros encontrados es " ranking(vecFinal)
	
FinAlgoritmo

SubAlgoritmo contarMultiplos (vec,vecFinal)
	Para i<-0 Hasta 9 Con Paso 1 Hacer
		
		Si (vec[i] mod 5 = 0) Entonces
			vecFinal[0]=vecFinal[0]+1
		Fin Si
		
		Si (vec[i] mod 2 = 0) Entonces
			vecFinal[1]=vecFinal[1]+1
		Fin Si
		
		Si (vec[i] mod 3 = 0) Entonces
			vecFinal[2]=vecFinal[2]+1
		FinSi
	Fin Para
FinSubAlgoritmo

SubAlgoritmo resultado <- ranking(vecFinal)
	Definir resultado Como Entero
	Definir aux Como Entero
	
	aux=vecFinal[0]
	
	Para i<-0 Hasta 2 Con Paso 1 Hacer
		Si (vecFinal[i] >= aux) Entonces
			Segun i Hacer
				caso 0:
					resultado=5
					aux=vecFinal[0]
				caso 1:
					resultado=2
					aux=vecFinal[1]
				caso 3:
					resultado=3
					aux=vecFinal[2]
				De Otro Modo:
					Mostrar "Error."
			Fin Segun
		FinSi
	Fin Para
	
FinSubAlgoritmo


//
//Se dispone de un vector vec de 500 posiciones, cuyos valores son números enteros aleatorios comprendidos entre 1 y 1000.
//
//Se solicita:
//	1. Generar y cargar el (vector vec con valores aleatorios dentro del rango especificado.
//2. Procesar el vector vec para contar la cantidad de numeros que son múltiplos de:
//		-5
//		-2
//		-3
//	3.Almacenar estos conteos en un nuevo vector vecFinal, organizado de la siguiente manera:
//		
//	vecFinal[0]: cantidad de múltiplos de 5
//	vecFinal[1]: cantidad de múltiplos de 2
//	vecFinal[2]: cantidad de múltiplos de 3
//		
//		4. Determinar cuál de los tres tipos de múltiplos es el más frecuente y mostrar el resultado.
//		
//		Tareas para realizar
//		-Implementar un subalgoritmo que genere y cargue vec con valores aleatorios.
//		-Implementar un subalgoritmo que procese vec y cargue vecFinal con los conteos correspondientes.
//		-Desarrollar una función que determine cuál de los tres valores de vecFinal es elmayor e 
//		indique qué tipo de múltiplo predominó.
//		-Mostrar los vectores.