#ifndef CLEAR_H
#define CLEAR_H
void clear(int inicio, int fin){
	for(int y = inicio; y<fin; y++){
		for(int x = 30; x<89; x++){
			gotoxy(x,y); cout << " ";	
		}			
	}	
}
#endif
