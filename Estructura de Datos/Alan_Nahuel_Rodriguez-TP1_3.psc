Algoritmo TP1_3
	Definir i, j, k, articulos, codigo, aux, intervalo Como Entero
	Escribir "Cantidad de  art�culos: " Sin Saltar
	Leer articulos
	Dimension arreglo(2,articulos)
	Dimension  burbuja(2,articulos)
	Dimension shell(2, articulos)
	Para i = 1 Hasta articulos Hacer
		codigo = azar(9999)
		precio = azar(9999)
		arreglo(1,i) = codigo
		arreglo(2,i) = precio
		burbuja(1,i) = codigo
		burbuja(2,i) = precio
		shell(1,i) = codigo
		shell(2,i) = precio
	FinPara
		
	Para i=1 Hasta articulos-1 Hacer
		Para j=1 Hasta articulos-1 Hacer
			Si burbuja(1,j) > burbuja(1,j+1)
				aux = burbuja(1,j)
				burbuja(1,j) = burbuja(1, j+1)
				burbuja(1,j+1) = aux				
				aux = burbuja(2,j)
				burbuja(2,j) = burbuja(2, j+1)
				burbuja(2,j+1) = aux
			FinSi
		FinPara		
	Fin Para
	
	intervalo = trunc(articulos / 2)
	Mientras intervalo<>0 Hacer
		Para i=intervalo Hasta articulos Hacer
			j=i-intervalo
			Mientras j>=1 Hacer
				k=j+intervalo
				Si shell(1,j)<=shell(1,k) Entonces
					j=j-1
				SiNo
					aux = shell(1,j)
					shell(1,j) = shell(1,k)
					shell(1,k) = aux
					
					aux = shell(2,j)
					shell(2,j) = shell(2, k)
					shell(2,k) = aux
					
					j=j-intervalo
				FinSi
			FinMientras
		FinPara
		intervalo=trunc(intervalo/2)
	FinMientras
	
	Escribir "Original"
	Escribir " Codigo | Precio "
	Para i=1 Hasta articulos Hacer
		Escribir arreglo(1, i), " | ", arreglo(2,i)
	FinPara
	
	Escribir "Burbuja"
	Escribir " Codigo | Precio "
	Para i=1 Hasta articulos Hacer
		Escribir burbuja(1, i), " | ", burbuja(2,i)
	FinPara
	
	Escribir "Shell"
	Escribir " Codigo | Precio "
	Para i=1 Hasta articulos Hacer
		Escribir shell(1, i), " | ", shell(2,i)
	FinPara
FinAlgoritmo