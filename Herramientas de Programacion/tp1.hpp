#ifndef TP1_H
#define TP1_H
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "volver_menu.hpp"
using namespace std;
void divisor(int y){
	for(int x = 3; x < 88; x++){		
		gotoxy(x,y); cout<<"-";
	}	
}
int tp1()
{
	gotoxy(68,4); cout<<"Trabajo Practico N"<<static_cast<char>(248)<<"1"; 
	char car;
	static char nombre[] = "La temperatura ambiente";
	int a,b,c;
	float x,y,z;
	car = 'C'; a=20; b=350; c=1995;
	x= 34.5; y=1234; z=1.248;
	gotoxy(3,6); cout<<nombre<< " es de: " <<a<<static_cast<char>(248)<<car<<endl;
	gotoxy(3,7); cout<<"a = "<<a<<" b = "<<b<<" c = "<<c;
	gotoxy(3,9); cout<<"Los resultados son los siguientes:";
	gotoxy(3,10); cout<<x<<"\t\t"<<y<<"\t\t"<<z;
	divisor(12);
	gotoxy(3,13); cout<<"Ingrese un nuevo valor para x: ";
	cin>>x;
	gotoxy(3,14); cout<<"Ingrese un nuevo valor para y: ";
	cin>>y;
	divisor(15);
	gotoxy(3,16); cout<<"x = "<<x<<" y = "<<y<<" z = "<<z;
	gotoxy(3,17); cout<<"x+y = "<<x+y<<" y/5 = "<<y/5<<" z*2 = "<<z*2;	
	divisor(18);
	gotoxy(3,19); cout<<"Ingrese un nuevo valor de z: ";
	cin>>z;
	gotoxy(3,20); cout<<"Valor resultado de z*(x+y) es: "<<fixed<<setprecision(3)<<z*(x+y);
	volver_menu();
}
#endif
