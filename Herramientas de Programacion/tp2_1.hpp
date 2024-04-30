#ifndef TP2_1_H
#define TP2_1_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <vector>
int tp2_1()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
    
    gotoxy(30,5);
    string nombre, apellido;
    cout << "Ingrese un nombre: ";
	cin >> nombre;
    gotoxy(30,6);
    cout << "Ingrese un apellido: ";
	cin >> apellido;
	cout << endl;
	
	int encontrado = -1;
	
	for(int i = 0; i < 10 ; i++){
		if(nombre == listado[i][1] && apellido == listado[i][0]){
			encontrado = i;
		}
	}
	
	if(encontrado != -1){		
		integrantesBox(4, 4, encontrado);
		gotoxy(30,10); cout<< "\033[42m\033[30m Esta persona es parte del Grupo A1 "<<endl;
		cout << "\033[0m";
	}else{
		gotoxy(30,10); cout<< "\033[41m\033[30m Esta persona NO pertenece al Grupo A1 "<<endl;
		cout << "\033[0m";
	}
    
    volver_menu();
}
#endif
