#ifndef TP3_4_H
#define TP3_4_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <limits>
int tp3_4()
{	
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
	
	double A, B;
    int opcion;
    string respuesta;

INGRESO:
	clear(5,20);
    gotoxy(30,5); cout << "Ingrese el primer valor: ";
	while (!(cin >> A)) {
		clear(5,6);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(30,5); cout << "No se permite letras, Ingrese el primer valor:";
	   	gotoxy(78,5); cout << "       ";
	   	gotoxy(78,5);
    }
    gotoxy(30,6); cout << "Ingrese el segundo valor: ";
    while (!(cin >> B)) {
		clear(6,7);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(30,6); cout << "No se permite letras, Ingrese el segundo valor: ";
	   	gotoxy(78,6); cout << "       ";
	   	gotoxy(78,6);
    }

MENU:
	clear(7,20);
    gotoxy(30,7); cout << "-----Menu------";
    gotoxy(30,8); cout << "1) SUMAR.";
    gotoxy(30,9); cout << "2) RESTAR.";
    gotoxy(30,10); cout << "3) MULTIPLICAR.";
    gotoxy(30,11); cout << "4) DIVIDIR.";
    gotoxy(30,12); cout << "Elija su opcion: ";
    gotoxy(50,12); 
    while (!(cin >> opcion)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        gotoxy(30,13); cout << "No se aceptan letras";
	   	gotoxy(50,12); cout << "             ";
	   	gotoxy(50,12);
    }
    switch(opcion) {
        case 1:
            gotoxy(30,13); cout << "La Suma es = " << A + B;
            break;
        case 2:
            gotoxy(30,13); cout << " La Resta es = " << A - B;
            break;
        case 3:
            gotoxy(30,13); cout << "La Multiplicacion es = " << A * B;
            break;
        case 4:
	            if (B != 0){
	            	gotoxy(30,13); cout << " La Division es = " << A / B;
				} else {
					gotoxy(30,13); cout << "Error: Division por cero.";
				}                
            break;
        default:
	            gotoxy(30,13); cout << "El ingreso es incorrecto";
	            gotoxy(30,14); cout << "por favor seleccione la opcion 1 a 4.";
	            sleep(1);
	            goto MENU;
            break;
            
    }
    
REITERAR:
    gotoxy(30,14); cout << "Desea volver a operar? menu / ingresar / salir";
	gotoxy(30,15); cin >> respuesta;
    if (respuesta == "menu") {
        goto MENU;
    } else if (respuesta == "ingresar") {
        goto INGRESO;
    } else if (respuesta == "salir") {
        return 0;
    } else {
    	gotoxy(30,16); cout<<"La respuesta ingresada es incorrecta";
    	sleep(1);
    	clear(15,20);
    	goto REITERAR;
    }
    volver_menu();
}
#endif
