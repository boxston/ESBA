#ifndef TP3_2_H
#define TP3_2_H
#include "integrantes.hpp"
#include "volver_menu.hpp"
char letra(){
	char opcion;
	bool flag = false;
	do{
		gotoxy(30,11); cout<<"       ";
		gotoxy(30,11); cin >> opcion;		
		gotoxy(30,12); cout<<"                                              ";
		gotoxy(30,13); cout<<"                                              ";
		switch(opcion){
			case 'a': case 'A':
				gotoxy(30,12); cout<<"Ha escrito la letra "<<opcion<<" de Almendra.";
				flag = true;
				break;
			case 'b': case 'B':
				gotoxy(30,12); cout<<"Ha escrito la letra "<<opcion<<" de Bruce.";
				flag = true;
				break;
			case 'c': case 'C':
				gotoxy(30,12); cout<<"Ha escrito la letra "<<opcion<<" de Caramelo.";
				flag = true;
				break;
			case 'd': case 'D':
				gotoxy(30,12); cout<<"Ha escrito la letra "<<opcion<<" de Diametro.";
				flag = true;
				break;
			default:
					gotoxy(30,12); cout << "La letra "<<opcion<<" no es letra habilitada,";
					gotoxy(30,13); cout << "por favor ingrese a,b,c o d";
				break;
		}
	}while(!flag);
	return opcion;	
}
bool reingresar(){
	string opcion;
	gotoxy(30,13); cout<<"Desea volver a ingresar una letra? s/si n/no";
	do{
		gotoxy(30,14); cout<<"          ";
		gotoxy(30,14); cin >> opcion;
	}while((opcion != "s") && (opcion != "si") && (opcion != "n") && (opcion != "no"));
	if((opcion == "s") || (opcion == "si")){		
		gotoxy(30,12); cout<<"                                              ";
		gotoxy(30,13); cout<<"                                              ";
		gotoxy(30,14); cout<<"                                              ";
		return true;
	}else{
		return false;
	}
}
int tp3_2()
{
	string (*listado)[2] = getIntegrantes();
	integrantesBox(4, 4, -1);
	string opcion;
	gotoxy(30,5);cout<<"------MENU------";
	gotoxy(30,6);cout<<"A";
	gotoxy(30,7);cout<<"B";
	gotoxy(30,8);cout<<"C";
	gotoxy(30,9);cout<<"D";
	gotoxy(30,10);cout<<"Elija una letra del menu";
   	opcion = letra();
   	if(reingresar()){
   		tp3_2();	
	}
    volver_menu();
}
#endif
