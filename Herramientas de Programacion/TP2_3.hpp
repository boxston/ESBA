#ifndef TP2_3_H
#define TP2_3_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <vector>
#include <unistd.h> 
void cuentaRegresiva(int n){
	for(int i=n; i >= 0; i--){
		
		if(i > 30) cout << "\033[32m";
		if(i < 30) cout << "\033[33m";
		if(i < 10) cout << "\033[31m";
		gotoxy(48,5); cout << i << "  ";
		sleep(1);
	}
	gotoxy(48,5); cout << "\033[36mFIN";
	cout << "\033[0m";
}
int tp2_3()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
    
    gotoxy(30,4);
	cout << "Ingresar un numero mayor a 0 y menor a 60: ";
	int n;
	do{
		gotoxy(74, 4); cout<<"              ";
		gotoxy(74,4); cin >> n;
	}while((n <= 0) || (n >= 60));	
    gotoxy(30,5); cout<<"Cuenta Regresiva:";
    cuentaRegresiva(n);
    volver_menu();
}
#endif
