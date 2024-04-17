#ifndef MENU_H
#define MENU_H

#include "opciones_menu.hpp"
#include <iostream>
#include <conio.h>

using namespace std;
void imprimirMenu(int seleccion) {
    system("cls");
    for (int i = 0; i < cantidad; ++i) {
        if (i == seleccion) {
            cout << "\033[47m\033[30m";
        } else {
            cout << "\033[0m";
        }
        cout << opciones[i] << endl;
    }
    cout << "\033[0m";
}

int menu() {
    int seleccion = 0;
    char tecla;
    
    do {
        imprimirMenu(seleccion);
        tecla = _getch();
        
        switch (tecla) {
            case 72:
                if (seleccion > 0) {
                    --seleccion;
                }
                break;
            case 80:
                if (seleccion < cantidad - 1) {
                    ++seleccion;
                }
                break;
        }
    } while (tecla != 13);
    
    return seleccion + 1;
}
#endif

