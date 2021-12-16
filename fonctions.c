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
			//char* argv[3] = {"ls",(char*) NULL," "};
			char* argv[BUFF_SIZE];
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


char* Adapt_command(char* command, char* argv[]){
	int size = 0;
	char* command_split = strtok(command,"\n");
	char* file;
	char* ptr = strtok(command_split," ");
	while(ptr != NULL) //Calcul la taille du tableau des arguments
	{
		size+=1;
		ptr = strtok(NULL," ");
	}



	ptr = strtok(command_split," ");
	for(int i=0; i<size;i++){ //remplit argv
		argv[i]= ptr;
		ptr = strtok(NULL," ");
		printf("%s",argv[i]);
		printf("\n");
	}

	argv[size]= (char*) NULL;
	file = argv[0];


	return file;
}
