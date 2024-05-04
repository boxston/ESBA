#ifndef TP2_4_H
#define TP2_4_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <vector>
#include <unistd.h> 
void cuentaRegresiva2(int n){
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
int esPar(int linea){
	int n;
	do{
		gotoxy(66,linea); cout<<"            ";
		gotoxy(66,linea); cin >> n;
	}while((n <= 0) || (n%2 != 0));	
	return n;
}
bool continuar(){
	string resp;
	    gotoxy(30,8); cout << "Desea volver a cargar numeros?: s/si n/no ";
	do{
	    gotoxy(72,8); cin >> resp;
    	gotoxy(72,8); cout << "            ";
	}while((resp != "s") && (resp != "si") && (resp != "n") && (resp != "no"));
	
	if((resp == "s") || (resp == "si")){
		return true;
	} else {
		return false;
	}
}
int tp2_4()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);    
	int n1, n2;
    gotoxy(30,4); cout << "Ingresar un numero par mayor a 0: ";
	n1 = esPar(4);
    gotoxy(30,5); cout << "Ingresar otro numero par mayor a 0: ";
	n2 = esPar(5);
    gotoxy(30,6); cout << "La suma de ambos numeros es: " << n1+n2;
    if(continuar()){
    	gotoxy(30,4); cout << "                                                ";
    	gotoxy(30,5); cout << "                                                ";
    	gotoxy(30,6); cout << "                                                ";
    	gotoxy(30,8); cout << "                                                ";
    	tp2_4();
	}
    volver_menu();
}
#endif
