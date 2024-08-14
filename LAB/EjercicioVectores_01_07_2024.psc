// Centro de distribución de ventas en el cual vendemos todo tipo de productos, 
// uno en CABA, 2 Corrientes, 3 Misiones y 4 San Luis.
// Vendemos de a un producto por cliente.
// La carga se realizara hasta que el código de cliente sea -1, en ese momento se corta.
// Lo que se le va a pedir al usuario son: Codigo de cliente, código de ciudad, cantidad y precio  .
// Lo que quiero saber yo es:
// 	A - Total de ventas por centro
// 	B - total vendido en general
// 	C - cantidad de productos por centro
// 	D - Quien vendio mas?
Algoritmo EjercicioVectores_01_07_2024
	definir VecCentros Como Caracter // guardo los nombres de cada centro
	definir VecTotVentas Como Real // acumulo las ventas de cada centro
	definir TotalVentas Como Real // total vendido en general
	definir CantProdVend Como Entero // cantidad de productos vendidos por centro
	definir PosMaxventa Como entero // maxima venta
	// dimensionamos los ventores
	Dimension VecCentros[4]
	Dimension VecTotVentas[4]
	Dimension CantProdVend[4]
	InicializarVectores(VecCentros,VecTotVentas,CantProdVend)
	InformaVentas(VecCentros,VecTotVentas,CantProdVend)
	cargaVentas(VecTotVentas,CantProdVend,VecCentros)
	TotalVentas=CalcularTotalVentas(VecTotVentas) 
	PosMaxventa<-CalcularMaximaVenta(VecTotVentas)
	InformaVentas(VecCentros,VecTotVentas,CantProdVend)
	mostrar "----------------------------------------------"
	mostrar "Maxima venta fue realizada por:", VecCentros[PosMaxventa]," con un total de $",VecTotVentas[PosMaxventa]
	mostrar "----------------------------------------------"
FinAlgoritmo
// esto en Pseint no es tan necesario, pero en C si hay que inicializar en Cero
// porque tendria un vector con basura 

subalgoritmo  InicializarVectores(VecCentros,VecTotVentas,CantProdVend)
	VecCentros[0] <- "Caba"
    VecCentros[1] <- "Corrientes"
    VecCentros[2] <- "Misiones"
    VecCentros[3] <- "San Luis"
	Para i <- 0 hasta 4-1
        VecTotVentas[i] <- 0.0
		CantProdVend[i] <- 0
    Fin Para
FinSubAlgoritmo

subalgoritmo  InformaVentas(VecCentros,VecTotVentas,CantProdVend)
	definir j Como Entero
	mostrar "Centros de Venta     Total Ventas    Cantidades Vendidas"
	Para i <- 0 hasta 4-1
        Mostrar "<",i+1,"> ",VecCentros[i] Sin Saltar
		para j<- 0 hasta 25-Longitud(VecCentros[i])
			mostrar " " sin saltar
		FinPara
		mostrar VecTotVentas[i] sin saltar
		mostrar "             " Sin Saltar
		mostrar CantProdVend[i]
    Fin Para
FinSubAlgoritmo

Funcion TotalVentas<-CalcularTotalVentas(VecTotVentas) 
	Definir TotalVentas como real
	TotalVentas <- 0
	Para i <- 0 hasta 4-1
		TotalVentas <- TotalVentas + VecTotVentas[i]
	Fin Para
Fin Funcion

Funcion pos<-CalcularMaximaVenta(VecTotVentas) 
	Definir Max como real
	definir pos como entera
	
	Max <- VecTotVentas[0]
	pos=0
	Para i <- 1 hasta 4-1
		Si VecTotVentas[0]>Max Entonces
			Max<-VecTotVentas[i]
			pos<-i;
		Fin Si
	Fin Para
Fin Funcion

subalgoritmo cargaVentas(VecTotVentas,CantProdVend,VecCentros)
	definir i, cod_cli,centro,cant Como Entero
	definir precio como real
	Mostrar "Ingrese codigo de cliente:<-1> para Finalizar la carga"
	leer cod_cli
	Mientras (cod_cli<>-1)
		Repetir
			mostrar "Ingrese Codigo de centro:"
			leer centro
		mientras Que (centro<1 o centro>4) 
		
		mostrar "Ingrese Cantidad Vendida en ",VecCentros[centro-1]," :"
		leer cant
		mostrar "Ingrese Precio:"
		leer precio
		VecTotVentas[centro-1]=VecTotVentas[centro-1]+(cant*precio)
		CantProdVend[centro-1]=CantProdVend[centro-1]+cant
		Mostrar "Ingrese codigo de cliente::<-1> para Finalizar la carga"
		leer cod_cli
	FinMientras
FinSubAlgoritmo
	