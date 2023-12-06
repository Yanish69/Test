#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {

	char sChaine[100];
    ssize_t bytesRead;
    write(1,"% ./enseash\n",14);
    write(1, "Bienvenue dans le shell ENSEA\n", 31),
    write(1,"Pour quitter, tapez 'exit : ",28);
    //scanf("%s", sChaine);

    ssize_t bytesRead = read(STDIN_FILENO, sChaine, sizeof(sChaine));

    //strcmp compares string s with exit
    if(strcmp(sChaine, "exit") == 0){

	exit(0);
	}

	else{

	write(1,"erreur, réessayer\n",18);

	}
}

