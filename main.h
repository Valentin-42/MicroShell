/*
 * main.h
 *
 *  Created on: 6 déc. 2021
 *      Author: ensea
 */

#ifndef MAIN_H_
#define MAIN_H_

#endif /* MAIN_H_ */

//Constantes
#define BUFF_SIZE 100

//Includes
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//Prototypes
int main(void);



//Q1
void Init(void);
//Q2
int Execute(char*,ssize_t);
//Q6
char* Adapt_command(char*,char*[]);
//Q7
void Redirection_Ecriture(char* ptr);
//Q8
void Redirection_Lecture(char* ptr);
