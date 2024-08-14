Algoritmo sin_titulo
	definir dado1, dado2, cantidadTiradas, tope, contd7, contd2, contd12 Como Entero
	
	cantidadTiradas=0
	contd7=0
	contd2=0
	contd12=0
	
	Mostrar "Cuantas veces quieres tirar los dados? (1 Tirada = 2 dados): "
	Leer tope
	
	Mientras cantidadTiradas<tope hacer
		cantidadTiradas=cantidadTiradas+1
		dado1=azar(6-1+1)+1
		dado2=azar(6-1+1)+1
		
		Segun dado1+dado2 hacer
			7: contd7=contd7+1
			2: contd2=contd2+1
			12: contd12=contd12+1
		FinSegun
		
		Si (tope<50) Entonces
			mostrar dado1, " ", dado2, " total: ", dado1+dado2 Sin Saltar
			mostrar " "
		FinSi
		
	FinMientras
	
	mostrar "Total de Tiradas: ", tope
	mostrar "Resultado 2: ", contd2
	mostrar "Resultado 7: ", contd7
	mostrar "Resultado 12: ", contd12

FinAlgoritmo
