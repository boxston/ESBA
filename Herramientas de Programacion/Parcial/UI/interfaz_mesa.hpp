#ifndef INTERFAZ_MESA_H
#define INTERFAZ_MESA_H
#include "gotoxy.hpp"
void interfaz_mesa(int seleccion[39][2], int hover){
	bool color = true;
	string negro = "\033[0m";
	string rojo = "\033[41m\033[37m";
	string verde = "\033[48;5;28m";
	string verde_claro = "\033[48;5;34m";
	string resaltar = "\033[43m\033[30m";
	string negro_amarillo = "\033[40m\033[33m";
	string rojo_amarillo = "\033[41m\033[33m";
	string verde_amarillo = "\033[48;5;34m\033[33m";

	for(int i = 42; i < 88; i++){
		gotoxy(i,6); cout << verde << " ";
		gotoxy(i,10); cout << verde << " ";
	}
	
	for(int i = 39; i < 42; i++){
		for(int j = 6; j < 11 ; j++){
			gotoxy(i,j); cout << verde << " ";
		}
	}
	
	cout << verde_claro;
	if(seleccion[38][1] > 0) cout << verde_amarillo;
	if(hover == 38) cout<<resaltar;
	gotoxy(39, 8); cout << " " << 0 << " ";
	
	cout << verde_claro;
	if(seleccion[36][1] > 0) cout << verde_amarillo;
	if(hover == 36) cout<<resaltar;
	gotoxy(55, 10); cout << " PAR ";
	
	cout << verde_claro;	
	if(seleccion[37][1] > 0) cout << verde_amarillo;
	if(hover == 37) cout<<resaltar;
	gotoxy(65, 10); cout << " IMPAR ";
	
	cout << negro;	
	gotoxy(42,7);
	for(int i = 3; i<37; i+=3){
		if(color) {
			cout<<rojo;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << rojo_amarillo;
			}			
		}else{
			cout<<negro;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << negro_amarillo;
			}	
		}
		if(seleccion[hover][0] == i) cout<<resaltar;
		color = !color;
		cout << " " << i << " ";
	}
	cout << verde << " ";
	
	gotoxy(42,8);
	for(int i = 2; i<36; i+=3){
		if(!color) {
			cout<<rojo;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << rojo_amarillo;
			}	
		}else{
			cout<<negro;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << negro_amarillo;
			}
		}
		if(seleccion[hover][0] == i) cout<<resaltar;
		color = !color;
		cout << " " << i << " ";
	}
	cout << verde << " ";
	
	gotoxy(42,9);
	for(int i = 1; i<35; i+=3){
		if(color) {
			cout<<rojo;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << rojo_amarillo;
			}	
		}else{
			cout<<negro;
			for(int x = 0; x < 36; x++){
				if(seleccion[x][0] == i && seleccion[x][1] > 0) cout << negro_amarillo;
			}	
		}
		if(seleccion[hover][0] == i) cout<<resaltar;
		color = !color;
		cout << " " << i << " ";
	}
	cout << verde << " ";	
}
#endif
