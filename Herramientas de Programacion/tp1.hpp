#ifndef TP1_H
#define TP1_H
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int escuchar(){	
	bool seguir = true;
	gotoxy(52,24);cout<<"Presione ESC para volver al menu ...";
	while (seguir) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 27) {
                seguir = false;
                return 27;
            }
        }
		Sleep(100);
    }
}
int tp1()
{
	char car;
	static char nombre[] = "La temperatura ambiente";
	int a,b,c;
	float x,y,z;
	car = 'C'; a=20; b=350; c=1995;
	x= 34.5; y=1234; z=1.248;
	gotoxy(68,4); cout<<"Trabajo Practico N"<<static_cast<char>(248)<<"1"; 
	gotoxy(3,6);cout<<nombre<< " es de: " <<a<<static_cast<char>(248)<<car<<endl;
	gotoxy(3,7); cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<endl;
	gotoxy(3,8);cout<<"Los resultados son los siguientes:"<<endl;
	gotoxy(3,9);cout<<x<<"\t\t"<<y<<"\t\t"<<z<<endl;
	gotoxy(3,10);cout<<"------------------------------------------"<<endl;
	gotoxy(3,11);cout<<"Ingrese un nuevo valor para x: ";
	cin>>x;
	gotoxy(3,12);cout<<"Ingrese un nuevo valor para y: ";
	cin>>y;
	gotoxy(3,13);cout<<"------------------------------------------"<<endl;
	gotoxy(3,14);cout<<"x = "<<x<<" y = "<<y<<" z = "<<z<<endl;
	gotoxy(3,15);cout<<"x+y = "<<x+y<<" y/5 = "<<y/5<<" z*2 = "<<z*2<<endl;
	gotoxy(3,16);cout<<"Ingrese un nuevo valor de z: ";
	cin>>z;
	gotoxy(3,17);cout<<"Valor resultado de z*(x+y) es: "<<fixed<<setprecision(3)<<z*(x+y)<<endl;
	int seleccion = escuchar();	
    if (seleccion == 27) {
        return 27;
    }else if(seleccion == 13){
        return 13;          	
	}
}
#endif
