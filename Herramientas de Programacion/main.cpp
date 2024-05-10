#include <iostream>
#include <conio.h>
#include "menu.hpp"
#include "interfaz.hpp"
#include "gotoxy.hpp"
#include "tp1.hpp"
#include "tp2_1.hpp"
#include "tp2_2.hpp"
#include "tp2_3.hpp"
#include "tp2_4.hpp"
#include "integrantes.hpp"

// IMPORTANTE: 1. Cada ejercicio al comenzar debe mostrar por pantalla el APELLIDO y NOMBRE (en ese orden) 
// IMPORTANTE: 2. Se deben enviar los archivos en formato *.cpp con los ejercicios funcionales y resolviendo lo planteado, solo 1 archivo por ejercicio NO son necesarios los archivos de cada alumno,
// IMPORTANTE: 3. Pueden agregar al programa todo tipo de opciones que gusten, pero siempre contemplar que cumpla con todo lo solicitado.
using namespace std;
navegacion(int seleccion){
	int tecla = 0;
	switch (seleccion) {
	    case 6:
			gotoxy(3,26);
	        ExitProcess(0);
	        break;
	    case 5:
	    	interfaz();
	    	integrantes(35, 6, -1);	    	
    		volver_menu();
	        break;
	    case 1:
	    	interfaz();
			tp2_1();
	        break;
	    case 2:
	    	interfaz();
			tp2_2();
	        break;
	    case 3:
	    	interfaz();
			tp2_3();
	        break;
	    case 4:
	    	interfaz();
			tp2_4();
	        break;
	    // ...
	    default:
	        gotoxy(35,18); cout<<"Opcion no valida ...";
	        break;
	}
}
int main () {
	bool seguir = true;
	while (seguir) {
		interfaz();
		navegacion(menu());	
		Sleep(100);
    }
	return 0;
}
