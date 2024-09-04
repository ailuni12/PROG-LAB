//Una línea aérea, American Airlines, vende pasajes en 3 aeropuertos: "Uruguay", "Perú" y
//	"Brasil". En cada uno de ellos, hay 3 empleados que efectúan las ventas. Cada vez que un
//cliente compra pasajes, se requiere la siguiente información:
//	? Número de Aeropuerto
//	? Número de Empleado
//	? Valor del pasaje
//	? Cantidad de pasajeros
//Se pide calcular:
//	a) La cantidad de pasajes vendidos por cada empleado.
//	b) La recaudación por cada aeropuerto.
//	c) El número de empleado que haya vendido la mayor cantidad de pasajes.
//	d) La cantidad de pasajes vendidos por aeropuerto.
//	e) El porcentaje de ventas en pesos de cada empleado.
//	f) El porcentaje de ventas por aeropuerto.
//	g) Ranking de ventas por Aeropuerto de Ordenado de mayor a Menor.
//	La carga de datos finalizará cuando se ingrese un número de aeropuerto igual a cero.

Algoritmo EJ0508VECTORES
	Definir Aeropuerto, Empleado Como Cadenas
	Dimension Aeropuerto[3]
	Dimension Empleado[9]
	Definir codAeropuerto, codEmpleado, nroDePasajerosAep, nroDePasajerosEmpleado Como Entero
	Definir totalVentasAep, totalVentasEmpleado, valorPasaje Como Real
	Dimension totalVentasAep[3]
	Dimension totalVentasEmpleado[9]
	Dimension nroDePasajerosAep[3]
	Dimension nroDePasajerosEmpleado[9]
	
	cargarDatosIniciales(Aeropuerto,Empleado)
	cargaDeUsuario(codAeropuerto,codEmpleado,totalVentasAep,totalVentasEmpleado,nroDePasajerosAep,nroDePasajerosEmpleado)
	
	mostrarDatos(Aeropuerto,Empleado,totalVentasAep,totalVentasEmpleado,nroDePasajerosAep,nroDePasajerosEmpleado)
	
	rankingVentasAep(totalVentasAep)
	
FinAlgoritmo

SubAlgoritmo cargarDatosIniciales(Aeropuerto,Empleado)
	Aeropuerto[0]<-"Uruguay"
	Aeropuerto[1]<-"Peru"
	Aeropuerto[2]<-"Brasil"
	//-----------------------
	Empleado[0]<-"Lopez"
	Empleado[1]<-"Perez"
	Empleado[2]<-"Aguilar"
	Empleado[3]<-"Gonzalez"
	Empleado[4]<-"Gomez"
	Empleado[5]<-"Rodriguez"
	Empleado[6]<-"Fernandez"
	Empleado[7]<-"Diaz"
	Empleado[8]<-"Martinez"
FinSubAlgoritmo

SubAlgoritmo cargaDeUsuario(codAeropuerto,codEmpleado,totalVentasAep,totalVentasEmpleado,nroDePasajerosAep,nroDePasajerosEmpleado)
	Definir valorPasaje Como Real
	Definir pasajeros Como Entero
	
	codAeropuerto<-1
	codEmpleado<-1
	
	Mostrar "Ingrese el Codigo de Aeropuerto (1, 2 o 3). Ingrese 0 para finalizar la carga"
	Repetir
		Mostrar "Ingrese el codigo de Aeropuerto"
		leer codAeropuerto
		
		Mientras codAeropuerto<>1 & codAeropuerto<>2 & codAeropuerto<>3 & codAeropuerto<>0 Hacer
			mostrar "El codigo de Aeropuerto es invalido, ingrese 1, 2 o 3"
			Mostrar "Ingrese el codigo de Aeropuerto"
			Leer codAeropuerto
		FinMientras
		
		Si codAeropuerto<>0 Entonces
			Mostrar "Ingrese el codigo de Empleado"
			Leer codEmpleado
			
			Si codEmpleado<1 | codEmpleado>9 Entonces
				mostrar "El codigo de Empleado es invalido, ingrese un codigo entre 1 y 9"
				Mostrar "Ingrese el codigo de Empleado"
				Leer codEmpleado
			Fin Si
			
			Si codEmpleado>=1 & codEmpleado<=9
				Mostrar "Ingrese el valor total de los pasajes"
				Leer valorPasaje
				totalVentasAep[codAeropuerto-1]<-totalVentasAep[codAeropuerto-1]+valorPasaje
				totalVentasEmpleado[codEmpleado-1]<-totalVentasEmpleado[codEmpleado-1]+valorPasaje
				Mostrar "Ingrese la cantidad de pasajeros"
				Leer pasajeros
				nroDePasajerosAep[codAeropuerto-1]<-nroDePasajerosAep[codAeropuerto-1]+pasajeros
				nroDePasajerosEmpleado[codEmpleado-1]<-nroDePasajerosEmpleado[codEmpleado-1]+pasajeros
			FinSi
		Fin Si

	Mientras Que codAeropuerto<>0

FinSubAlgoritmo

SubAlgoritmo mostrarDatos(Aeropuerto,Empleado,totalVentasAep,totalVentasEmpleado,nroDePasajerosAep,nroDePasajerosEmpleado)
	Definir i Como Entero
	
	Mostrar " "
	
	Para i<-0 hasta 3-1 Con Paso 1 Hacer
		Mostrar "Aeropuerto: ", Aeropuerto[i]
		Mostrar "Total de Ventas: ",totalVentasAep[i]
		Mostrar "Pasajes vendidos: ",nroDePasajerosAep[i]
	FinPara
	
	mostrar " "
	
	Para i<-0 Hasta 9-1 Con Paso 1 Hacer
		Mostrar "Empleado:", Empleado[i]
		Mostrar "Total de Ventas: ", totalVentasEmpleado[i]
		Mostrar "Pasajes vendidos: ", nroDePasajerosEmpleado[i]
	Fin Para
	
FinSubAlgoritmo

SubAlgoritmo rankingVentasAep(totalVentasAep)
	Definir i, j Como Entero
	Definir rankingMayoresVentas, aux como Numero
	Dimension rankingMayoresVentas[3]
	
	Para i<-0 Hasta 3-1 Con Paso 1 Hacer
		rankingMayoresVentas[i]<-totalVentasAep[i]
	FinPara
	
	Para i<-0 Hasta 3-1 Con Paso 1 Hacer
		Para j<-0 hasta i-1 Con Paso 1 Hacer
			Si rankingMayoresVentas[j]<rankingMayoresVentas[j+1] Entonces
				aux<-rankingMayoresVentas[j]
				rankingMayoresVentas[j]<-rankingMayoresVentas[j+1]
				rankingMayoresVentas[j+1]<-aux
			FinSi
		FinPara
	FinPara
	
	Mostrar " "
	Mostrar "Ranking de Ventas por Aeropuerto:"
	
	Para i<-0 Hasta 3-1 Con Paso 1 Hacer
		Mostrar "Aerpuerto ", i+1, ": ", rankingMayoresVentas[i]
	FinPara
	
FinSubAlgoritmo
	