#include <iostream>
#include <conio.h>

#include <windows.h>
#include "ocultar_cursor.hpp"
#include "menu.hpp"

using namespace std;
int main () {
	hideCursor();
	int opcion = menu();
	cout<<"La opcion seleccionada es: "<< opcion << endl;
	if (opcion == 6) {
        ExitProcess(0);
    }
	return 0;
}
