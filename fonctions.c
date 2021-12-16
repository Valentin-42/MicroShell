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
		kill(getpid(),SIGINT);
		return 1; 									// Sortie de la fonction
	}
	else{
		strncpy(command_adapt,command,size-1);		//Copie les size premier caracteres de la command dans le tableau command_adapt
		if(strcmp(command_adapt,"exit") == 0){ 		//Compare la chaine command_adpat avec le tableau créé.
			write(1,"Closing...\n",strlen("Closing...\n"));
			kill(getpid(),SIGTERM);
			return 1; 								// Sortie de la fonction
		}

		else{

			char* argv[BUFF_SIZE]; //Tableau des arguments
			char* file = Adapt_command(command,argv);

			if(execvp(file,argv) == -1){
				write(1,"Command unknown\n",strlen("Command unknown\n"));
				write(1,file,strlen(file));
				write(1,"\n",strlen("\n"));
				exit(1);
			}

			return 0;
		}
	}

}

/*
 * Creer le tableau des arguments argv et le chemin vers la commande
 * */
char* Adapt_command(char* command, char* argv[]){

	int size = 0;
	char* command_split = strtok(command,"\n");
	char* file;
	char* ptr = strtok(command_split," ");
	while(ptr != NULL) //Remplissage des arguments.
	{
		if(strcmp(ptr,">") == 0){
			ptr = strtok(NULL," ");
			Redirection_Ecriture(ptr);
			break;
		}else if(strcmp(ptr,"<") == 0){
			ptr = strtok(NULL," ");
			Redirection_Lecture(ptr);
			break;
		}else{
			argv[size]= ptr;
			size+=1;
			ptr = strtok(NULL," ");
		}

	}

	argv[size]= (char*) NULL;
	file = argv[0];

	return file;
}

void Redirection_Lecture(char* ptr){
	struct stat stat_buf;

	if(stat(ptr, &stat_buf) == -1){ 										 			//Le fichier n'existe pas
		exit(1);
	}
	else{
		int fd = open(ptr,O_RDONLY,S_IRUSR);											//Ouverture du file 1
		dup2(fd,STDIN_FILENO);															//Deviation
		fclose(&ptr);
	}

}


void Redirection_Ecriture(char* ptr){

	struct stat stat_buf;

	if(stat(ptr, &stat_buf) == -1){ 										 //Le fichier n'existe pas
		int fd = creat(ptr,S_IWUSR | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); //Creation du fichier
		dup2(fd,STDOUT_FILENO);												 //Deviation du filedescripteur sur stdout
	}
	else{
		dup2(fileno(ptr),STDOUT_FILENO);			//Deviation
	}


}
