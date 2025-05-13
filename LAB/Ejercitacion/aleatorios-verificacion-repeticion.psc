//Se requiere crear un algoritmo en PSeInt que permita generar y cargar un vector llamado vec con 10 posiciones.
//	
//1. Cada posici�n del vector debe contener un valor entero aleatorio entre 1 y 12. No importa el orden en que se 
//generan ni cu�les son los n�meros seleccionados, siempre que sean �nicos.
//	
//Generador de azar (por si no recuerdan como era):
//		Azar(CotSup-CotaInf+1) +CotaInf
//		
//	2. No se permiten valores repetidos dentro del vector, lo que implica que cada n�mero guardado en el mismo debe ser �nico.
//		
//	3. Durante la carga del vector, se deber� verificar que el n�mero aleatorio generado no est� previamente en el vector.
//Si el n�mero ya existe, se deber� generar un nuevo valor aleatorio (siempre entre 1 y 12) hasta encontrar uno que no se haya utilizado.
//			
//Requerimientos:
//� Implementar un subalgoritmo llamado VerificaDigito que reciba el vector cargado hasta el momento y un n�mero generado.
//Este subAlgoritmo deber� devolver un valor l�gico indicando si el n�mero ya existe en el vector.
//� Usar un subalgoritmo mostrarVector que recorra el vector y muestre sus valores en una �nica l�nea, separados por espacios.
//Al finalizar la carga del vector.
//� La carga del vector deber� ser autom�tica y se SOLO detendr� cuando el vector est� lleno.
//							
//Notas:
//� El rango de n�meros permitidos es de 1 a 12. Como el vector tiene solo 10 posiciones, siempre ser� posible llenarlo con valores �nicos.
//� No se requiere ingreso manual de datos por parte del usuario, para ello les dejo la instrucci�n azar previamente.

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

