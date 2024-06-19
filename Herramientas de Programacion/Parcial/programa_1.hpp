#ifndef PROGRAMA_1_H
#define PROGRAMA_1_H
#include <cstdlib>
#include <ctime>
#include "interfaz_fichas.hpp"
#include "interfaz_mesa.hpp"
#include "format.hpp"
int ficha = 100;
void setFicha(){	
	gotoxy(38,4); cout << "Ficha: " << ficha << "         ";
}
void girar(int numero, int cantidad_ficha, string opcion) {
    srand(time(0));
    int ruleta = rand() % 37;
    gotoxy(39, 9); cout << "                                  ";
    gotoxy(39, 9); cout << "El numero de la ruleta es: " << ruleta;
	if(opcion == "NUMERO" && ruleta == numero){
		ficha = (ficha - cantidad_ficha) + (cantidad_ficha * 36);
	}else if(opcion == "PAR" && numero != 0 && ruleta%2 == 0){
		ficha = (ficha - cantidad_ficha) + (cantidad_ficha * 2);
	}else if(opcion == "IMPAR" && numero != 0 && ruleta %2!= 0){
		ficha = (ficha - cantidad_ficha) + (cantidad_ficha * 2);
	} else{
		ficha = ficha - cantidad_ficha;
	}
    setFicha();
    gotoxy(39, 10); cout << "                                                 ";
	gotoxy(39, 10); cout << "A usted le quedan " << ficha << " Ficha ";
}
int programa_1()
{   
	ficha = 100;
	gotoxy(3,5); cout << "Integrantes:";
	integrantesBox(3,6);
	interfaz_fichas();
	setFicha();
    string opcion, paridad, continuar;
    int numero_apostado = 0, cantidad_ficha;   
    do {
        gotoxy(39,6); cout << "                                  ";
        gotoxy(39,7); cout << "                                  ";
        gotoxy(39,8); cout << "                                  ";
        gotoxy(39,9); cout << "                                  ";
        gotoxy(39,10); cout << "                                  ";
        gotoxy(39,11); cout << "                                               ";
    	do{
    		gotoxy(39,6); cout << "                                  ";
    		gotoxy(39,6); cout << "Numero o Paridad? ";
	        cin >> opcion;        
	        opcion = format(opcion);
		}while((opcion != "NUMERO") && (opcion != "PARIDAD"));
    	if (opcion == "NUMERO") {
            do {
            	gotoxy(39,7); cout << "                              ";
                gotoxy(39,7); cout << "INGRESE EL NUMERO (0-36): ";
                cin >> numero_apostado;
            } while (numero_apostado < 0 || numero_apostado > 36);       
        } else if (opcion == "PARIDAD") {
            do {
            	gotoxy(39,7); cout << "                              ";
                gotoxy(39,7); cout << "INGRESE PAR O IMPAR: ";
                cin >> paridad;
                paridad = format(paridad);
            } while (paridad != "PAR" && paridad != "IMPAR");      
        }  
        do {
        	gotoxy(39,8); cout << "                              ";
            gotoxy(39,8); cout << "QUE CANTIDAD DE FICHA? ";
            cin >> cantidad_ficha;
        } while ((cantidad_ficha > ficha) || (cantidad_ficha < 1));
        if(opcion == "NUMERO"){
        	girar(numero_apostado, cantidad_ficha, opcion);
		}else{
			girar(99, cantidad_ficha, paridad);
		}
    	setFicha();  
        if (ficha > 0) {
        	do{       
				gotoxy(39, 11); cout << "                              ";		
	            gotoxy(39, 11); cout << "Desea seguir jugando? JUGAR / RETIRAR: ";
	            cin >> continuar;
        		continuar = format(continuar);	            
			} while (continuar != "RETIRAR" && continuar != "JUGAR");
        } else {
			gotoxy(39, 11); cout << "                              ";		
            gotoxy(39, 11); cout << "Se ha quedado sin ficha. Fin del juego.\n";
            continuar = "RETIRAR";
        }  
    } while (continuar != "RETIRAR");
    setFicha();
    if(ficha > 0) gotoxy(39,12); cout << "Le quedan " << ficha << " ficha.\n";    
    volver_menu();

}
#endif
