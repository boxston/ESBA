#ifndef VOLVER_MENU_H
#define VOLVER_MENU_H
using namespace std;
int volver_menu()
{
	bool seguir = true;
	gotoxy(52,27);cout<<"Presione ESC para volver al menu ...";
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
#endif

