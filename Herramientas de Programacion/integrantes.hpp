#ifndef INTEGRANTES_H
#define INTEGRANTES_H
#include <vector>
#include <string>
#include "volver_menu.hpp"
using namespace std;
string (*getIntegrantes())[2]{
	static string listado[10][2] = {
	    {"Rodriguez", "Alan"},
	    {"Ali", "Benjamin"},
	    {"Cinquemani", "Carolina"},
	    {"Mas", "Federico"},
	    {"Arboleya", "Guido"},
	    {"Vinolo", "Lucas"},
	    {"Pelleritti", "Pedro"},
	    {"Martinez", "Rocio"},
	    {"Hormigo", "Tamara"},
	    {"Eguigorry", "Walter"}
	};
	return listado;
}
int integrantes(int ejeX, int EjeY, int pintado)
{
	string (*listado)[2] = getIntegrantes();
    gotoxy(ejeX,EjeY); cout << "Integrantes Grupo A1:" << endl;
    for(int i = 0; i < 10; i++) {
        gotoxy(ejeX, (EjeY+1)+i);
        if(i == pintado){
        	cout << "\033[42m\033[30m";
		}else{
			cout << "\033[0m";
		}
        cout << " - " << listado[i][0] << " " << listado[i][1] << endl;        
    }
}

void integrantesBox (int ejeX, int ejeY, int pintado) {	
	integrantes(ejeX,ejeY, pintado);
	gotoxy(28,3); printf("%c", 203);
	gotoxy(28,25); printf("%c", 202);
	for(int i=4; i<25; i++){
		gotoxy(28,i); printf("%c", 186);
	}
}
#endif

