#ifndef MENU_H
#define MENU_H
#include <conio.h>
#include "menu_opciones.hpp"
#include "interfaz.hpp"

using namespace std;
void imprimirMenu(int seleccion) {
    for (int i = 0; i < cantidad; ++i) {
        if (i == seleccion) {
            cout << "\033[47m\033[30m";
        } else {
            cout << "\033[0m";
        }
        int x = (15 - opciones[i].size()) / 2;
        gotoxy(36+x,10+i);
        if(opciones[i] == "Salir ...") gotoxy(78,24);
		cout << opciones[i];
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


