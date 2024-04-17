#include <iostream>
#include <conio.h>
#include "menu.hpp"
#include "interfaz.hpp"
#include "gotoxy.hpp"
#include "tp1.hpp"
using namespace std;
navegacion(int seleccion){
	int tecla = 0;
	switch (seleccion) {
	    case 5:
			gotoxy(3,26);
	        ExitProcess(0);
	        break;
	    case 1:
	    	interfaz();
			tp1();
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
