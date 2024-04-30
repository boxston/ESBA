Algoritmo TP1_5
	Definir n, i, j, elemento, inicial, final, medio Como Entero
	Definir aux Como Caracter
	Definir encontrado Como Logico
	Dimension colores(4)
	colores(1) = "rojo"
	colores(2) = "amarillo"
	colores(3) = "verde"
	colores(4) = "gris"
	
	Escribir "Cantidad de personas en la cola" Sin Saltar
	Leer n
	
	Dimension cola(n)
	
	
	Para i=1 hasta n Hacer
		elemento = 0
		Repetir
			elemento = azar(5)
		Hasta Que elemento <> 0 
		cola(i) = colores(elemento)
	FinPara
	
	elemento = 0
	Repetir
		elemento = azar(5)
	Hasta Que elemento <> 0 
	cola(elemento) = "azul"	
	
	
	Para i=1 Hasta n-1 Hacer
		Para j=i+1 Hasta n Hacer
			Si cola(j) < cola(i) Entonces
				aux = cola(j)
				cola(j) = cola(i)
				cola(i) = aux
			FinSi
		FinPara		
	Fin Para
	
	Escribir "Cola"
	Para i=1 hasta n Hacer
		Si i <> 1
			Escribir ", " Sin Saltar
		FinSi
		Escribir cola(i) Sin Saltar
	FinPara
	
	Escribir ""
	
	Para i=1 hasta n Hacer
		Si cola(i)="azul" Entonces
			Escribir "El saco azul esta en la posicion: ", i, " (secuencial)"
		FinSi
	FinPara
		
	inicial = 1
	final = n
	encontrado = Falso
	Mientras encontrado=Falso Y inicial<=final Hacer
		medio = trunc((inicial+final) / 2)
		Si cola(medio) = "azul" Entonces
			Escribir "El saco azul esta en la posicion: ", medio, " (binaria)"
			encontrado = Verdadero
		SiNo
			Si cola(medio)<"azul" Entonces
				inicial = medio + 1
			SiNo
				final = medio -1
			FinSi
		FinSi
	FinMientras
	
	
FinAlgoritmo