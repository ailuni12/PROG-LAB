Algoritmo areadeuncirculo
	definir radio, area Como Real
	Escribir "Ingrese el radio del circulo: "
	leer radio
	
	area <- CalculoAreaCirculo(radio)
	Escribir "El area del circulo es igual a ", area
FinAlgoritmo

Funcion a <- CalculoAreaCirculo(r)
	a <- PI*r*r
FinFuncion
