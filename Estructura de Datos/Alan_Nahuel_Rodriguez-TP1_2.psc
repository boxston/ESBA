Algoritmo TP1_2	
	Definir columna, fila, i, random Como Entero
	columna = 0
	fila = 0	
	Escribir "Cantidad de columnas: " Sin Saltar
	Leer columna	
	Escribir "Cantida de filas: " Sin Saltar
	Leer fila	
	Definir partest Como Logico
	Definir pausa Como Caracter	
	Dimension arreglo(columna,fila)	
	posY = 0
	posX = 0
	random = 0
	parRnd = Falso
	pausa = ""
	Para posY=1 Hasta fila Hacer
		Para posX=1 Hasta columna Hacer
			Repetir
				random = azar(100)
				Si random%2 = 0 Entonces
					parRnd = Verdadero
				Fin Si
			Hasta Que parRnd = Verdadero
			arreglo(posX,posY) = random
			parRnd = Falso
		Fin Para
	Fin Para
		Escribir "BUSCAR UN VALOR"
		Escribir "Posici�n X: (1-", columna, ")"
		Leer posX
		Escribir "Posicion Y: (1-", fila, ")"
		Leer posY		
		Escribir "N�mero correspondiente = ", arreglo(posX,posY)
FinAlgoritmo