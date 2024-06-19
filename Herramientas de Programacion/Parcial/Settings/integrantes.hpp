#ifndef INTEGRANTES_H
#define INTEGRANTES_H
#include <vector>
#include <string>
#include "volver_menu.hpp"
using namespace std;
string (*getIntegrantes())[3]{
	static string listado[8][3] = {
	    {"Rodriguez", "Alan", "37.234.611"},
	    {"Ali", "Benjamin", "46.825.097"},
	    {"Cinquemani", "Carolina", "40.067.798"},
	    {"Mas", "Federico", "34.291.527"},
	    {"Arboleya", "Guido", "37.433.205"},
	    {"Martinez", "Rocio", "40.735.160"},
	    {"Hormigo", "Tamara", "37.004.164"},
	    {"Eguigorry", "Walter", "34.340.468"}
	};
	return listado;
}
int integrantes(int ejeX, int EjeY)
{
	string (*listado)[3] = getIntegrantes();
    for(int i = 0; i < 8; i++) {
        gotoxy(ejeX, (EjeY+1)+(i*2));
        cout << listado[i][0] << " " << listado[i][1] << " - " << listado[i][2] << endl;        
    }
}
void integrantesBox (int ejeX, int ejeY) {	
	integrantes(ejeX,ejeY);
	gotoxy(37,3); printf("%c", 203);
	gotoxy(37,28); printf("%c", 202);
	for(int i=4; i<28; i++){
		gotoxy(37,i); printf("%c", 186);
	}
}
#endif


