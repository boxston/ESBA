#ifndef TP2_2_H
#define TP2_2_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <vector>
int tp2_2()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
    
    gotoxy(30,4);
    int ciclos;
    cout << "Ingrese ciclos (Muestra los primeros 80 impares): ";
	cin >> ciclos;
	
	int y, x;
	y= 6;
	x= 30;
	
	int par = 0, impar = 0;
	for(int i = 0; i<= ciclos; i++){
		gotoxy(x,y);
		
		if(i % 2 == 0){
			par++;
		}else{
			if(impar <= 80){
				cout<< "\033[49m\033[32m"<< i << endl;
				Sleep(100);
			} 
			impar++;
		}
		cout << "\033[0m";
		if(x >= 80){
			y+=2;
			x = 30;
		}else{
			x += 3;
		}
	}
		
	gotoxy(3, 20); cout<< "\033[42m\033[30m - Cantidad Pares: " << par << " " << endl;
	gotoxy(3, 22); cout<< "\033[41m\033[30m - Cantidad Impares: " << impar << " " <<endl;
	
	cout << "\033[0m";
    
    volver_menu();
}
#endif
