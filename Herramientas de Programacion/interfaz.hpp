#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <windows.h>
#include "ocultar_cursor.hpp"
#include "gotoxy.hpp"
using namespace std;
void interfaz(){
    system("cls");
	hideCursor();
	for(int i=2; i<90; i++){
		gotoxy(i,1); printf("%c", 205);
		gotoxy(i,3); printf("%c", 205);
		gotoxy(i,25); printf("%c", 205);
	}
	for(int i=2; i<25; i++){
		gotoxy(1,i); printf("%c", 186);
		gotoxy(89,i); printf("%c", 186);
	}
	gotoxy(1,1); printf("%c", 201);
	gotoxy(1,25); printf("%c", 200);
	gotoxy(1,3); printf("%c", 204);
	gotoxy(89,3); printf("%c", 185);
	gotoxy(89,1); printf("%c", 187);
	gotoxy(89,25); printf("%c", 188);
	gotoxy(66,26); printf("Fijar ventana en 90x30");
	
	gotoxy(31,2); cout<<"HERRAMIENTAS DE PROGRAMACION";
	gotoxy(3,24); printf("A%co: 2024", 164);
	
	gotoxy(3, 5);
}
#endif
