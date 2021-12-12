/*
 * main.c
 *
 *  Created on: 6 déc. 2021
 *      Author: ensea
 */

#include "main.h"
// Testtest Nico test test test


int Execute_Q3(char* command, ssize_t size){
	char compare[size];
	memset(compare,0,size);
	strncpy(compare,command,size-1); //Copie les size premier caracteres de la command dans le tableau fortune

	if(strcmp(compare,"exit")==0){ //Compare la chaine fortune avec le tableau créé.
		write(1,command,size);
		return 0; // Sortie de la fonction
	}
	else{
		write(1,"Today is what happened to yesterday.\n",strlen("Today is what happened to yesterday.\n"));
		return 1;
	}
}

int main(){
	char command[BUFF_SIZE]={0};
	int exit=1;
	char buffer[100];
	ssize_t size;
	pid_t pid ;

	pid=fork();
	if(pid != 0){ //Father
		Init();
			while(exit==1){
				memset(command,0,BUFF_SIZE); 					//remise a zero du tableau
				size = read(1,command,BUFF_SIZE); 				//Ecoute d'une commande
				exit = Execute_Q3(command,size); 				//Execution
				lseek(1,0,SEEK_SET); 							//remise du curseur en debut de fichier
				write(1,"enseash % ",strlen("enseash % ")); 	//Loop

			}
	}
	else{//Child
		//Gestion du control+D
		char buffer[10];
		while(1){
			if (fgets(buffer, BUFF_SIZE, stdin)==0){
				write(1,"exitCTRL",strlen("exitCTRL"));

			}
		}

	}


	return 0;
}
