Algoritmo TP1_4
	Definir i, n, nuevo, viejo, elemento Como Entero
	
	Escribir "Cantidad de elementos de la pila: " Sin Saltar
	Leer n
	
	Dimension pila(n)
	
	Escribir "Pila Original"
	Para i=1 Hasta n Hacer
		elemento = azar(99)
		pila(i) = elemento
		Si i <> 1
			Escribir ", " Sin Saltar
		FinSi
		Escribir pila(i) Sin Saltar
	FinPara
	
	Escribir ""
	Escribir "Numero a reemplazar: " Sin Saltar
	Leer viejo
	
	Escribir "Numero nuevo: "
	Leer nuevo
	
	Escribir "Pila Modificada"
	Para i=1 Hasta n Hacer
		Si pila(i) = viejo
			pila(i) = nuevo
		FinSi
		Si i <> 1
			Escribir ", " Sin Saltar
		FinSi
		Escribir pila(i) Sin Saltar
	FinPara
	Escribir ""
	
FinAlgoritmo