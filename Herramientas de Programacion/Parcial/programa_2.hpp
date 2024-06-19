#ifndef PROGRAMA_2H
#define PROGRAMA_2H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "format.hpp"
#include "clear.hpp"
using namespace std;

struct Persona {
    int DNI;
    char NombreYApellido[65];
};

void ingresarDatos(ofstream &archivo) {
    Persona persona;
    string confirmar;
    do {
        gotoxy(39,5); cout << "Por favor, ingrese el DNI (sin puntos):";
        gotoxy(39,6); cin >> persona.DNI;
        cin.ignore();
        gotoxy(39,7); cout << "Ingrese el Nombre y Apellido: ";
        gotoxy(39,8);cin.getline(persona.NombreYApellido, 65);
        gotoxy(39,9); cout << "Los datos ingresados son: ";
        gotoxy(39,10); cout << "DNI: " << persona.DNI;
        gotoxy(39,11); cout << "Nombre y Apellido: " << persona.NombreYApellido;
		do{
			gotoxy(39,12); cout << "Confirma los datos de ingreso? (SI/NO): ";
        	gotoxy(39,13); cin >> confirmar;       
			confirmar = format(confirmar);
			if((confirmar != "SI" && confirmar != "NO")){
				gotoxy(39,14); cout << "Solo se admite ingresar SI/NO";
				clear(12,14);
			}
		}while((confirmar != "SI" && confirmar != "NO"));		
		gotoxy(39,15); cout << "                                   ";
        if (confirmar == "SI") {
            archivo << persona.DNI << ' ' << persona.NombreYApellido << '\n';
            gotoxy(39,15); cout << "Datos guardados exitosamente!";
        }
		clear(5,25);
    } while (confirmar != "SI");
}
void buscarDatos(ifstream &archivo) {
    int dniBuscado;
    Persona persona;
    bool encontrado = false;
    gotoxy(39,5); cout << "Ingrese el DNI que desea buscar: ";
    gotoxy(39,6); cin >> dniBuscado;
    while (archivo >> persona.DNI) {
        archivo.ignore();
        archivo.getline(persona.NombreYApellido, 65);
        if (persona.DNI == dniBuscado) {
            gotoxy(39,7); cout << "El DNI " << dniBuscado << " pertenece a:";
			gotoxy(39,8); cout << persona.NombreYApellido;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        gotoxy(39,7); cout << "El DNI ingresado no se encuentra en el archivo.";
    }
}

int programa_2()
{   	
	gotoxy(3,5); cout << "Integrantes:";
	integrantesBox(3,6);
    string opcion = "INGRESAR";
    
    INGRESAR:
    	if(opcion == "INGRESAR"){
    	ofstream archivo("DATOS.txt", ios::app);
	        if (archivo.is_open()) {
	            ingresarDatos(archivo);
	            archivo.close();
	        } else {
	            cout << "No se pudo abrir el archivo para escritura.";
	        }
		}
    
    BUSCAR:
    	if(opcion == "BUSCAR"){
	    	ifstream archivo("DATOS.txt");
	        if (archivo.is_open()) {
	            buscarDatos(archivo);
	            archivo.close();
	        } else {
	            cout << "No se pudo abrir el archivo para lectura.";
	        }
	    }
        
    PREGUNTA:    	
    	do{
    		gotoxy(39,5); cout << "                                      ";
    		gotoxy(39,6); cout << "                                      ";
	       	gotoxy(39,5); cout << "Que desea hacer? (ingresar, buscar, terminar): ";
	        gotoxy(39,6);cin >> opcion;
		    opcion = format(opcion);
		}while((opcion != "INGRESAR") && (opcion != "BUSCAR") && (opcion != "TERMINAR"));
		
	if(opcion == "TERMINAR"){
		clear(5,25);
		volver_menu();
	}else if (opcion == "INGRESAR"){
		clear(5,25);
		goto INGRESAR;
	} else if (opcion == "BUSCAR"){
		clear(5,25);
		goto BUSCAR;
	} else{
		cout << "El ingreso es incorrecto por favor escriba ingresar, buscar o terminar";
	}
}
#endif
