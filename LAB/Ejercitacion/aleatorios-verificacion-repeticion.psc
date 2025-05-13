//Se requiere crear un algoritmo en PSeInt que permita generar y cargar un vector llamado vec con 10 posiciones.
//	
//1. Cada posición del vector debe contener un valor entero aleatorio entre 1 y 12. No importa el orden en que se 
//generan ni cuáles son los números seleccionados, siempre que sean únicos.
//	
//Generador de azar (por si no recuerdan como era):
//		Azar(CotSup-CotaInf+1) +CotaInf
//		
//	2. No se permiten valores repetidos dentro del vector, lo que implica que cada número guardado en el mismo debe ser único.
//		
//	3. Durante la carga del vector, se deberá verificar que el número aleatorio generado no esté previamente en el vector.
//Si el número ya existe, se deberá generar un nuevo valor aleatorio (siempre entre 1 y 12) hasta encontrar uno que no se haya utilizado.
//			
//Requerimientos:
//· Implementar un subalgoritmo llamado VerificaDigito que reciba el vector cargado hasta el momento y un número generado.
//Este subAlgoritmo deberá devolver un valor lógico indicando si el número ya existe en el vector.
//· Usar un subalgoritmo mostrarVector que recorra el vector y muestre sus valores en una única línea, separados por espacios.
//Al finalizar la carga del vector.
//· La carga del vector deberá ser automática y se SOLO detendrá cuando el vector esté lleno.
//							
//Notas:
//· El rango de números permitidos es de 1 a 12. Como el vector tiene solo 10 posiciones, siempre será posible llenarlo con valores únicos.
//· No se requiere ingreso manual de datos por parte del usuario, para ello les dejo la instrucción azar previamente.

Algoritmo Main
	Dimension vec[10]
	Definir aux Como Entero
	
	Mostrar "Vector con numeros aleatorios del 1 al 12:"
	Para i<-0 Hasta 9 Con Paso 1 Hacer
		aux=Azar(12-1+1)+1
		
		Si (VerificarDigito(vec,aux)=-1) Entonces
			vec[i]=aux
		SiNo
			Mientras (VerificarDigito(vec,aux)=1) Hacer
				aux=Azar(12-1+1)+1
			Fin Mientras
			vec[i]=aux
		Fin Si
		
		Mostrar vec[i] " " Sin Saltar
	Fin Para
	Mostrar ""
	
FinAlgoritmo

SubAlgoritmo posicion <- VerificarDigito ( vec ,num )
	Definir posicion Como Entero
	posicion=-1
	
	Para i<-0 Hasta 9 Con Paso 1 Hacer
		Si vec[i]=num Entonces
			posicion=1
		Fin Si
	Fin Para
Fin SubAlgoritmo

