#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

    char sChaine[100];

    //printf("Bienvenue dans le shell ENSEA\n");
    write(1,"enseash % ",10);
    scanf("%s", sChaine);

    //strcmp compare la chaine s avec exit
    if(strcmp(sChaine, "exit") == 0){

        write(1,"Bye bye ",8);
        exit(0);
    }

    else{

        write(1,"erreur, réessayer\n",18);

    }
}
