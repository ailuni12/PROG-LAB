Algoritmo ejemplo3_contador
	Definir tope, i, contd Como Entero
	Mostrar "Ingrese tope: "
	Leer tope
	
	i=0
	contd=0
	
	Mientras i<tope Hacer
		i=i+1
		contd=contd+1
		Mostrar " ", i Sin Saltar
		
		Si contd=5 Entonces
			Mostrar " "
			contd=0
		FinSi
	FinMientras
FinAlgoritmo
