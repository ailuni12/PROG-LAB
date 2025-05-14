
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
	
	//Resolución va aquí

FinFuncion
