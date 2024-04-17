#include <iostream>
#include <conio.h>
#include "menu.hpp"
#include "interfaz.hpp"
#include "gotoxy.hpp"
using namespace std;
int main () {
	interfaz();
	if (menu() == 5) ExitProcess(0);
	gotoxy(1,27); system("PAUSE");
	return 0;
}
