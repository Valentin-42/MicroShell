/*
 * main.c
 *
 *  Created on: 6 déc. 2021
 *      Author: ensea
 */

#include "main.h"



int main(){
	char command[BUFF_SIZE]={0};
	int exit=0;
	ssize_t size;

	Init();
	while(exit==0){
		memset(command,0,BUFF_SIZE); 					//remise a zero du tableau
		size = read(1,command,BUFF_SIZE); 				//Ecoute d'une commande
		exit = Execute(command,size); 				//Traitement
		if(exit == 0){
			lseek(1,0,SEEK_SET); 							//remise du curseur en debut de fichier si loop
			write(1,"enseash % ",strlen("enseash % ")); 	//Loop
		}

	}

	return 0;
}
