#ifndef TP3_3_H
#define TP3_3_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <iostream>
#include <limits>
int tp3_3()
{	
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
    int numeros[4];
    int contadorCeros = 0;
    string mensajes[4] = {"Ingrese el primer numero: ", "Ingrese el segundo numero: ", "Ingrese el tercer numero: ", "Ingrese el cuarto numero: "};
    for (int i = 0; i < 4; i++) {
        gotoxy(30,(5 + i)); cout << mensajes[i];
        while (!(cin >> numeros[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            gotoxy(30,(5+i));cout << "No se aceptan letras, " <<  mensajes[i];
            gotoxy(78,(5+i)); cout<<"         ";
            gotoxy(78,(5+i));
        }
    }
    gotoxy(30,12); cout << "Numeros ingresados: ";
    for (int i = 0; i < 4; i++) {
        if (numeros[i] == 0) {
            contadorCeros++;
            continue;
        }
        cout << numeros[i] << " ";
    }
    gotoxy(30,13); cout << "En los ingresos habia/n " << contadorCeros << " ceros." << endl;
    volver_menu();
}
#endif
