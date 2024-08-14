//4. Una persona desea saber en qué día del mes realizó más gastos en
//compras, para ello ingresa por teclado día a día lo que gastó por día, 
//cargando un vector definido en memoria. Puede haber varias o ninguna
//compra para un determinado día. Informar cual fue el día de mayor gasto.

Algoritmo RegistroDeCompras
	Definir gastosDia Como Real
	Dimension gastosDia[32]
	Definir numeroMes Como Entero
	Definir mesActual Como Caracter
	
	Mostrar "Ingrese el numero correspondiente del Mes que quiere registrar (1 a 12):"
	Leer numeroMes
	
	Si 1 <= numeroMes & numeroMes <= 12 entonces
		Segun numeroMes Hacer
			opcion 1:
				mesActual<-'Enero'
			opcion 2:
				mesActual<-'Febrero'
			opcion 3:
				mesActual<-'Marzo'
			opcion 4:
				mesActual<-'Abril'
			opcion 5:
				mesActual<-'Mayo'
			opcion 6:
				mesActual<-'Junio'
			opcion 7:
				mesActual<-'Julio'
			opcion 8:
				mesActual<-'Agosto'
			opcion 9:
				mesActual<-'Septiembre'
			opcion 10:
				mesActual<-'Octubre'
			opcion 11:
				mesActual<-'Noviembre'
			opcion 12:
				mesActual<-'Diciembre'
			De Otro Modo:
				mesActual<-' '
		Fin Segun
		
		ingresarGastoDia(gastosDia)
		Mostrar "Para el mes de ", mesActual, ":"
		compararGastos(gastosDia)
	SiNo
		Mostrar "Debe ingresar un numero de mes valido (1 a 12)."
	FinSi
	
FinAlgoritmo

SubAlgoritmo ingresarGastoDia(gastosDia)
	Definir contadorDia Como Entero
	contadorDia <- 0
	
	Mostrar "Ingrese sus gastos totales para cada dia:"
	Para contadorDia<-0 Hasta (31-1) Con Paso 1 Hacer
		Mostrar "Gastos del dia ", contadorDia+1,":"
		Leer gastosDia[contadorDia]
	Fin Para
	
FinSubAlgoritmo

SubAlgoritmo compararGastos(gastosDia)
	Definir contadorDia Como Entero
	Definir gastoMayor Como Real
	Definir diaGastoMayor Como Entero
	contadorDia <- 0
	gastoMayor <- 0
	diaGastoMayor <- 0
	
	Para contadorDia<-0 Hasta (31-1) Con Paso 1 Hacer
		Si gastosDia[contadorDia] >= gastoMayor Entonces
			diaGastoMayor<-contadorDia+1
			gastoMayor<-gastosDia[contadorDia]
		FinSi
	Fin Para
	
	Mostrar "El mayor gasto registrado fue el dia " diaGastoMayor " con un total de $", gastoMayor
	
FinSubAlgoritmo
