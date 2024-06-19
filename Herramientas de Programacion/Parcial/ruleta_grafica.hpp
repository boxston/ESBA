#ifndef RULETA_GRAFICA_H
#define RULETA_GRAFICA_H
#include <cstdlib>
#include <ctime>
#include "interfaz_fichas.hpp"
#include "interfaz_mesa.hpp"
#include "format.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
int fichas = 100;
int apuesta = 1;
int totalApuesta = 0;
int hover = 0;
int seleccion[39][2] = {
	{3, 0}, {6, 0},{9 , 0},{12 , 0},{15 , 0},{18 , 0},{21 , 0},{24 , 0},{27 , 0},{30 , 0},{33 , 0},{36 , 0},	
	{2, 0}, {5, 0},{8 , 0},{11 , 0},{14 , 0},{17 , 0},{20 , 0},{23 , 0},{26 , 0},{29 , 0},{32 , 0},{35 , 0},
	{1, 0}, {4, 0},{7 , 0},{10 , 0},{13 , 0},{16 , 0},{19 , 0},{22 , 0},{25 , 0},{28 , 0},{31 , 0},{34 , 0},
	{37, 0}, {38, 0},{0, 0}
};

void calcularApuesta(){
	totalApuesta = 0;
	for(int i= 0; i<39; i++){
		totalApuesta += seleccion[i][1]; 
	}
}
void resetSeleccion(){
	calcularApuesta();
	for(int i = 0; i < 39; i++){
		seleccion[i][1] = 0;
	}
}
void setFichas(){	
    cout << "\033[0m"; 
	gotoxy(39,4); cout << "Fichas: " << fichas << "           ";
}
void estado(){
	calcularApuesta();
    cout << "\033[0m";    
    gotoxy(39, 12); cout << "Fichas a Apostar: \033[48;5;28m " << apuesta << " \033[0m         ";
	gotoxy(39, 14); cout << "Total a Apostar: \033[48;5;28m " <<  totalApuesta << " \033[0m        ";
    cout << " \033[0m"; 
}

void detalle(){
	gotoxy(1,29);
	for(int i = 0; i < 39; i++){
		cout << "Posicion: " << i << " Numero: " << seleccion[i][0] << " Apuesta: " << seleccion[i][1] << " / " << endl;
	}
}
void girarRuleta(){	
    srand(time(0));
    int numero_ruleta = rand() % 37;
    cout << "\033[0m"; 
    gotoxy(39,16);cout << "El numero de la ruleta es: \033[48;5;28m " << numero_ruleta << " \033[0m        ";
    for(int i = 0; i < 36; i++){
    	if(seleccion[i][1] < 1) continue;
    	if(seleccion[i][0] == numero_ruleta){
    		fichas = (fichas - seleccion[i][1]) + seleccion[i][1] * 36;
    		estado();
		}else{
			fichas -= seleccion[i][1];
		}
	}
	if(seleccion[36][1] > 0){
		if(numero_ruleta%2 == 0){
			fichas = (fichas - seleccion[36][1]) + seleccion[36][1] * 2;
		}else
		{
			fichas -= seleccion[36][1];
		}
	}
	
	if(seleccion[37][1] > 0){
		if(numero_ruleta%2 != 0){
			fichas = (fichas - seleccion[37][1]) + seleccion[37][1] * 2;
		}else
		{
			fichas -= seleccion[37][1];
		}
	}
	
	if(seleccion[38][1] > 0){
		if(seleccion[38][0] == numero_ruleta){
			fichas = (fichas - seleccion[38][1]) + seleccion[38][1] * 36;
		}else{
			fichas -= seleccion[38][1];
		}
	}
	apuesta = 0;
	totalApuesta = 0;
	hover = 0;
	setFichas();
	estado();
	resetSeleccion();
	interfaz_mesa(seleccion, hover);
}
int ruleta_grafica()
{     
	gotoxy(3,5); cout << "Integrantes:";
	integrantesBox(3,6);
	interfaz_fichas();
	setFichas();
	estado();
	gotoxy(40, 19); cout << "Comandos:";
	gotoxy(40, 20); cout << "- Seleccionar opcion con FLECHAS";
	gotoxy(40, 21); cout << "- Agregar apuesta ESPACIO";
	gotoxy(40, 22); cout << "- Subir/Bajar monto +/-";
	gotoxy(40,23); cout << "- Finalizar apuesta ENTER";    	
	gotoxy(40,24); cout << "- Retirarse ESC";    	
	interfaz_mesa(seleccion, hover);
	bool flag = true;
	do{
        gotoxy(40, 20); 
		char tecla = _getch();
		if (tecla == 0 || tecla == 224) tecla = _getch();		
    	gotoxy(39,16);cout << "\033[0m                                 ";
		calcularApuesta();
		estado();
        switch (tecla) {
        	case 27: // ESC
        		flag = false;
				break;
            case 72: // Flecha arriba
            	if(hover < 12) continue;
            	hover = hover - 12;
				interfaz_mesa(seleccion, hover);
                break;
            case 80: // Flecha abajo
            	if(hover > 37) continue;
            	if(hover < 24){            		
            		hover = hover + 12;
				}else if(hover != 37){
					hover = 36;
				}else{
					continue;
				}
				interfaz_mesa(seleccion, hover);
                break;
            case 75: // Flecha izquierda
            	if(hover == 0 || hover == 24  || hover ==36 || hover == 36 || hover == 38) continue;
            	if(hover == 12){
            		hover = 38;
				}else{
            		hover = hover - 1;
				}
				interfaz_mesa(seleccion, hover);
                break;
            case 77: // Flecha derecha
            	if(hover == 11 || hover == 23  || hover ==35 || hover == 37) continue;
            	if(hover == 38){
            		hover = 12;
				}else{
					hover = hover + 1;
				};            	
				interfaz_mesa(seleccion, hover);
                break;
            case '+': // Tecla +
            	calcularApuesta();
            	if(fichas < (totalApuesta + apuesta)) apuesta = 0;
                if((apuesta + 1) <= fichas && totalApuesta <= fichas) apuesta++;                
				estado();
                break;
            case '-': // Tecla -
                if((apuesta-1) >= 0) apuesta--;
				estado();
                break;
            case ' ': // Tecla Espacio
            	calcularApuesta();
            	if(apuesta < 0) continue;
            	if(apuesta > fichas) continue;
            	if((apuesta + totalApuesta) > fichas) continue;
                seleccion[hover][1] = apuesta;
                calcularApuesta();
                if((apuesta + fichas) <= totalApuesta) apuesta = 0;
				interfaz_mesa(seleccion, hover);
				estado();
                break;
            case 13: // Tecla Enter
            	girarRuleta();
                break;
     	};
		Sleep(100);		
	}while(flag);
    	    
    volver_menu();

}
#endif
