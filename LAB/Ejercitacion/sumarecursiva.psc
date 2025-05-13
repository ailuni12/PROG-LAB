Funcion resultado <- sumarecursiva ( num )
	Definir resultado Como Entero
	
	Si num > 0 Entonces
		resultado = num + sumarecursiva(num-1)
	SiNo
		resultado = 0
	Fin Si
Fin Funcion

Algoritmo Main
	Definir num1 Como Entero
	Dimension array[7]
	
	Mostrar sumarecursiva(9)
FinAlgoritmo


