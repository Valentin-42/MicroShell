/*
 * main.c
 *
 *  Created on: 6 déc. 2021
 *      Author: ensea
 */

#include "main.h"



int main(){

	char command[BUFF_SIZE]={0};
	char affichage[BUFF_SIZE]={0};
	int exit=0;
	ssize_t size;
	int status=-1;
	pid_t pid;

	Init();
	while(exit==0){
		memset(command,0,BUFF_SIZE); 					//remise a zero du tableau
		size = read(1,command,BUFF_SIZE); 				//Ecoute d'une commande
		pid = fork();									//Creation d'un fils traitant la commande
		if(pid == 0){ 									//Processus Fils
			exit = Execute(command,size); 				//Execution
		}
		else{ 											//Processus Père
			struct timespec start,stop;
			clock_gettime( CLOCK_REALTIME, &start);
			double time_duration;
			wait(&status);
			clock_gettime( CLOCK_REALTIME, &stop);
			time_duration = stop.tv_nsec - start.tv_nsec;

			if(WIFEXITED(status)==1){										//Le processus fils s'est terminé correctement
				lseek(1,0,SEEK_SET); 	 									//remise du curseur en debut de fichier
				sprintf(affichage,"enseash [sign:%d|%.2fms] %%",WEXITSTATUS(status),time_duration/1e6);   //Formattage de l'affichage
				write(1,affichage,strlen(affichage));						// LOOP
			}
			else if(WIFSIGNALED(status) == 1){					      		//Le processus fils s'est mal terminé
				sprintf(affichage,"enseash [exit %d|%.2fms] %%",WTERMSIG(status),time_duration/1e6);   //Formattage de l'affichage
				write(1,affichage,strlen(affichage));						// LOOP
				kill(getpid(),SIGINT);
			}

		}

	}

	return 0;
}
