#include "main.h"

void Init(){
	write(1,"$ ./enseash\n",strlen("$ ./enseash\n"));
	write(1,"Bienvenue sur le Shell de l'ENSEA.\n",strlen("Bienvenue sur le Shell de l'ENSEA.\n"));
	write(1,"Pour quitter, tapez exit.\n",strlen("Pour quitter, tapez exit.\n"));
	write(1,"enseash % ",strlen("enseash % "));
}

//Pour le moment la fonction ne sert qu'à renvoyer un message simple dans le terminal
int Execute(char* command, ssize_t size){

	write(1,"Today is what happened to yesterday.\n",strlen("Today is what happened to yesterday.\n"));

	return 0; // Sortie de la fonction
}
