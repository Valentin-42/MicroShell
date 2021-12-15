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
		size = read(1,command,BUFF_SIZE); // Lit l'input utilisateur
		exit = Execute(command,size); //Traite la commande
		write(1,"enseash % ",strlen("enseash % ")); // Loop
	}

	return 0;
}
