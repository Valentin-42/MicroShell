#include "main.h"


int Execute_Q2(char* command, ssize_t size){
	char fortune[size];
	strncpy(fortune,command,size-1); //Copie les size premier caracteres de la command dans le tableau fortune
	if(strcmp(fortune,"fortune")==0){ //Compare la chaine fortune avec le tableau créé.
		write(1,"Today is what happened to yesterday.\n",strlen("Today is what happened to yesterday.\n"));
		return 1; // Sortie de la fonction
	}
	else{
		write(1,"Non reconnu\n",strlen("Non reconnu\n"));
		write(1,command,size);
		return 1;
	}
}



int main_Q2(){
	char command[BUFF_SIZE]={0};
		int exit=1;
		ssize_t size;

		Init();
		while(exit==1){
			size = read(1,command,BUFF_SIZE);
			exit = Execute_Q2(command,size);
			write(1,"enseash % ",strlen("enseash % "));
		}

		return 0;
}
