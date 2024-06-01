#ifndef TP3_1_H
#define TP3_1_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
#include <iostream>
#include <string>
#include <limits>
int seleccion(){
	int opcion;
	bool flag = false;
	do{
		gotoxy(30,11);
		while (!(cin >> opcion)) {
			clear(11,20);
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        gotoxy(30,12); cout << "No se permite letras";
		   	gotoxy(30,11);
	    }
		clear(11,20);        
		switch (opcion){
			case 1: flag = true;
				break;
			case 2: flag = true;
				break;
			case 3: flag = true;
				break;
			default:
				gotoxy(30,12); cout << "El ingreso es incorrecto";
				gotoxy(30,13); cout << "por favor seleccione la opcion 1 a 3";
				break;
		}
	}while(!flag);	
	clear(11,20);
	return opcion;
}
int vocales (string frase){
	int count = 0;
	for(int i=0;i<frase.size();i++)
	{
		if((frase[i]=='a')or(frase[i]=='e')or(frase[i]=='i')or(frase[i]=='o')or(frase[i]=='u'))
		{
			count++;
		}
	}
	return count;
}
int consonantes (string frase){
	int count = 0;
	for(int i=0;i<frase.size();i++)
	{
		if((isdigit(frase[i])==0)&&(frase[i]!=' ')&&(frase[i]!='a')&&(frase[i]!='e')&&(frase[i]!='i')&&(frase[i]!='o')&&(frase[i]!='u'))
		{
			count++;
		}
	}
	return count;
}
int numeros (string frase){
	int count = 0;
	for(int i=0;i<frase.size();i++)
	{
		if(isdigit(frase[i]))
		{
			count++;
		}
	}
	return count;
}
int tp3_1()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
	string frase;
	int opcion = 0;
	gotoxy(30,5); cout<<"Escribir frase ...";
	gotoxy(30,6); cin.ignore(); getline(cin, frase);
	gotoxy(30,7); cout<<"-----Menu------";
	gotoxy(30,8); cout<<"1) Contar VOCALES.";
	gotoxy(30,9); cout<<"2) Contar CONSONANTES.";
	gotoxy(30,10); cout<<"3) Contar NUMEROS.";
	opcion = seleccion();
	switch(opcion){
		case 1:
			gotoxy(30,12); cout<<"La frase tiene "<<vocales(frase)<<" VOCALES.";
			break;
		case 2:
			gotoxy(30,12); cout<<"La frase tiene "<<consonantes(frase)<<" CONSONANTES.";
			break;
		case 3:
			gotoxy(30,12); cout<<"La frase tiene "<<numeros(frase)<<" NUMEROS.";
			break;
	}
    volver_menu();
}
#endif
