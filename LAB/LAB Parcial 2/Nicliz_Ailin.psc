//Segundo Parcial Laboratorio I 2024 - Ailin Nicliz - Tema 2

Algoritmo SEGUNDOPARCIAL
	Definir clientes Como Numero
	Definir ingresarProducto, ingresarPrecio Como Numero
	Definir i Como Entero
	//columna 0: codigo de clientes
	//columna 1: total que gasto en 1 (Electronicos)
	//columna 2: total que gasto en 2 (Ropa)
	//columna 3: total que gasto en 3 (Alimentos)
	Dimension clientes[3,4]
	ingresarPrecio<-0
	ingresarProducto<-0

	Para i<-0 Hasta 3-1 Con Paso 1 Hacer
		clientes[i,0]<-0
		clientes[i,1]<-0
		clientes[i,2]<-0
		clientes[i,3]<-0
	FinPara
	
	clientes[0,0]<-1
	clientes[1,0]<-2
	clientes[2,0]<-3
	
	cargaPedidos(clientes)
	mostrarPedidos(clientes)

FinAlgoritmo


SubAlgoritmo cargaPedidos(clientes)
	Definir i Como Entero
	Mostrar "Ingrese el codigo de producto de su pedido (1 Electronico, 2 Ropa, 3 Alimentos). Para finalizar la carga ingrese -1:"
	Leer ingresarProducto
	
	Mientras ingresarProducto<>(-1) Hacer
		Mostrar "Ingrese el precio total de su pedido:"
		Leer ingresarPrecio
		
		i<-Aleatorio(1,3)
		clientes[i-1,ingresarProducto]<-clientes[i-1,ingresarProducto]+ingresarPrecio
		Mostrar "Ingrese el codigo de producto de su pedido:"
		Leer ingresarProducto
	FinMientras
FinSubAlgoritmo 


SubAlgoritmo mostrarPedidos(clientes)
	Definir totalElect, totalRopa, totalAlimentos Como Numero
	totalElect<-0
	totalRopa<-0
	totalAlimentos<-0
	
	Mostrar " "
	Mostrar "Pedidos Registrados para cada cliente:"
	Mostrar "Cliente ", clientes[0,0], " Electronicos: $", clientes[0,1], " Ropa: $", clientes[0,2], " Alimentos: $", clientes[0,3]
	Mostrar "Cliente ",clientes[1,0]," Electronicos: $", clientes[1,1], " Ropa: $", clientes[1,2], " Alimentos: $", clientes[1,3]
	Mostrar "Cliente ", clientes[2,0]," Electronicos: $", clientes[2,1]," Ropa: $", clientes[2,2], " Alimentos: $", clientes[2,3]
	Mostrar " "
	
	totalElect<-clientes[0,1]+clientes[1,1]+clientes[2,1]
	totalRopa<-clientes[0,2]+clientes[1,2]+clientes[2,2]
	totalAlimentos<-clientes[0,3]+clientes[1,3]+clientes[2,3]
	
	Mostrar "Total de Ventas segun la categoria de Producto:"
	Mostrar "Total de ventas de Electronicos: $", totalElect
	Mostrar "Total de ventas de Ropa: $", totalRopa
	Mostrar "Total de Ventas de Alimentos: $", totalAlimentos
FinSubAlgoritmo
	