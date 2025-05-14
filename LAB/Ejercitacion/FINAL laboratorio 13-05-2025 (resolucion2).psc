
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
		Si EsCapicua(vec[i],contar(vec[i]))=1 Entonces
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

Funcion n<-EsCapicua(num,digitos)
	Definir aux1 Como Real
	Definir j Como Entero
	Dimension vecOriginal[digitos]
	Dimension vecInverso[digitos]
	
	j=0
	aux1=num
	n=1
	
	Para i<-0 Hasta digitos-1 Con Paso 1 Hacer
		vecInverso[i]=aux1 mod 10
		aux1=trunc(aux1/10)
	Fin Para
	
	Para i<-digitos-1 Hasta 0 Con Paso -1 Hacer
		vecOriginal[j]=vecInverso[i]
		j=j+1
	Fin Para
	
	Para i<-0 Hasta digitos-1 Con Paso 1 Hacer
		Si vecOriginal[i]<>vecInverso[i] Entonces
			n=0
		FinSi
	Fin Para

FinFuncion

Funcion resultado <- contar(num)
	Mientras num >= 1 Hacer
		num=trunc(num/10)
		resultado=resultado+1
	Fin Mientras
	
	Mostrar "digitos: " resultado
	
Fin Funcion

