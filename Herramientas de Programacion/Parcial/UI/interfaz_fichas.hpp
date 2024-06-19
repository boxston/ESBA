#ifndef INTERFAZ_FICHAS_H
#define INTERFAZ_FICHAS_H
void interfaz_fichas(){
	for(int i=38; i<89; i++){
		gotoxy(i,5); printf("%c", 205);
	}
	gotoxy(37,5); printf("%c", 204);
	gotoxy(89,5); printf("%c", 185);
}
#endif
