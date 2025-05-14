
Algoritmo Calcula_Capicua
	definir capaMax,tot_capicua como entero 
	Definir i como Entero
	capaMax=5
	dimx=capaMax-1
	tot_capicua=0
	Dimension Vec[capaMax]
	CargarVector(Vec, dimx)
	mostrar "--------------------"
	Mostrar "       Vector       "
	mostrar "--------------------"
	MuestraVector(Vec,dimx)
	
    // AQUI LLAMAR A LA FUNCION PARA QUE RESUELVA 
	// LOS DATOS QUE ESTA EN EL VECTOR vec
	
	Para i<-0 Hasta dimx Con Paso 1 Hacer
		Si EsCapicua(vec[i])=1 Entonces
			Mostrar ""
			Mostrar "El numero " vec[i] " es CAPICUA."
			tot_capicua=tot_capicua+1
			Mostrar ""
 		SiNo
			Mostrar ""
			Mostrar "El numero " vec[i] " NO es capicua."
			Mostrar ""
		Fin Si
	Fin Para
	
	Mostrar ""
	Mostrar "Total de capicuas encontrados: " tot_capicua
	
FinAlgoritmo


SubAlgoritmo CargarVector(v,x)
	
	v[0]=123445
	v[1]=12321
	v[2]=72327
	v[3]=76542
	v[4]=120021
	
FinsubAlgoritmo

SubAlgoritmo  MuestraVector(v,x)
	Para i <- 0 Hasta x Hacer
		Mostrar "valor :",i+1," = ",v[i]
	FinPara
	mostrar"-----------------------"
FinSubAlgoritmo

Funcion n<-EsCapicua(num)
	Definir aux1, aux2, inverso Como Real
	
	aux1=num
	
	Mientras aux1>=1 Hacer
		aux2=aux1 mod 10
		aux1=trunc(aux1/10)
		inverso=inverso*10+aux2 mod 10
		
		Mostrar "aux2: " aux2 " aux1: " aux1 " inverso: " inverso
	Fin Mientras

	Si num = inverso Entonces
		n=1
	SiNo
		n=0
	Fin Si

FinFuncion
