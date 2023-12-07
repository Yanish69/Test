# Test
Avant de commencer le Tp, plusieurs choses ont été nécessaires :

-installation de Clion

-Mettre a jour les différents paquets de la VM à l’aide de « update »

-Installer Firefox

-Configurer Git hub afin qu’il soit relié à notre IDE

1. Affichage d’un message d’accueil, suivi d’un prompt simple :

En ce qui concerne l’affichage du message d’accueil, on a du utiliser la fonction write() qui a servi a afficher des messages a l’écran.

2. Exécution de la commande saisie et retour au prompt (REPL : read–eval–print loop) :

Pour répondre à cette question, il a fallu d’abord passer par l’installation du programme fortune. Ensuite, le but était de pouvoir lancer fortune dans la console. L’utilisation de system() étant interdite, on a donc du passer par les processus (fork() - père/fils).

3. Gestion de la sortie du shell avec la commande “exit” ou un +d :

Il a suffit de reprendre le squelette de la question 1 et d’y rajouter des conditions dans le but de quitter le programme(  exit(0) ) ou non. En effet, on a cette fois ci fais appel aux fonctions write() et read(). L’une a permis l’affichage des messages a l’écran tandis que l’autre avait pour rôle de récupérer ce que l’utilisateur écrivait au clavier.

4. "Affichage du code de retour (ou du signal) de la commande précédente dans le prompt :

L’utilisation des processus est encore primordiale pour cette question. Par ailleurs, la mise en place d’un while() permet au programme de patienter jusqu’à que l’utilisateur rentre « exit ». En attendant, il lance tout ce que l’utilisateur lui dit.
