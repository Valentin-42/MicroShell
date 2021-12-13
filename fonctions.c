#include "main.h"

void Init(){
	write(1,"$ ./enseash\n",strlen("$ ./enseash\n"));
	write(1,"Bienvenue sur le Shell de l'ENSEA.\n",strlen("Bienvenue sur le Shell de l'ENSEA.\n"));
	write(1,"Pour quitter, tapez exit.\n",strlen("Pour quitter, tapez exit.\n"));
	write(1,"enseash % ",strlen("enseash % "));
}


int Execute(char* command, ssize_t size){
	char command_adapt[size];
	memset(command_adapt,0,size); 					//remise a zero du tableau

	if(size == 0){
		write(1,"Closing...\n",strlen("Closing...\n"));
		return 1; // Sortie de la fonction
	}
	else{

		strncpy(command_adapt,command,size-1); 	//Copie les size premier caracteres de la command dans le tableau fortune
		if(strcmp(command_adapt,"exit") == 0){ 	//Compare la chaine fortune avec le tableau créé.
			write(1,"Closing...\n",strlen("Closing...\n"));
			return 1; 						// Sortie de la fonction
		}

		else{
			write(1,"Command unknown\n",strlen("Command unknown\n"));
			write(1,command,size);
			return 0;
		}
	}

}
