#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define Size 100
#define fd 1

int main()
{
	char sChaine[Size];
    const char *buf = ("$ ./enseash\n Bienvenue dans le Shell ENSEA.\n Pour quitter, tapez 'exit'.\n enseash % \n");
    
    pid_t ret = fork();
    char *argv[] = {"fortune",NULL};// initialisation du processus fortune.
    write(fd,buf,strlen(buf)); // affiche le message *buf

	while(1){
        fgets(sChaine, sizeof(sChaine), stdin);	// la fonction va lire la variable stockée dans sChaine.
        sChaine[strcspn(sChaine, "\n")] = 0; //renvoie la fonction d'avant à 0.
        
        if(strcmp(sChaine, "exit") == 0){ // la boucle permet de faire une comparaison entre la variable sChaine et le mot "exit" et si le mot tapé est "exit", dans ce cas, le processus se finit.
            exit(0);
        }
		else {
            if(ret == 0){	// la boucle va permettre d'appeler la fonction fortune lorsque le mot tapé sera "faux" ou différent d'exit.
                execvp(argv[0], argv);
            }
        }
    }
    return 0;
}

