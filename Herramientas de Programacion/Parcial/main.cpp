#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include "ocultar_cursor.hpp"
#include "menu.hpp"
#include "gotoxy.hpp"
#include "clear.hpp"
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include "interfaz.hpp"
#include "programa_1.hpp"
#include "programa_2.hpp"
#include "ruleta_grafica.hpp"
using namespace std;
void navegacion(int seleccion){
	int tecla = 0;
	switch (seleccion) {
	    case 1:
	    	interfaz("	PARCIAL - PROGRAMA 1");
	    	programa_1();
	        break;
	    case 2:
	    	interfaz("	PARCIAL - PROGRAMA 2");
	    	programa_2();
	        break;
	    case 3:
	    	interfaz("RULETA GRAFICA");
	    	ruleta_grafica();
    		volver_menu();
	        break;
	    case 4:
	    	interfaz("INTEGRANTES DEL GRUPO A1");
	    	integrantes(30, 4);	    	
    		volver_menu();
	        break;
	    case 5:
			gotoxy(3,26);
	        ExitProcess(0);
	        break;
	    default:
	        gotoxy(35,18); cout<<"Opcion no valida ...";
	        break;
	}
}
int main(int argc, char** argv) {
	hideCursor();
	bool seguir = true;
	while (seguir) {
		interfaz("HERRAMIENTAS DE PROGRAMACION");
		navegacion(menu());	
		Sleep(100);
    }
	return 0;
}
